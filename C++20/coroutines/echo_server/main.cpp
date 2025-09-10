// Requires:
// apt install libboost-all-dev

// test with e.g.
// nc localhost 4000 + "hello" + ENTER

// based on: https://www.boost.org/doc/libs/1_86_0/doc/html/boost_asio/examples/cpp17_examples.html#boost_asio.examples.cpp17_examples.coroutines_ts_support
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/as_tuple.hpp>
#include <cstdio>

// this is a coroutine
boost::asio::awaitable<void> echo(boost::asio::ip::tcp::socket socket) {
  char data[1024];
  for (;;) {
    // 5. ->suspend, go back to io_context, wake me up when data arrives
    const auto&& [ec, n] = co_await socket.async_read_some(boost::asio::buffer(data),
                                                    boost::asio::as_tuple(boost::asio::use_awaitable));
    if (ec) {
      if (ec == boost::asio::error::eof)
        break;
      throw boost::system::system_error(ec);
    }

    // 6. ->suspend, go back to io_context, wake me up when write is done
    co_await async_write(socket, boost::asio::buffer(data, n), boost::asio::use_awaitable);
  }
}

// this is a coroutine
boost::asio::awaitable<void> listen() {
  // suspend
  auto executor = co_await boost::asio::this_coro::executor;
  boost::asio::ip::tcp::acceptor acceptor(executor, {boost::asio::ip::tcp::v4(), 4000});
  for (;;) {
    // 3. ->suspend, go back to io_context, wake me up when a client connects
    boost::asio::ip::tcp::socket socket = co_await acceptor.async_accept(boost::asio::use_awaitable);
    // 4. create a new coroutine for every connection
    boost::asio::co_spawn(executor, echo(std::move(socket)), boost::asio::detached);
  }
}

int main() {
  try {
    boost::asio::io_context io_context(1);
    // 1. Start corouteine that listens for incoming connections
    boost::asio::co_spawn(io_context, listen(), boost::asio::detached);

    // 2. start io_context event loop
    io_context.run();
  } catch (std::exception &e) {
    std::printf("Exception: %s\n", e.what());
  }
}
