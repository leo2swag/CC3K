#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include <vector>
#include "character.h"
#include "potion.h"

class Player : public Character {
	private:
			std::vector<Potion *> potions;
			int Psize;
	public:
			Player(int hp, int attack, int def, int race, char symbol, int gold = 0, int row = 0, int col = 0);
    void AddPotion(Potion *pot);
			void UsePotion();
			void AddGold(int money) override;
			bool Move(std::string dir) override;
			void Attack(std::string dir) override;
			void AttackedBy(Character *hitter) override;

};

#endif
