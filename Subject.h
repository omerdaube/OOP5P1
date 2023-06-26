//
// Created by omerd on 27/06/2023.
//

#ifndef OOP5P1_SUBJECT_H
#define OOP5P1_SUBJECT_H
#include <iostream>
#include <list>
#include "OOP5EventException.h"

using namespace std;
template <typename T>
class Subject{
private:
    list<Observer<T>*> observers;
public:
    Subject() = default;
    virtual ~Subject() = default;

    void notify(const T& t){
        for(auto it = observers.begin(); it != observers.end(); ++it){
            (*it)->handleEvent(t);
        }
    }
    void addObserver(Observer<T>& observer){
        for(auto it = observers.begin(); it != observers.end(); ++it){
            if(*it == &observer){
                throw ObserverAlreadyKnownToSubject();
            }
        }
        observers.push_back(&observer);
    }
    void removeObserver(Observer<T>& observer){
        for(auto it = observers.begin(); it != observers.end(); ++it){
            if(*it == &observer){
                observers.erase(it);
                return;
            }
        }
        throw ObserverUnknownToSubject();
    }
    Subject& operator+=(Observer<T>& observer){
        addObserver(observer);
        return *this;
    }
    Subject& operator-=(Observer<T>& observer){
        removeObserver(observer);
        return *this;
    }
    void operator()(const T& t){
        notify(t);
    }
};
#endif //OOP5P1_SUBJECT_H
