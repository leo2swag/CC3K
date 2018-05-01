#include "enemy.h"
#include "floor.h"
#include "board.h"
#include "stdlib.h"
#include "allhoard.h"
#include <math.h>
#include <iostream>
#include <stdexcept>
using namespace std;


Enemy::Enemy(int hp, int attack, int def, int race, char symbol, int gold, int row, int col): Character{hp, attack, def, race, symbol, gold, row, col} {}

void Enemy::AddGold(int money){
	return;
}

bool Enemy::Move(string dir) {
	int tmpr = this->row;
	int tmpc = this->col;
	if (dir == "no") {
		tmpr += 1;
	} else if (dir == "so") {
		tmpr -= 1;
	} else if (dir == "ea") {
		tmpc += 1;
	} else if (dir == "we") {
		tmpc -= 1;
	} else if (dir == "ne") {
		tmpr += 1;
		tmpc += 1;
	} else if (dir == "nw") {
		tmpr += 1;
		tmpc -= 1;
	} else if (dir == "se") {
		tmpr -= 1;
        tmpc += 1;
	} else if (dir == "sw") {
		tmpr -= 1;
		tmpc -= 1;
	}
	try{
        char tmp = Board::myFloor->GetSymbol(tmpr, tmpc);
		if (tmp != '.') {
			return false;
		}
	} catch (out_of_range) {
		return false;
	}
	Board::myFloor->MoveSymbolTo(this->row, this->col, tmpr, tmpc);
	this->row = tmpr;
	this->col = tmpc;
	return true;
}

void Enemy::Attack(string dir) {
	 Board::players->AttackedBy(this);
}

void Enemy::AttackedBy(Character *hitter) {
	int Arace = hitter->GetRace();
	int Drace = this->GetRace();
	int dmg = ceil((100.0/(100.0 + (float)this->GetDef())) * (float)hitter->GetAttack());
	if ((Drace == 17) && (Arace == 3)) {
		if ((rand() % 2) == 0) {
			dmg = 0;
		} else {
			if (Drace == 12) {
			hitter->ResetHp(-5);
			} else {
			hitter->ResetHp(5);
			}
		}
	} else if (Arace == 3) {
		if (Drace == 12) {
			hitter->ResetHp(-5);
		} else {
			hitter->ResetHp(5);
		}
	} else if (Drace == 17) {
		if ((rand() % 2) == 0) {
			dmg = 0;
		}
	} else if (Drace == 18) {
		if ((rand() % 8) != 0) {
			dmg = 0;
		}
	} else if (Arace == 7) {
		hitter->ResetHp(10);
	}

	this->ResetHp(-1 * dmg);
	Board::UpAttackP(dmg, this->GetHp(), this->GetRace());
	if (this->IsDead()) {
		if (Drace == 15 || Drace == 11) {
				Position po = GetCoordinate();
				int x = po.x;
				int y = po.y;
				int orgX = x;
				int orgY = y;
				if (Drace == 15) {
					Board::goodM = false;
					Board::myFloor->SetSymbol(x,y,'G');
					treasure *c = new mhoard(8, x, y);
					Board::gold.emplace_back(c);
				} else if (Drace == 11){
					Board::myFloor->SetSymbol(x,y,'G');
					treasure *c = new normal(7, x, y);
					Board::gold.emplace_back(c);
					int cases = random() % 4;
					for(int i =0; i < 4; i++){
						if(cases == 0){
							if(Board::myFloor->GetSymbol(x+1,y)!='.'){
								cases +=1;
								break;
							}
							x += 1;
							break;
						}else if(cases == 1){
							if(Board::myFloor->GetSymbol(x,y+1)!='.'){
								cases +=1;
								break;
							}
							y += 1;
							break;
						}else if (cases == 2){
							if(Board::myFloor->GetSymbol(x-1,y)!='.'){
								cases +=1;
								break;
							}
							x -= 1;
							break;
						}else{
							if(Board::myFloor->GetSymbol(x,y-1)!='.'){
								cases = 0;
								break;
							}
							y -= 1;
							break;
						}
						}if(x != orgX || y != orgY){
							Board::myFloor->SetSymbol(x,y,'G');
							treasure *b = new normal(7, x, y);
							Board::gold.emplace_back(b);
						}

				}
		} else {
			if (Arace == 5) {
				hitter->AddGold(5);
			}
			Board::myFloor->SetSymbol(row,col,'.');
		}
	}
}

Enemy::~Enemy(){}
