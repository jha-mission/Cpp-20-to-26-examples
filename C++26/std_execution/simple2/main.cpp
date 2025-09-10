// https://godbolt.org/z/TPrajoxxT

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
  // 1. execution ressource
  exec::static_thread_pool pool(8);
  auto sched = pool.get_scheduler();

  // 2. schedule senders on the execution ressource
  auto begin = stdexec::schedule(sched);

  // 3. when_all algorithm: wait for all senders to finish
  // all this just configures where, when, what should be executed
  stdexec::sender auto work = stdexec::when_all(
      stdexec::then(stdexec::schedule(sched), [] { return compute_intensive(2); }),
      stdexec::then(stdexec::schedule(sched), [] { return compute_intensive(3); }),
      stdexec::then(stdexec::schedule(sched), [] { return compute_intensive(4); }));

  // 4. execution actually starts here
  auto [a, b, c] = stdexec::sync_wait(std::move(work)).value();

  std::cout << "results: " << a << ", " << b << ", " << c << "\n";
  return 0;
}
