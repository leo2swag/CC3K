#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

TextDisplay::TextDisplay(int row, int col):
                          floorRowSize{row},
                          floorColSize{col}{
  for(int r=0; r<floorRowSize; r++){
    vector<char> v = vector<char>(floorColSize,' ');
    theDisplay.push_back(v);
  }
}

void TextDisplay::Notify(Subject &whoNotified) {
  Info info = whoNotified.GetInfo();
  theDisplay[info.row][info.col]=info.c;
}

TextDisplay::~TextDisplay() {}

SubscriptionType TextDisplay::SubType() const {
  return SubscriptionType::Display;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  for(int r = 0; r < td.floorRowSize; r++ ){
    for(int c = 0; c < td.floorColSize; c++){//display a row
      out<<td.theDisplay[r][c];
    }
    out<<endl;//end of a row
  }
  return out;
}
