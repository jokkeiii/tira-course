// life.h
#pragma once

class Life {
public:
  Life(int rows, int cols); // Constructor to initialize grid size
  ~Life();                  // Destructor to free allocated memory
  void initialize();
  void print();
  void update();

private:
  int maxrow, maxcol;
  int **grid; // Pointer for a 2D dynamic array
  int neighbor_count(int row, int col);
};

void instructions(int maxrow, int maxcol);
