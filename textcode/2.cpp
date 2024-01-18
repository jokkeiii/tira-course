/* Program extracts from Chapter 2 of
   "Data Structures and Program Design in C++"
   by Robert L. Kruse and Alexander J. Ryba
   Copyright (C) 1999 by Prentice-Hall, Inc.  All rights reserved.
   Extracts from this file may be used in the construction of other programs,
   but this code will not compile or execute as given here. */


// Section 2.1:

#include   <stack.h>

int main()
/*
Pre:   The user supplies an integer n and n decimal numbers.
Post:  The numbers are printed in reverse order.
Uses:  The STL class stack and its methods
*/

{
   int n;
   double item;
   stack<double> numbers;  //  declares and initializes a stack of numbers

   cout << " Type in an integer n followed by n decimal numbers." << endl
        << " The numbers will be printed in reverse order." << endl;
   cin  >> n;

   for (int i = 0; i < n; i++) {
      cin >> item;
      numbers.push(item);
   }

   cout << endl << endl;
   while (!numbers.empty()) {
      cout << numbers.top() << " ";
      numbers.pop();
   }
   cout << endl;
}


#include <stack>
stack<char> s;
char x, y, z;

s.push('a');
s.push('b');
s.push('c');
s.pop();
s.pop();
s.pop();

s.push('a');
s.push('b');
s.push('c');
x = s.top();
s.pop();
y = s.top();
s.pop();
s.push(x);
s.push(y);
s.pop();

s.push('a');
s.push('b');
s.push('c');
while (!s.empty())
   s.pop();

s.push('a');
s.push('b');
while (!s.empty()) {
   x = s.top();
   s.pop();
}
s.push('c');
s.pop();
s.push('a');
s.pop();
s.push('b');
s.pop();



// Section 2.2:

const int maxstack = 10;   //  small value for testing

class Stack {
public:
   Stack();
   bool empty() const;
   Error_code pop();
   Error_code top(Stack_entry &item) const;
   Error_code push(const Stack_entry &item);

private:
   int count;
   Stack_entry entry[maxstack];
};


Error_code Stack::push(const Stack_entry &item)
/*
Pre:  None.
Post: If the Stack is not full, item is added to the top
      of the Stack.  If the Stack is full,
      an Error_code of overflow is returned and the Stack is left unchanged.
*/

{
   Error_code outcome = success;
   if (count >= maxstack)
      outcome = overflow;
   else
      entry[count++] = item;
   return outcome;
}


Error_code Stack::pop()
/*
Pre:  None.
Post: If the Stack is not empty, the top of
      the Stack is removed.  If the Stack
      is empty, an Error_code of underflow is returned.
*/

{
   Error_code outcome = success;
   if (count == 0)
      outcome = underflow;
   else --count;
   return outcome;
}


Error_code Stack::top(Stack_entry &item) const
/*
Pre:  None.
Post: If the Stack is not empty, the top of
      the Stack is returned in item.  If the Stack
      is empty an Error_code of underflow is returned.
*/

{
   Error_code outcome = success;
   if (count == 0)
      outcome = underflow;
   else
      item = entry[count - 1];
   return outcome;
}


bool Stack::empty() const
/*
Pre:  None.
Post: If the Stack is empty, true is returned.
      Otherwise false is returned.
*/

{
   bool outcome = true;
   if (count > 0) outcome = false;
   return outcome;
}


Stack::Stack()
/*
Pre:  None.
Post: The stack is initialized to be empty.
*/
{
   count = 0;
}


class Extended_stack {
public:
   Extended_stack();
   Error_code pop();
   Error_code push(Stack_entry item);
   Error_code top(Stack_entry &item) const;
   bool empty() const;
   void clear(); //  Reset the stack to be empty.
   bool full() const ; //  If the stack is full, return true; else return false.
   int size() const;   //  Return the number of entries in the stack.

private:
   int count;
   Stack_entry entry[maxstack];
};



// Section 2.3:

typedef double Stack_entry;
#include ""

int main()
/*
Post: The program has executed simple arithmetic
      commands entered by the user.
Uses: The class Stack and the functions
      introduction, instructions, do_command, and get_command.
*/

{
   Stack stored_numbers;
   introduction();
   instructions();
   while (do_command(get_command(), stored_numbers));
}


char get_command()
{
   char command;
   bool waiting = true;
   cout << "Select command and press <Enter>:";

   while (waiting) {
      cin >> command;
      command = tolower(command);
      if (command == '?' || command == '=' || command == '+' ||
          command == '-' || command == '*' || command == '/' ||
          command == 'q' ) waiting = false;


      else {
         cout << "Please enter a valid command:"   << endl
              << "[?]push to stack   [=]print top" << endl
              << "[+] [-] [*] [/]   are arithmetic operations" << endl
              << "[Q]uit." << endl;
      }
   }
   return command;
}


bool do_command(char command, Stack &numbers)
/*
Pre:  The first parameter specifies a valid calculator command.
Post: The command specified by the first parameter
      has been applied to the Stack of numbers given by the second parameter.
      A result of true is returned unless command == 'q'.
Uses: The class Stack.
*/

{
   double p, q;
   switch (command) {
   case '?':
      cout << "Enter a real number: " << flush;
      cin >> p;
      if (numbers.push(p) == overflow)
         cout << "Warning: Stack full, lost number" << endl;
      break;

   case '=':
      if (numbers.top(p) == underflow)
         cout << "Stack empty" << endl;
      else
         cout << p << endl;
      break;

   case '+':
      if (numbers.top(p) == underflow)
         cout << "Stack empty" << endl;
      else {
         numbers.pop();
         if (numbers.top(q) == underflow) {
            cout << "Stack has just one entry" << endl;
            numbers.push(p);
         }

         else {
            numbers.pop();
            if (numbers.push(q + p) == overflow)
               cout << "Warning: Stack full, lost result" << endl;
         }
      }
      break;

   //   Add options for further user commands.

    case 'q':
      cout << "Calculation finished.\n";
      return false;
   }
   return true;
}



// Section 2.4:

int main()
/*
Post: The program has notified the user of any bracket
      mismatch in the standard input file.
Uses: The class Stack.
*/

{
   Stack openings;
   char symbol;
   bool is_matched = true;

   while (is_matched && (symbol = cin.get()) != '\n') {
      if (symbol == '{' || symbol == '(' || symbol == '[')
         openings.push(symbol);
      if (symbol == '}' || symbol == ')' || symbol == ']') {
         if (openings.empty()) {
            cout << "Unmatched closing bracket " << symbol
                 << " detected." << endl;
            is_matched = false;
         }

         else {
            char match;
            openings.top(match);
            openings.pop();
            is_matched = (symbol == '}' && match == '{')
                         || (symbol == ')' && match == '(')
                         || (symbol == ']' && match == '[');
            if (!is_matched)
               cout << "Bad match " << match << symbol << endl;
         }
      }
   }
   if (!openings.empty())
      cout << "Unmatched opening bracket(s) detected." << endl;
}


// Section 2.5:

   if (counter < max) {
      openings[counter] = symbol;
      counter++;
   }


if ((xxt == mxx) || (xxt > mxx))
    try_again();
else {
    xx[xxt] = wi;
    xxt++;
}

/*************************************************************************/

