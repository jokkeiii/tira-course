#include "stack.h"

using namespace std;

int main() {
  Stack numba_one, numba_two;
  int count = 10;
  double num;

  for (size_t i = 0; i < count; i++) {
    cout << numba_one.top(num) << endl;
    numba_one.push(i);
  }
  cout << "1 done!" << endl;
}