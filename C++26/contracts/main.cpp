// https://godbolt.org/z/e7chfvTTG

#include <contracts>

int fun(int i)
 pre(i >= 0)
 post(r : r > 0) {
  contract_assert(i >= 0);
  return i + 1;
}

int main() {
  int r = fun(-1);

  return 0;
}