#include "item.h"
#include "position.h"
#include <iostream>

using namespace std;

Item::Item(int symbol, int x, int y): s{symbol}, x{x}, y{y} {}


Position Item::GetCoordinate() {
	Position tmp;
	tmp.x = x;
	tmp.y = y;
	return tmp;
}

Item::~Item() {}
