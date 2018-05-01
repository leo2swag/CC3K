#include "subject.h"
#include "observer.h"
#include "subscriptions.h"

void Subject::Attach(Observer *o) {
  observers.push_back(o);
}

void Subject::NotifyObservers(SubscriptionType t) {
  for(unsigned int i = 0; i<observers.size(); i++){
    if(observers[i]->SubType()==t){
      observers[i]->Notify(*this);
    }
  }
}

Subject::~Subject() {}
