// https://godbolt.org/z/TPrajoxxT

// https://github.com/NVIDIA/stdexec

#include <exec/static_thread_pool.hpp>
#include <iostream>
#include <stdexec/execution.hpp>


int main() {
  exec::static_thread_pool pool(8);  // pool with 8 threads
  auto sch = pool.get_scheduler();

  auto begin = stdexec::schedule(sch);      // create a sender
  auto hi = stdexec::then(begin, [] {       // sender adapter then
    std::cout << "Hello world! Have an int.\n";
    return 13;
  });
  auto add_42 = stdexec::then(hi, [](int arg) { return arg + 42; });

  auto [i] = stdexec::sync_wait(add_42).value();  // sender consumer, receiver

  std::cout << "i = " << i << '\n';
}
