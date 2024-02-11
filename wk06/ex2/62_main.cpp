// 62_main.cpp
/*
Exercise 1.
-----------
Implement and test queue data structure test program that is documented in the
lecture slides on pages 64 - 66 (page number can be found at the bottom of the
page).

To do this, you need a working queue data structure. Also complete the
missing parts of the test program (implementations of commands append, serve -
help functionality of your program lists all needed functions. You can create a
test program for the Extended_queue class (as has been done in the slides), but
this requires that you implement missing parts of Extended_queue class yourself.

Alternatively, you can do a test program for the Queue class, whose all public
methods can be found in the lecture slides. To save typing effort I recommend
that you Copy-Paste all useful source code from the file 3.cpp which has been
given in tabula (source codes in the slides/book, part 3).
*/
#include "../../utility/utility.h"
#include "extended_queue.h"
#include "queue.h"
#include <limits>
#include <unordered_set>

using namespace std;

bool do_command(char c, Extended_queue &test_queue);
void help();
char get_command();
char get_next_char();

int main()
/*
Post: Accepts commands from user as a menu-driven demonstration program for
      the class Extended_queue.
Uses: The class Extended_queue and the functions help,
      get_command, and do_command.
*/
{
  Extended_queue test_queue;
  help();
  while (do_command(get_command(), test_queue))
    ;
}

bool do_command(char c, Extended_queue &test_queue)
/*
Pre:  c represents a valid command.
Post: Performs the given command c on the Extended_queue test_queue.
      Returns false if c == 'q', otherwise returns true.
Uses: The class Extended_queue.
*/
{
  bool continue_input = true;
  Queue_entry x;

  switch (c) {
  case 'r':
    if (test_queue.retrieve(x) == underflow)
      cout << "Queue is empty." << endl;
    else
      cout << endl << "The first entry is: " << x << endl;
    break;
  case 's':
    if (test_queue.serve() == underflow)
      cout << "Queue is empty." << endl;
    else
      cout << endl << "The first entry is served." << endl;
    break;
  case 'a':
    if (test_queue.append(get_next_char()) == overflow)
      cout << "Queue is full." << endl;
    else
      cout << endl << "The entry is appended." << endl;
    break;
  case 'c':
    test_queue.clear();
    cout << endl << "Queue cleared." << endl;
    x = ' ';
    break;
  case 'h':
    // clear the input buffer up to and including the first newline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    help();
    break;
  case '#':
    cout << "Current queue size is: " << test_queue.size() << endl;
    break;
  case 'p':
    if (test_queue.print_queue() == underflow)
      cout << "Queue is empty." << endl;
    break;
  case 'q':
    cout << "Extended queue demonstration finished." << endl;
    continue_input = false;
    break;
  }
  return continue_input;
}

void help()
/*
Post: A help screen for the program is printed, giving the meaning of each
      command that the user may enter.
*/
{
  cout << endl
       << "This program allows the user to enter one command" << endl
       << "(but only one) on each input line." << endl
       << "For example, if the command S is entered, then" << endl
       << "the program will serve the front of the queue." << endl
       << endl

       << " The valid commands are:" << endl
       << "A - Append the next input character to the extended queue" << endl
       << "S - Serve the front of the extended queue" << endl
       << "R - Retrieve and print the front entry." << endl
       << "# - The current size of the extended queue" << endl
       << "C - Clear the extended queue (same as delete)" << endl
       << "P - Print the extended queue" << endl
       << "H - This help screen" << endl
       << "Q - Quit" << endl

       << "Press <Enter> to continue." << flush;

  char c;
  do {
    cin.get(c);
  } while (c != '\n');
}

char get_command() {
  // Define an unordered_set of allowed commands
  unordered_set<char> allowed_commands = {'h', 'a', 's', 'r',
                                          '#', 'c', 'p', 'q'};

  char command;
  bool waiting = true;
  cout << "Select command and press <Enter>: ";

  while (waiting) {
    cin >> command;
    command = tolower(command);

    // Check if the command is in the set of allowed commands
    if (allowed_commands.find(command) != allowed_commands.end())
      waiting = false;

    else {
      cout << "Please enter a valid command:" << endl
           << "A - Append the next input character to the extended queue"
           << endl
           << "S - Serve the front of the extended queue" << endl
           << "R - Retrieve and print the front entry." << endl
           << "# - The current size of the extended queue" << endl
           << "C - Clear the extended queue (same as delete)" << endl
           << "P - Print the extended queue" << endl
           << "H - Print help screen" << endl
           << "Q - Quit" << endl
           << "Select command and press <Enter>: ";
    }
  }
  return command;
}

char get_next_char() {
  cout << endl << "Give next character to append: " << flush;
  char c;
  cin >> c;
  return c;
}