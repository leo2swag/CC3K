#include "allpotion.h"
#include "stdlib.h"
using namespace std;

lucky::lucky(int s, int x, int y): Potion{s,x,y} {}

int lucky::hp() {
	if ((rand() % 2) == 0) {
		return 40;
	} else {
		return -20;
	}
}

int lucky::attack() {
	if ((rand() % 2) == 0) {
		return 5;
	} else {
		return -2;
	}
}

int lucky::defense() {
	if ((rand() % 2) == 0) {
		return 5;
	} else {
		return -2;
	}
}

pRH::pRH(int s, int x, int y): Potion{s,x,y} {}

int pRH::hp() {
	return 10;
}

int pRH::attack() {
	return 0;
}

int pRH::defense() {
	return 0;
}

pBA::pBA(int s, int x, int y): Potion{s,x,y} {}

int pBA::hp() {
	return 0;
}

int pBA::attack() {
	return 5;
}

int pBA::defense() {
	return 0;
}

pBD::pBD(int s, int x, int y): Potion{s,x,y} {}

int pBD::hp() {
	return 0;
}

int pBD::attack() {
	return 0;
}

int pBD::defense() {
	return 5;
}

nPH::nPH(int s, int x, int y): Potion{s,x,y} {}

int nPH::hp() {
	return -10;
}

int nPH::attack() {
	return 0;
}

int nPH::defense() {
	return 0;
}

nWA::nWA(int s, int x, int y): Potion{s,x,y} {}

int nWA::hp() {
	return 0;
}

int nWA::attack() {
	return -5;
}

int nWA::defense() {
	return 0;
}

nWD::nWD(int s, int x, int y): Potion{s,x,y} {}

int nWD::hp() {
	return 0;
}

int nWD::attack() {
	return 0;
}

int nWD::defense() {
	return -5;
}
