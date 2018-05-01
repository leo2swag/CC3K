#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include "subscriptions.h"
class Info;
class Observer;

class Subject {
  std::vector<Observer*> observers;
 public:
  void Attach(Observer *o);
  void NotifyObservers(SubscriptionType t);
  virtual Info GetInfo() const = 0;
  virtual ~Subject() = 0;
};

#endif
