#include "board.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;



string GetDir(){
  char c = getchar();
  if(c == 'w' || c == 'W'){
    return "no";
  }else if(c == 'a' || c == 'A'){
    return "we";
  }else if(c == 's' || c == 'S'){
    return "so";
  }else if(c == 'd' || c == 'K'){
    return "ea";
  }else{
    std::cerr << "default move is toward east" << '\n';
    std::cerr << "please enter direction correctly" << endl;
    return "ea";
  }
}

void gameStart() {
  cout << "Welcome to the advanture of CC3K." << endl;
  cout << "Presented by Haohan Li, Renjie Liu, Yahao Yan" << endl;
}

void comm() {
  cout << "To walk: no, so, ea, we, ne, nw, se, sw. (these are directions)" << endl;
  cout << "To attack enemies or use items: (a   direction), (u    dirction)" << endl;
  cout << "To quit: q.    To restart: r." << endl;
}

void lose() {
  cout << "try again, don't give up." << endl;
}

void quit() {
  cout << "Yar never win." << endl;
}

void again() {
  cout << "Please enter either r or q :" << endl;
}

int main(int argc, char *argv[]) {
  bool moveBool = true;  //enemies can move
  string fileName = "cc3kfloor.txt";
  if(argc == 1) {
    srand(time(NULL));
  }
  else {
    srand(time(NULL));
    fileName = argv[1];
  }
  gameStart();

  Board *myBoard = new Board();
  myBoard->Build(fileName);
//  myBoard->printBoard();
  string comm;
  while(true) {
    if((myBoard->players)->GetHp() <= 0){
      lose();
      again();
    }
    cin >> comm;
    if(cin.eof() || (comm == "q")){
      if(comm == "q") {
        quit();
      }
      break;
    }
    while(true) {
      if (comm == "r") {
        delete myBoard;
        Board *myBoard = new Board();
        myBoard->Build(fileName);
        Board::nFloor = 1;
        break;
      }
      else if(comm == "f") {
        moveBool = !moveBool;
        break;
      }
      else if(comm[0] == 'a' || comm[0] == 'u') {
        string c = comm;
        c.erase(0,2);
        myBoard->move(moveBool, comm[0], c);
        break;
      }
      else if (comm == "no" || comm == "nw" || comm == "ne"
              || comm == "so" || comm == "sw" || comm == "se"
              || comm == "ea" || comm == "we") { // switch case getchar
        myBoard->move(moveBool, 'g', comm);
        break;
      }
      else{
        cout << "enter a valid key:" << endl;
        break;
      }
    }
  }
  delete myBoard;
  return 0;
}
