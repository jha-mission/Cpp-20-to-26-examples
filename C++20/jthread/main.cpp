#include <iostream>
#include <thread>
#include <chrono>
#include <stop_token>

void worker(std::stop_token stoken) {
  int count = 0;
  std::cout << "Worker thread ID: " << std::this_thread::get_id() << "\n";

  while (!stoken.stop_requested()) {
    std::cout << "Working... " << ++count << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
  std::cout << "Worker stopped." << std::endl;
}

int main() {
  // this will lead to an exception when the thread is not joined
  // std::thread j{[]() {}};

  std::jthread jt(worker);

  std::cout << "Main thread ID: " << std::this_thread::get_id() << "\n";

  // Register a stop callback on the jthread.
  std::stop_callback callback(jt.get_stop_token(), [&jt]
  {
      std::cout << "Stop callback executed for thread: "
          << jt.get_id() << '\n';
  });

  std::this_thread::sleep_for(std::chrono::seconds(3));
  jt.request_stop(); // Ask the thread to stop

  // jt joins automatically on destruction
  return 0;
}