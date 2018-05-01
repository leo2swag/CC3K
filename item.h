#ifndef _ITEM_H_
#define _ITEM_H_
#include <string>
class Position;

class Item {
		private:
				int x;
				int y;
		protected:
				int s;

		public:
				Item(int s, int x, int y);
				virtual char GetSymbol() = 0;
				virtual bool isTreasure() = 0;
				virtual bool canBePickedUp() = 0;
				Position GetCoordinate();
				~Item();
};


#endif
