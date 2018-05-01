#include "player.h"
#include "floor.h"
#include "board.h"
#include <iostream>
#include <math.h>
#include <stdexcept>
using namespace std;


Player::Player(int hp, int attack, int def, int race, char symbol, int gold, int row, int col):
																			Character{hp, attack, def, race, symbol, gold, row, col},
																			potions{std::vector<Potion *>()},
																			Psize{0} {}

void Player::AddPotion(Potion *pot){
	potions.emplace_back(pot);
	Psize++;
	UsePotion();
}

void Player::UsePotion(){
	Potion *tmp = potions[Psize - 1];
	potions.pop_back();
	Psize--;
	this->ResetHp(tmp->hp());
	this->ResetAtt(tmp->attack());
	this->ResetDef(tmp->defense());
}

void Player::AddGold(int money){
	this->gold += money;
}

bool Player::Move(string dir) {
	int tmpr = this->row;
	int tmpc = this->col;
	if (dir == "no") {
		tmpr -= 1;
	} else if (dir == "so") {
		tmpr += 1;
	} else if (dir == "ea") {
		tmpc += 1;
	} else if (dir == "we") {
		tmpc -= 1;
	} else if (dir == "ne") {
		tmpr -= 1;
		tmpc += 1;
	} else if (dir == "nw") {
		tmpr -= 1;
		tmpc -= 1;
	} else if (dir == "se") {
		tmpr += 1;
		tmpc += 1;
	} else if (dir == "sw") {
		tmpr += 1;
		tmpc -= 1;
	}
	try{
      char tmp = Board::myFloor->GetSymbol(tmpr, tmpc);
			if(tmp=='G'){
				for(unsigned int i = 0; i< Board::gold.size();i++){
					Position pos = Board::gold[i]->GetCoordinate();
					if(tmpr == pos.x && tmpc == pos.y){
						this->AddGold(Board::gold[i]->gold());
						Board::UpMove(dir, true);
						break;
					}
				}
		} else {
			Board::UpMove(dir, false);
		}
		if (tmp == '-' || tmp == '|'|| tmp == ' ') {
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

void Player::Attack(string dir) {
	int tmpr = this->row;
	int tmpc = this->col;
	if (dir == "no") {
		tmpr -= 1;
	} else if (dir == "so") {
		tmpr += 1;
	} else if (dir == "ea") {
		tmpc += 1;
	} else if (dir == "we") {
		tmpc -= 1;
	} else if (dir == "ne") {
		tmpr -= 1;
		tmpc += 1;
	} else if (dir == "nw") {
		tmpr -= 1;
		tmpc -= 1;
	} else if (dir == "se") {
		tmpr += 1;
		tmpc += 1;
	} else if (dir == "sw") {
		tmpr += 1;
		tmpc -= 1;
	} for (unsigned i = 0; i < Board::enemies.size(); i++) {

		int r = Board::enemies[i]->row;
		int c = Board::enemies[i]->col;
      if((r == tmpr) && (c == tmpc)) {
         Board::enemies[i]->AttackedBy(this);
          return;
      }
    }
		return;
}

void Player::AttackedBy(Character *hitter) {
	int Arace = hitter->GetRace();
	int Drace = this->GetRace();
	int dmg = ceil((100.0/(100.0 + (float)this->GetDef())) * (float)hitter->GetAttack());
	if ((rand() % 2) == 0) {
		dmg = 0;
	} else {
		if (Arace == 13 && Drace != 2) {
			dmg *= 2;
		} else if (Arace == 14 && Drace == 5) {
			dmg *= 1.5;
		}
		this->ResetHp(-1 * dmg);
	}
 Board::UpAttackE(dmg, hitter->GetRace());
 if (hitter->IsDead()) {
	 int r = hitter->GetCoordinate().x;
	 int c = hitter->GetCoordinate().y;
	 for (unsigned i = 0; i < Board::enemies.size(); i++) {
		 if (Board::enemies[i] == nullptr) {
			 continue;
		 }
		 int tmpr = Board::enemies[i]->GetCoordinate().x;
		 int tmpc = Board::enemies[i]->GetCoordinate().y;
		 if (r == tmpr && c == tmpc) {
			 delete Board::enemies[i];
			 Board::enemies[i] = nullptr;
		 }
	 }

 }
}
