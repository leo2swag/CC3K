#include "character.h"
#include <iostream>
using namespace std;


Character::Character(int hp, int attack, int def, int race, char symbol, int gold, int row, int col): hp{hp}, curHp{hp}, attack{attack}, def{def}, race{race}, symbol{symbol}, gold{gold}, row{row}, col{col} {}

Character::~Character() {}

int Character::GetRace() const {
	return race;
}

int Character::GetMax() const {
	return hp;
}

int Character::GetHp() const {
	return curHp;
}

int Character::GetAttack() const {
	return attack;
}

int Character::GetDef() const {
	return def;
}

void Character::ResetHp(int php) {
	curHp += php;
	if (race != 3) {
		if (curHp >= hp) {
			curHp = hp;
		}
	}
	if (curHp <= 0) {
		curHp = 0;
	}
}


void Character::ResetAtt(int patt) {
	attack += patt;
}

void Character::ResetDef(int pdef) {
	def += pdef;
}

bool Character::IsDead() {
	if (curHp <= 0) {
		return true;
	} else {
		return false;
	}
}

char Character::GetSymbol() {
	return symbol;
}

void Character::AddGold(int money) {
    gold += money;
}



Position Character::GetCoordinate(){
	Position tmp;
	tmp.x = row;
	tmp.y = col;
	return tmp;
}

