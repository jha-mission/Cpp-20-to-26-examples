//you need to use linker flag -lstdc++exp for stacktrace
import std;

void my_fun() {
  std::println("{}", std::stacktrace::current());
}

int main() {
  my_fun();
  return 0;
}