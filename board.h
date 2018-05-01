#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "floor.h"
#include "potion.h"
#include "player.h"
#include "enemy.h"
#include "treasure.h"
#include "stair.h"

#define ROW_NUM 25
#define FLOOR_NUM 5
#define GOLD_NUM 10
#define ENEMY_NUM 20
#define POTION_NUM 10

using namespace std;

class Board {
  private:
    string fileName;
    int floorLvl;
    vector<string> map; // rows
    vector<string> floors; // floors


    void ReadText();
  public:
    static bool goodM;
    static int nFloor;
    int status = 0; //1 means the player is dead.
    static vector<Potion*> potions;
    static vector<treasure*> gold;
    static vector<Enemy*> enemies;
    static Floor* myFloor;
    static Player* players;
    static stair* stairs;

    /* Constructor */
    Board();
    void Build(string filename = "");

    /* Create functions */
    void createBoard();
    void createPlayer();
    void createEnemy();
    void createFloor();
    void createPotion();
    void createGold();
    void createStair();

    /* Functionality */
    static void UpMove(string dir,bool gold);
    static void UpAttackP(int PD, int TH, int Race);
    static void UpAttackE(int ED, int Race);
    void move(bool mv, char con, std::string dir);
    char selectPlayer();
    void selectFloor();
    void addPlayer();
    void cleanBoard();
    void isWon();

    /* Print function */
    void printBoard();

    /* Destructor */
    ~Board();

};

#endif
