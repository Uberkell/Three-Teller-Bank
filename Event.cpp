//
// Created by William on 4/8/2023.
//
#include "Event.h"
bool Event::operator<(const Event& rhs) const {

    return time < rhs.time;
}

bool Event::operator>(const Event& rhs) const {

    return time > rhs.time;
}

bool Event::operator<=(const Event& rhs) const {

    return time <= rhs.time;
}

bool Event::operator>=(const Event& rhs) const {

    return time >= rhs.time;
}

bool Event::operator==(const Event& rhs) const {

    return time == rhs.time;
}

bool Event::operator!=(const Event& rhs) const {

    return time != rhs.time;
}



bool Event::setNumber(int position){
    customerNumber = position;
    return true;
}
bool Event::setTime(int theTime){
    time = theTime;
    return true;
}
bool Event::setDuration(int theDuration){
    duration = theDuration;
    return true;
}
bool Event::setType(EventType theType){
    eventKind = theType;
    return true;
}

bool Event::setTeller(int num) {
    teller = num;
    return true;
}

int Event::getNumber() const{
    return customerNumber;
}
int Event::getTime() const{
    return time;
}
int Event::getDuration() const{
    return duration;
}
EventType Event::getType() const{
    return eventKind;
}
int Event::getLine() const {
    return teller;
}