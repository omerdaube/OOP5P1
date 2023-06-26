//
// Created by omerd on 27/06/2023.
//

#ifndef OOP5P1_OBSERVER_H
#define OOP5P1_OBSERVER_H
template <typename T>
class Observer{
public:
    Observer() = default;
    virtual ~Observer() = default;
    virtual void handleEvent(const T& t) = 0;
};
#endif //OOP5P1_OBSERVER_H
