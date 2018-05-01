#include "treasure.h"
#include "board.h"
using namespace std;

treasure::treasure(int s, int x, int y): Item{s,x,y} {}

char treasure::GetSymbol() {
	if ((this->s > 5) || (this->s < 10)) {
		return 'G';
	}
    return '?';
}

int treasure::GetNum() {
	return s;
}

bool treasure::isTreasure() {
	return true;
}

bool treasure::canBePickedUp() {
	if (this->s == 6) {
        for (int i = 0; i < ENEMY_NUM; i++) {
	//	for (vector<Enemy*>::iterator i = enemies.begin(); i != enemies.end(); i++) {
	//		if (i->GetRace() == 16) {
            if (Board::enemies[i]->GetRace() == 16) {
				if (Board::enemies[i]->IsDead()) {
					return true;
				}

			}
		}
        return false;
	} else {
		return true;
	}
}


treasure::~treasure() {}
