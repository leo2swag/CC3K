#ifndef _STAIR_H_
#define _STAIR_H_
#include "item.h"



class stair : public Item {
		public:
				stair(int s = 20, int x = 0, int y = 0);
				char GetSymbol() override;
                bool isTreasure() override;
				bool canBePickedUp() override;
				~stair();
};

#endif
