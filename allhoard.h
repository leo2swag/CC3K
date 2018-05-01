#ifndef _ALLHOARD_H_
#define _ALLHOARD_H_

#include "treasure.h"


class small : public treasure{
	public:
		small(int s, int x, int y);
		int gold() override;
};

class normal : public treasure{
	public:
		normal(int s, int x, int y);
		int gold() override;
};

class mhoard : public treasure{
	public:
		mhoard(int s, int x, int y);
		int gold() override;
};

class dhoard : public treasure{
	public:
		dhoard(int s, int x, int y);
		int gold() override;
};

#endif
