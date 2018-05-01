#include <iostream>
#include <stdexcept>
#include <string>
#include "floor.h"
#include "cell.h"
using namespace std;

Floor::Floor(): td{nullptr} {}

Floor::~Floor() {
  ClearFloor();
}

void Floor::ClearFloor() {
  theFloor.clear();
  delete td;
  td = nullptr;
}


void Floor::Init(int row, int col, vector<string> floorPlan) {
  ClearFloor();
  floorColSize = col;
  floorRowSize = row;
  for(int r=0; r<floorRowSize; r++){
    //initaliazed a row of cell
    vector<Cell> v = vector<Cell>((long unsigned)floorColSize, Cell());
    //push a row of cells into the grid
    theFloor.push_back(v);
  }
  td = new TextDisplay(floorRowSize,floorColSize);
  //add observers
  for(int r = 0; r<floorRowSize; r++){
    for(int c = 0; c< floorColSize; c++){
      theFloor[r][c].SetCoord(r,c);
      //attach observer block
      if((r+1)<floorRowSize){
        theFloor[r][c].Attach(&theFloor[r+1][c]);
      }
      if((r-1)>=0){
        theFloor[r][c].Attach(&theFloor[r-1][c]);
      }
      if((c+1)<floorColSize){
        theFloor[r][c].Attach(&theFloor[r][c+1]);
      }
      if((c-1)>=0){
        theFloor[r][c].Attach(&theFloor[r][c-1]);
      }
      //add observer text display
      theFloor[r][c].Attach(td);
      theFloor[r][c].InitSymbol(floorPlan[r][c]);
    }
  }
//end of adding observers
}

char Floor::GetSymbol(int row, int col){
  if(row<floorRowSize&&col<floorColSize){
    return theFloor[row][col].GetSymbol();
  }else{
    throw  out_of_range("blah");
  }
}

void Floor::MoveSymbolTo(int orgRow,int orgCol, int destRow, int destCol){
  char a = GetSymbol(orgRow, orgCol);
  theFloor[orgRow][orgCol].RemoveSymbol();
  theFloor[destRow][destCol].SetSymbol(a);
}

void Floor::RemoveSymbol(int row, int col){
  if(row<floorRowSize&&col<floorColSize){
    return theFloor[row][col].RemoveSymbol();
  }else{
    throw  out_of_range("blah");
  }
}

void Floor::Spread(int row,int col){
    theFloor[row][col].Spread();
}

void Floor::SetSymbol(int row, int col, char a){
  if(row<floorRowSize&&col<floorColSize){
    return theFloor[row][col].SetSymbol(a);
  }else{
    throw  out_of_range("blah");
  }
}

bool Floor::SameChamber(int row, int col){
  if(theFloor[row][col].status==1){
    return true;
  }
    return false;
}

ostream &operator<<(ostream &out, const Floor &g) {
  out<<(*g.td);
  return out;
}
