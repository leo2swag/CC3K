#include <iostream>
#include <fstream>
#include "stdlib.h"
#include <time.h>
#include "board.h"
#include "enemy.h"
#include "item.h"
#include "player.h"
#include "floor.h"
#include "stair.h"
#include "treasure.h"
#include "allenemy.h"
#include "allhoard.h"
#include "allpotion.h"
#include "character.h"
#include "allplayer.h"

bool Board::goodM = true;
Player *Board::players = nullptr;
Floor *Board::myFloor = nullptr;
stair *Board::stairs = nullptr;
vector<Enemy*> Board::enemies{};
vector<Potion*> Board::potions{};
vector<treasure*> Board::gold{};
vector<string> lines;
int lineNum = 0;
int Board::nFloor = 1;
int floorX = 0;
int floorY = 0;
char currace = ' ';
string action = " ";
string action2 = " ";
char c[8] = {'s', 'd', 'v', 't', 'g', 'h', 'a', 'z'};

Board::Board(){

}


void Board::Build(string name) {
  fileName = name;
  map = vector<string>(ROW_NUM);
  floors = vector<string>(FLOOR_NUM);
  potions = vector<Potion*>(POTION_NUM);
  gold = vector<treasure*>(GOLD_NUM);
  ReadText();
  createFloor();
  createBoard();
  createPlayer();
  createStair();
  printBoard();
}


void Board::createBoard() {
  ifstream input;
  input.open(fileName);

  input.close();

  string row;
  for (int i = 0; i < ROW_NUM; i++) {
    getline(input, row);
    map[i] = row;
  }
  createPotion();
  createEnemy();
  createGold();
}

void Board::createPlayer() {
  char race;
  if(currace == ' ') {
    race = this->selectPlayer();
  }
  else {
    race = currace;
  }
  int x;
  int y;
  while(true) {
  y = rand() % 79;
  x = rand() % 25;
  char sym;
  sym = myFloor->GetSymbol(x,y);
  if(sym == '.')
    break;
  }
  switch (race) {
    // Shade
    case 's':
      players = new shade(125, 25, 25, 1, '@', 0, x, y);
      break;
    // Drow
    case 'd':
      players = new drow(150, 25, 15, 2, '@', 0, x, y);
      break;
    // Vampire
    case 'v':
      players = new vampire(50, 25, 25, 3, '@', 0, x, y);
      break;
    // Troll
    case 't':
      players = new troll(120, 25, 15, 4, '@', 0, x, y);
      break;
    // Gobin
    case 'g':
      players = new goblin(110, 15, 20, 5, '@', 0, x, y);
      break;
    case 'h':
        players = new hedis(300, 30, 20, 6, '@', 0, x, y);
        break;
    case 'a':
        players = new aatrox(100, 50, 10, 7, '@', 0, x, y);
        break;
    case 'z':
        players = new god(1000, 200, 200, 8, '!', 0, x, y);
        break;
    default:
      cout << "please enter a valid race.";
      break;
  }
  myFloor->SetSymbol(x, y, players->GetSymbol());
  myFloor->Spread(x, y);
}

void Board::createStair() {
    int x;
    int y;
  while(true) {
  y = rand() % 79;
  x = rand() % 25;
  char sym;
  sym = myFloor->GetSymbol(x,y);
  bool b = myFloor->SameChamber(x, y);
  if(sym == '.' && !b)
    break;
  }
  stairs = new stair(20, x, y);
  myFloor->SetSymbol(x, y, stairs->GetSymbol());
  floorX = x;
  floorY = y;
}

void Board::ReadText(){
  ifstream myfile(fileName);
  string line;
  while(getline(myfile, line)){
    lines.push_back(line);
  }
  myfile.close();
}

void Board::createFloor() {
  string line;
  int tot_row = 25;
  int tot_col = 79;
  floors.clear();
  for(int i = lineNum; i< (lineNum+25);i++){
    floors.push_back(lines[i]);
  }
  lineNum += 25;
  myFloor = new Floor;
  myFloor->Init(tot_row, tot_col, floors);
}

void Board::createEnemy() {
  int dragonNum = 0;
  Enemy* e;
  int x;
  int y;
  for (int i = 0; i < ENEMY_NUM - 1; i++) {
    int random = rand() % 19;
    char race;
    while(true) {
    y = rand() % 79;
    x = rand() % 25;
    char sym;
    sym = myFloor->GetSymbol(x,y);
    if(sym == '.')
      break;
    }if(dragonNum == 0){//begin of dragon
      e = new dragon(150, 20, 20, 16, 'D', 4, x, y);
      this->enemies.push_back(e);
      Board::myFloor->SetSymbol(x,y,'D');
      int orgX = x;
      int orgY = y;
      int cases = rand() % 4;
      for(int i =0; i < 4; i++){
        if(cases == 0){
          if(Board::myFloor->GetSymbol(x+1,y)!='.'){
            cases +=1;
            continue;
          }
          x += 1;
          break;
        }else if(cases == 1){
          if(Board::myFloor->GetSymbol(x,y+1)!='.'){
            cases +=1;
            continue;
          }
          y += 1;
          break;
        }else if (cases == 2){
          if(Board::myFloor->GetSymbol(x-1,y)!='.'){
            cases +=1;
            continue;
          }
          x -= 1;
          break;
        }else{
          if(Board::myFloor->GetSymbol(x,y-1)!='.'){
            cases = 0;
            continue;
          }
          y -= 1;
          break;
        }
        }if(x != orgX || y != orgY){
          treasure *g = new dhoard(9, x, y);
          this->gold[0]=g;
          Board::myFloor->SetSymbol(x,y,'G');
        }
        dragonNum++;
        continue;
      }//end of dragon
    // Human
    if (random < 4)
      race = 'H';
    // Dwarf
    else if (random < 7)
      race = 'W';
    // Halfling
    else if (random < 12)
      race = 'L';
     // Elf
    else if (random < 14)
      race = 'E';
    // Orc
    else if (random < 16)
      race = 'O';
    // Merchant
    else if (random < 18)
      race = 'M';
    switch (race) {
      case 'H':
        e = new human(140, 20, 20, 11, 'H', 4, x, y);
        break;
      case 'W':
        e = new dwarf(100, 20, 30, 12, 'W', 0, x, y);
        break;
      case 'L':
        e = new halfling(100, 15, 20, 17, 'L', 0, x, y);
        break;
      case 'E':
        e = new elf(140, 30, 10, 13, 'E', 0, x, y);
        break;
      case 'O':
        e = new orc(180, 30, 25, 14, 'O', 0, x, y);
        break;
      case 'M':
        e = new merchant(30, 70, 5, 15, 'M', 2, x, y);
        break;
      default:
        e = new ghost(5, 1, 1, 18, 'T', 0, x, y);
    }
    this->enemies.push_back(e);
    myFloor->SetSymbol(x, y, e->GetSymbol());
  }
}

void Board::createGold() {
    treasure *t = nullptr;
    int x;
    int y;
  for (int i = 1; i < GOLD_NUM; i++) {
    int random = rand() % 2;
    int type;
    while(true) {
    y = rand() % 79;
    x = rand() % 25;
    char sym;
    sym =  myFloor->GetSymbol(x,y);
    if(sym == '.')
      break;
    }
    if (random == 0) {
      type = 6;
      t = new small(type, x, y);
      // Normal Gold
    }
    else if (random == 1){
      type = 7;
      // Small Gold
      t = new normal(type, x, y);
    }
    this->gold[i] = t;
    myFloor->SetSymbol(x, y, t->GetSymbol());
  }
}

void Board::createPotion() {
  int x;
  int y;
  for (int i = 0; i < POTION_NUM; i++) {
    int random = rand() % 7;
    int pot;
    while(true) {
    y = rand() % 79;
    x = rand() % 25;
    char sym;
    sym = myFloor->GetSymbol(x,y);
    if(sym != '.')
      break;
    else if (random == 0)
      pot = 0;
    else if (random == 1)
      pot = 1;
    else if (random == 2)
      pot = 2;
    else if (random == 3)
      pot = 3;
    else if (random == 4)
      pot = 4;
    else if (random == 5)
      pot = 5;
    else if (random == 6)
      pot = 10;
    Potion *p = nullptr;
    switch (pot) {
      case 0:
        p = new pRH(0, x, y);
        break;
      case 1:
        p = new pBA(1, x, y);
        break;
      case 2:
        p = new pBD(2, x, y);
        break;
      case 3:
        p = new nPH(3, x, y);
        break;
      case 4:
        p = new nWA(4, x, y);
        break;
      case 5:
        p = new nWD(5, x, y);
        break;
      case 10:
        p = new lucky(10, x, y);
        break;
      }
      this->potions.push_back(p);
      myFloor->SetSymbol(x, y, p->GetSymbol());
    }
  }
}

void Board::cleanBoard() {
  delete players; players = nullptr;
  delete myFloor; myFloor = nullptr;
  for (unsigned i = 0; i < potions.size(); i++) {
      delete potions[i];
  }
  potions.clear();
  for (unsigned i = 0; i < gold.size(); i++) {
    delete gold[i];
  }
  gold.clear();
  for (unsigned i = 0; i < enemies.size(); i++) {
    delete enemies[i];
  }
  enemies.clear();
}

void Board::move(bool mv, char con, string dir) {
  if(players->GetRace() == 4) {
    players->ResetHp(5);
  }
  else if(players->GetRace() == 6) {
    players->ResetHp(-3);
  }
  else if(players->GetRace() == 7) {
    players->ResetHp(-10);
  }
  if(con == 'g') { //general move command
    players->Move(dir);
    cout << action <<endl;
}

  else if(con == 'a') { //attack command
    string dir;
    cin >> dir;
//cout << "dir " << dir;
    players->Attack(dir);

  }
  else if(con == 'u') { //use command
    string dir;
    cin >> dir;
    Position pos = players->GetCoordinate();
    int tmpr = pos.x;
    int tmpc = pos.y;
    if (dir == "no") {
      tmpr -= 1;
    } else if (dir == "so") {
      tmpr += 1;
    } else if (dir == "ea") {
      tmpc += 1;
    } else if (dir == "we") {
      tmpc -= 1;
    } else if (dir == "ne") {
      tmpr -= 1;
      tmpc += 1;
    } else if (dir == "nw") {
      tmpr -= 1;
      tmpc -= 1;
    } else if (dir == "se") {
      tmpr += 1;
      tmpc += 1;
    } else if (dir == "sw") {
      tmpr += 1;
      tmpc -= 1;
    }
    for (unsigned i = 0; i < potions.size(); i++){
      if(potions[i]==nullptr)continue;
      int potx = potions[i]->GetCoordinate().x;
      int poty = potions[i]->GetCoordinate().y;
      if(potx == tmpr && poty==tmpc){
        players->AddPotion(potions[i]);
        Board::myFloor->RemoveSymbol(potx,poty);
        break;
      }
    }
  }

  if(players->GetHp() == 0) {
    status =1;
    return;
  }

  if((players->row == floorX) && (players->col == floorY)){
    if(nFloor == 5) {
      isWon();
      return;
    }
    else {
      selectFloor();
      return;
    }
  }
  if(mv == true) {
    //dragon attack gold thiefy
    Enemy *td = nullptr;
    for(unsigned int p = 0; p < Board::enemies.size();p++){
      if(Board::enemies[p] == nullptr){
        continue;
      }if(Board::enemies[p]->GetRace() == 16 ){
        td = Board::enemies[p];
      }
    }
    treasure *tr = nullptr;
    for(unsigned int p = 0; p < Board::gold.size();p++){
      if(Board::gold[p] == nullptr){
        continue;
      }if(Board::gold[p]->GetNum() == 9 ){
        tr = Board::gold[p];
      }
    }
    if(td != nullptr && tr != nullptr){
      if (abs(tr->GetCoordinate().x - players->row)<=1 &&
          abs(tr->GetCoordinate().y - players->col)<=1){
            players->AttackedBy(td);
          }
    }
    // end of dragon
    for (int i = 0; i < ENEMY_NUM-1; i++) {
      if (enemies[i] == nullptr || enemies[i]->GetRace() == 16) {
        continue;
      }
      Position enmPos = enemies[i]->GetCoordinate();
      int radiusRow = abs(enmPos.x-players->row);
      int radiusCol = abs(enmPos.y-players->col);
      if (goodM && enemies[i]->GetRace() == 15) {
        int random = rand() % 8;
        string enemyDir = "ea";
        for(int k = 0; k < 8; k++){
          if (random == 0){
            enemyDir="ea";
          }else if(random == 1){
            enemyDir = "ne";
          }else if(random == 2){
            enemyDir = "no";
          }else if(random == 3){
            enemyDir = "nw";
          }else if(random == 4){
            enemyDir = "we";
          }else if(random == 5){
            enemyDir = "sw";
          }else if(random == 6){
            enemyDir = "so";
          }else if(random == 7){
            enemyDir = "se";
          }
          if(enemies[i]->Move(enemyDir)){
            break;
          }else{
            random = (random+1)%7;
          }
        }
      } else {
            if(radiusRow<=1&&radiusCol<=1){
                players->AttackedBy(enemies[i]);
              }else{
                int random = rand() % 8;
                string enemyDir = "ea";
                for(int k = 0; k < 8; k++){
                  if (random == 0){
                    enemyDir="ea";
                  }else if(random == 1){
                    enemyDir = "ne";
                  }else if(random == 2){
                    enemyDir = "no";
                  }else if(random == 3){
                    enemyDir = "nw";
                }else if(random == 4){
                  enemyDir = "we";
                }else if(random == 5){
                  enemyDir = "sw";
                }else if(random == 6){
                  enemyDir = "so";
                }else if(random == 7){
                  enemyDir = "se";
                }
                if(enemies[i]->Move(enemyDir)){
                  break;
                }else{
                  random = (random+1)%7;
                }
              }
            }
        }
     }
   }
  printBoard();
}

char Board::selectPlayer() {
  char c;
  cout << "Please select a race: ";
  cin >> c;
  return c;
}

void Board::selectFloor() {
  nFloor += 1;
  int tempBlood = players->GetHp();
  int tempGold = players->gold;
  int a = players->GetRace();
  currace = c[a - 1];
  cleanBoard();
  Board *nBoard = new Board();
  nBoard->Build(fileName);
  players->AddGold(tempGold);
  players->ResetHp(tempBlood - (players->GetHp()));
}

void Board::UpMove(string dir, bool gold){
   if(dir == "ea"){
    action = "PC moves EAST.";
   }
   else if(dir == "we"){
    action = "PC moves WEST.";
   }
   else if(dir == "no"){
    action = "PC moves North.";
   }
   else if(dir == "so"){
    action = "PC moves SOUTH.";
   }
   else if(dir == "ne"){
    action = "PC moves NORTH EAST.";
   }
   else if(dir == "nw"){
    action = "PC moves NORTH WEST.";
   }
   else if(dir == "se"){
    action = "PC moves SOUTH EAST.";
   }
   else if(dir == "sw"){
    action = "PC moves SOUTH WEST.";
  }
  if (gold) {
    action += " PC picks up the gold.";

  }
}

void Board::UpAttackP(int PD, int TH,int Race){
  char r;
  if(Race == 11) {
    r = 'H';
  }
  else if(Race == 12){
    r = 'W';
  }
  else if(Race == 13){
    r = 'E';
  }
  else if(Race == 14){
    r = 'O';
  }
  else if(Race == 15){
    r = 'M';
  }
  else if(Race == 16){
    r = 'D';
  }
  else if(Race == 17){
    r = 'L';
  }
  else if(Race == 18){
    r = 'G';
  }
  action = " ";
  std::string s = std::to_string(PD);
  std::string s2 = std::to_string(TH);
  action += "PC deals ";
  action += s;
  action += " damage to ";
  action += r;
  action += " (";
  action += s2;
  action += " HP).";
}

void Board::UpAttackE(int ED, int Race){
  char r;
  if(Race == 11) {
    r = 'H';
  }
  else if(Race == 12){
    r = 'W';
  }
  else if(Race == 13){
    r = 'E';
  }
  else if(Race == 14){
    r = 'O';
  }
  else if(Race == 15){
    r = 'M';
  }
  else if(Race == 16){
    r = 'D';
  }
  else if(Race == 17){
    r = 'L';
  }
  else if(Race == 18){
    r = 'G';
  }
  action2 = " ";
  std::string s = std::to_string(ED);
  action2 += r;
  action2 += " deals ";
  action2 += s;
  action2 += " damage to PC.";
}

void Board::isWon() {

  cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
  cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
  cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
  cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
  cout << "Congradulations Dungeon Warrior!!!!!" << endl;
  cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
  cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
  cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
  cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t" << endl;

}



void Board::printBoard() {
  string race;
  int r = (Board::players)->GetRace();
  if(r == 1) {
    race = "Shade";
  }
  else if(r == 2) {
    race = "Drow";
  }
  else if(r == 3) {
    race = "Vampire";
  }
  else if(r == 4) {
    race = "Troll";
  }
  else if(r == 5) {
    race = "Goblin";
  }
  else if(r == 6) {
    race = "Hedis";
  }
  else if(r == 7) {
    race = "Aatrox";
  }
  else if(r == 8) {
    race = "God";
  }
  cout << *myFloor;
  cout << "Race: " << race << "  " << "Gold: " << (Board::players)->gold
  << "\t\t\t\t\t\t\t" << "Floor "<< nFloor << endl;
  cout << "HP: " << (Board::players)->GetHp() << endl;
  cout << "Atk: " << (Board::players)->GetAttack() << endl;
  cout << "Def: " << (Board::players)->GetDef() << endl;
  cout << "Action: " << action << action2 << endl;
  action = " ";
  action2 = " ";
}

Board::~Board() {
  currace = ' ';
  cleanBoard();
}
