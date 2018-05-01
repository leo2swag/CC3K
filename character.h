#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <string>
#include "position.h"


class Character {
		private:
				int hp;
				int curHp;
				int attack;
				int def;
				int race;

		/* protected:
				int gold;
                int row;
                int col; */
		public:
				Character(int hp, int attack, int def, int race, char symbol, int gold, int row, int col);
				int GetRace() const;
				int GetMax() const;
				int GetHp() const;
				int GetAttack() const;
				int GetDef() const;
				void ResetHp(int php);
				void ResetAtt(int patt);
				void ResetDef(int pdef);
				bool IsDead();
				char GetSymbol();
        int gold;
        int row;
        int col;
				char symbol;
				Position GetCoordinate();
        virtual void AddGold(int money) = 0;
				virtual bool Move(std::string dir) = 0;
				virtual void Attack(std::string dir) = 0;
				virtual void AttackedBy(Character *hitter) = 0;
				virtual ~Character();
};


#endif
