#include "life.h"
#include "utility.h"
#include <cstdlib> // for std::atoi
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int rows = 20; // Default number of rows
  int cols = 60; // Default number of columns

  // Check if the correct number of arguments is passed
  if (argc == 3) {
    rows = atoi(argv[1]); // Convert first argument to integer
    cols = atoi(argv[2]); // Convert second argument to integer
  } else if (argc != 1) {
    // If arguments are provided, but not the correct number
    cerr << "Usage: " << argv[0] << " [number of rows] [number of columns]"
         << endl;
    cerr << "Using default values: " << rows << " rows, " << cols << " columns"
         << endl;
  }

  // Additional check to ensure positive integer inputs
  if (rows <= 0 || cols <= 0) {
    cerr << "Rows and columns must be positive integers." << endl;
    return 1;
  }

  Life configuration(rows, cols);
  instructions(rows, cols);
  configuration.initialize();
  configuration.print();
  cout << "Continue viewing new generations? " << endl;
  while (user_says_yes()) {
    configuration.update();
    configuration.print();
    cout << "Continue viewing new generations? " << endl;
  }
  return 0; // Successful execution
}
