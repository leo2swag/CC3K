#ifndef _TREASURE_H_
#define _TREASURE_H_
#include "item.h"
#include <string>


class treasure : public Item {
		public:
				treasure(int s, int x, int y);
				int GetNum();
				char GetSymbol() override;
				bool isTreasure() override;
				bool canBePickedUp() override;
				virtual int gold() = 0;
				virtual ~treasure();
};

#endif
