#include "potion.h"
using namespace std;

Potion::Potion(int s, int x, int y): Item{s,x,y} {}

char Potion::GetSymbol() {
	if ((this->s <= 5) || (this->s == 10)) {
		return 'P';
	}
    return '?';
}

bool Potion::isTreasure() {
	return false;
}

bool Potion::canBePickedUp() {
    return true;
}

Potion::~Potion() {}
