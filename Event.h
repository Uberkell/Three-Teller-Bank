//
// Created by William on 4/8/2023.
//

#ifndef PROJECT6_THREE_TELLER_EVENT_H
#define PROJECT6_THREE_TELLER_EVENT_H
#include <iostream>
#include "EventType.h"
#include "Time.h"

class Event {
private:
    Time time,duration;
    int customerNumber;
    EventType eventKind;
    int teller;
public:

    bool operator<(const Event& rhs) const;
    bool operator>(const Event& rhs) const;
    bool operator<=(const Event& rhs) const;
    bool operator>=(const Event& rhs) const;
    bool operator==(const Event& rhs) const;
    bool operator!=(const Event& rhs) const;

    bool setNumber(int positionNum);
    bool setTime(int theTime);
    bool setDuration(int theDuration);
    bool setType(EventType theType);
    bool setTeller(int num);

    int getNumber() const;
    int getTime() const;
    int getDuration() const;
    EventType getType() const;
    int getLine() const;

};


#endif //PROJECT6_THREE_TELLER_EVENT_H
