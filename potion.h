#ifndef _POTION_H_
#define _POTION_H_
#include "item.h"
#include <string>


class Potion : public Item {
		public:
				Potion(int s, int x, int y);
				char GetSymbol() override;
				bool isTreasure() override;
				bool canBePickedUp() override;
				virtual int hp() = 0;
				virtual int attack() = 0;
				virtual int defense() = 0;
				virtual ~Potion();
};

#endif
