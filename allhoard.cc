#include "allhoard.h"
using namespace std;


small::small(int s, int x, int y): treasure{s,x,y} {}

int small::gold() {
	return 1;
}

normal::normal(int s, int x, int y): treasure{s,x,y} {}

int normal::gold() {
	return 2;
}

mhoard::mhoard(int s, int x, int y): treasure{s,x,y} {}

int mhoard::gold() {
	return 4;
}

dhoard::dhoard(int s, int x, int y): treasure{s,x,y} {}

int dhoard::gold() {
	return 6;
}
