#ifndef _ALLPOTION_H_
#define _ALLPOTION_H_

#include "potion.h"

class lucky : public Potion{
	public:
		lucky(int s, int x, int y);
		int hp() override;
		int attack() override;
		int defense() override;
};

class pRH : public Potion{
	public:
		pRH(int s, int x, int y);
		int hp() override;
		int attack() override;
		int defense() override;
};

class pBA : public Potion{
	public:
		pBA(int s, int x, int y);
		int hp() override;
		int attack() override;
		int defense() override;
};

class pBD : public Potion{
	public:
		pBD(int s, int x, int y);
		int hp() override;
		int attack() override;
		int defense() override;
};

class nPH : public Potion{
	public:
		nPH(int s, int x, int y);
		int hp() override;
		int attack() override;
		int defense() override;
};

class nWA : public Potion{
	public:
		nWA(int s, int x, int y);
		int hp() override;
		int attack() override;
		int defense() override;
};

class nWD : public Potion{
	public:
		nWD(int s, int x, int y);
		int hp() override;
		int attack() override;
		int defense() override;
};

#endif
