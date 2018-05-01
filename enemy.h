#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "character.h"
#include <string>

class Enemy : public Character {
	public:
			Enemy(int hp, int attack, int def, int race, char symbol, int gold, int row, int col);
            void AddGold(int money) override;
			bool Move(std::string dir) override;
			void Attack(std::string dir) override;
			void AttackedBy(Character *hitter) override;
			virtual ~Enemy();

};











#endif
