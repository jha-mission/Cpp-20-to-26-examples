#include <exec/static_thread_pool.hpp>
#include <iostream>
#include <stdexec/execution.hpp>
#include <thread>

int compute_intensive(int n) {
  // simple placeholder work
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  return n * n;
}

int main() {
  exec::static_thread_pool pool(8);
  auto sched = pool.get_scheduler();

  auto begin = stdexec::schedule(sched);

  stdexec::sender auto work = stdexec::when_all(
      stdexec::then(stdexec::schedule(sched), [] { return compute_intensive(0); }),
      stdexec::then(stdexec::schedule(sched), [] { return compute_intensive(1); }),
      stdexec::then(stdexec::schedule(sched), [] { return compute_intensive(2); }));

  auto [a, b, c] = stdexec::sync_wait(std::move(work)).value();

  std::cout << "results: " << a << ", " << b << ", " << c << "\n";
  return 0;
}
