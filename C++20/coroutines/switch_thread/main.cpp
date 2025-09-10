// https://cppreference.com/w/cpp/language/coroutines.html

#include <coroutine>
#include <iostream>
#include <stdexcept>
#include <thread>

auto switch_to_new_thread(std::thread& out) {
  struct awaitable {
    std::thread* p_out;

    bool await_ready() { return false; }                                    // not ready yet -> always suspend

    void await_suspend(std::coroutine_handle<> h) {                         // called when coroutine supends
      std::thread& out = *p_out;
      if (out.joinable())
        throw std::runtime_error("Output thread parameter not empty");

      out = std::thread([h] { h.resume(); });                              // coroutine handle h.resume() called in new thread

      // Potential undefined behavior: accessing potentially destroyed *this
      // std::cout << "New thread ID: " << p_out->get_id() << '\n';
      std::cout << "New thread ID: " << out.get_id() << '\n';  // this is OK
    }
    void await_resume() {}
  };
  return awaitable{&out};   // initialize awaitable with &out
}

struct Task {
  struct promise_type {
    Task get_return_object() { return {}; }
    std::suspend_never initial_suspend() { return {}; }
    std::suspend_never final_suspend() noexcept { return {}; }
    void return_void() {}
    void unhandled_exception() {}
  };
};

Task resuming_on_new_thread(std::thread& out) {
  std::cout << "Coroutine started on thread: " << std::this_thread::get_id()
            << '\n';
  co_await switch_to_new_thread(out);
  // awaiter destroyed here
  std::cout << "Coroutine resumed on thread: " << std::this_thread::get_id()
            << '\n';
}

int main() {
  std::thread out;
  resuming_on_new_thread(out);
  std::cout << "Main thread ID: " << std::this_thread::get_id() << '\n';
  out.join();
}
