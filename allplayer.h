#ifndef _ALLPLAYER_H_
#define _ALLPLAYER_H_

#include "player.h"

class shade : public Player {
public:
	shade(int hp = 125, int attack = 25, int def = 25, int race = 1, char symbol = '@', int gold = 0, int row = 0, int col = 0);
};

class drow : public Player {
public:
	drow(int hp = 150, int attack = 25, int def = 15, int race = 2, char symbol = '@', int gold = 0, int row = 0, int col = 0);
};

class vampire : public Player {
public:
	vampire(int hp = 50, int attack = 25, int def = 25, int race = 3, char symbol = '@', int gold = 0, int row = 0, int col = 0);
};

class troll : public Player {
public:
    troll(int hp = 120, int attack = 25, int def = 15, int race = 4, char symbol = '@', int gold = 0, int row = 0, int col = 0);
};

class goblin : public Player {
public:
	goblin(int hp = 110, int attack = 15, int def = 20, int race = 5, char symbol = '@', int gold = 0, int row = 0, int col = 0);
};

class hedis : public Player {
public:
	hedis(int hp = 300, int attack = 30, int def = 20, int race = 6, char symbol = '@', int gold = 0, int row = 0, int col = 0);
};

class aatrox : public Player {
public:
	aatrox(int hp = 100, int attack = 50, int def = 10, int race = 7, char symbol = '@', int gold = 0, int row = 0, int col = 0);
};

class god : public Player {
public:
    god(int hp = 1000, int attack = 200, int def = 200, int race = 8, char symbol = '!', int gold = 0, int row = 0, int col = 0);
};
#endif
