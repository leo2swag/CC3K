
#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <iostream>
#include <vector>
#include <string>
#include "cell.h"
#include "textdisplay.h"
using namespace std;

class Floor {
  vector<vector<Cell>> theFloor;  // The actual Floor.
  int floorColSize;    //Col number.
  int floorRowSize;   //Row number
  TextDisplay *td; // The text display.
  // Add private members, if necessary.

  void ClearFloor();   // Frees the grid.

 public:
  Floor();
  ~Floor();

  char GetSymbol(int row, int col);//Get symbol of specific cell
  void RemoveSymbol(int row,int col); //Remove Symbol of specific cell
                                     //i.e. Monster die at row 3 col 4
  void SetSymbol(int row, int col, char a);  // Set Symbol at specific cell
  void MoveSymbolTo(int orgRow,int orgCol, int destRow, int destCol);
  void Spread(int row,int col);//to identify every cell in the same chamber
  bool SameChamber(int row, int col);
  void Init(int row, int col,vector<string> floorPlan); // Sets up an n x n grid.  Clears old grid, if necessary.
  friend std::ostream &operator<<(std::ostream &out, const Floor &g);
};

#endif
