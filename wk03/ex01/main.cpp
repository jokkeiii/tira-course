#include <iostream>
#include <stack>

using namespace std;

int main()
/*
Pre:   The user supplies an integer n and n characters.
Post:  The chars are printed in reverse order.
Uses:  The STL class stack and its methods
*/
{
  int n;
  char item;
  stack<char> chars; //  declares and initializes a stack of characters

  cout << " Type in an integer n followed by n characters." << endl
       << " The characters will be printed in reverse order." << endl;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> item;
    chars.push(item);
  }

  cout << endl << endl;
  while (!chars.empty()) {
    cout << chars.top();
    chars.pop();
  }
  cout << endl;
}
