#include "cell.h"
#include "subject.h"
#include "observer.h"
#include "info.h"

Cell::Cell(){
  this->status = 0;
}

Cell::~Cell(){}

void Cell::InitSymbol(char a){
  if(a=='|'||a=='-'||a=='+'||a=='.'||a=='#'||a==' '){
    this->orgSymbol = a;
    this->curSymbol = a;
  }else{
    this->orgSymbol='.';
    this->curSymbol=a;
  }
  NotifyDisplay(*this);
}

void Cell::SetCoord(int r, int c){
  this->r=r;
  this->c=c;
}

void Cell::NotifyDisplay(Subject &whoNotified){
  NotifyObservers(SubscriptionType::Display);
}

void Cell::Spread(){
  Notify(*this);
}

void Cell::Notify(Subject &whoNotified){
  if(orgSymbol=='.'){
    if(status!=1){
      status = 1;
      NotifyObservers(SubscriptionType::Cell);
    }
  }
}

void Cell::RemoveSymbol(){
  curSymbol=orgSymbol;
  NotifyDisplay(*this);
}

void Cell::SetSymbol(char a){
  curSymbol=a;
  NotifyDisplay(*this);
}

SubscriptionType Cell::SubType() const {
  return SubscriptionType::Cell;
}

char Cell::GetSymbol()const {
  return curSymbol;
}

Info Cell::GetInfo() const {
  return Info{r,c,curSymbol};
}
