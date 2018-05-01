#ifndef __CELL_H__
#define __CELL_H__
#include "subject.h"
#include "observer.h"
class Info;

class Cell : public Subject, public Observer {
    int r, c;
    char orgSymbol;
    char curSymbol;
  public:
    Cell();
    ~Cell();
    int status;
    char GetSymbol() const;
    void RemoveSymbol();
    void SetSymbol(char a);
    void InitSymbol(char a);
    void SetCoord(int r, int c);
    void NotifyDisplay(Subject &whoNotified);
    void Spread();//spread the stauts which stands for
                  //if it is same chamber as player
    void Notify(Subject &whoNotified) override;
    SubscriptionType SubType() const override;
    Info GetInfo() const override;
};
#endif
