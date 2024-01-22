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
  stack<char> char_stack,
      reverse_stack; //  declares and initializes a stack of characters

  cout << " Type in an integer n followed by n characters." << endl
       << " The characters will be printed in reverse order." << endl;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> item;
    char_stack.push(item);
  }
  cout << endl << endl;

  stack<char> temp_stack = char_stack;

  while (!temp_stack.empty()) {
    reverse_stack.push(temp_stack.top());
    cout << temp_stack.top();
    temp_stack.pop();
  }

  cout << endl;

  bool is_palindrome = true;
  while (!char_stack.empty() && !reverse_stack.empty()) {
    if (char_stack.top() != reverse_stack.top()) {
      is_palindrome = false;
    }
    char_stack.pop();
    reverse_stack.pop();
  }

  if (is_palindrome) {
    cout << "Given characters are a palindrome" << endl;
  }
}
