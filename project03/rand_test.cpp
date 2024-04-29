#include "Random.h"
#include <climits>
#include <iostream>

int main() {
  // Create a Random object with pseudo-random based on time
  Random randGenerator(false);

  // Generate a random integer between 1 and 10
  int randomNum = randGenerator.random_integer(1, 10);
  std::cout << "Random number between 1 and 10: " << randomNum << std::endl;

  // Generate a random integer between 20 and 30
  randomNum = randGenerator.random_integer(20, 30);
  std::cout << "Random number between 20 and 30: " << randomNum << std::endl;

  // Generate a random integer between 100 and 200
  randomNum = randGenerator.random_integer(100, 200);
  std::cout << "Random number between 100 and 200: " << randomNum << std::endl;

  randomNum = randGenerator.random_integer(1, 200000);
  std::cout << "Random number between 1 and 200000: " << randomNum << std::endl;

  return 0;
}
