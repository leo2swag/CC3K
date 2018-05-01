#include "stair.h"
using namespace std;

stair::stair(int s, int x, int y): Item{s,x,y} {}

char stair::GetSymbol() {
	if (this->s == 20) {
		return '/';
	}
    return '?';
}

bool stair::isTreasure() {
	return false;
}

bool stair::canBePickedUp(){
	return false;
}
stair::~stair() {}
