#ifndef _ALLENEMY_H_
#define _ALLENEMY_H_

#include "enemy.h"

class human : public Enemy{
public:
	human(int hp = 140, int attack = 20, int def = 20, int race = 11, char symbol = 'H', int gold = 0, int row = 0, int col = 0);
};

class dwarf : public Enemy{
public:
	dwarf(int hp = 100, int attack = 20, int def = 30, int race = 12, char symbol = 'W', int gold = 0, int row = 0, int col = 0);
};

class elf : public Enemy{
public:
	elf(int hp = 140, int attack = 30, int def = 10, int race = 13, char symbol = 'E', int gold = 0, int row = 0, int col = 0);
};

class orc : public Enemy{
public:
	orc(int hp = 180, int attack = 30, int def = 25, int race = 14, char symbol = 'O', int gold = 0, int row = 0, int col = 0);
};

class merchant : public Enemy{
public:
	merchant(int hp = 30, int attack = 70, int def = 5, int race = 15, char symbol = 'M', int gold = 0, int row = 0, int col = 0);
};

class dragon : public Enemy{
public:
	dragon(int hp = 150, int attack = 20, int def = 20, int race = 16, char symbol = 'D', int gold = 0, int row = 0, int col = 0);
};

class halfling : public Enemy{
public:
	halfling(int hp = 100, int attack = 15, int def = 20, int race = 17, char symbol = 'L', int gold = 0, int row = 0, int col = 0);
};

class ghost : public Enemy{
public:
	ghost(int hp = 5, int attack = 1, int def = 1, int race = 18, char symbol = 'G', int gold = 0, int row = 0, int col = 0);
};

#endif
