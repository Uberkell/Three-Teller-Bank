//
// Created by William on 4/9/2023.
//
#include <iostream>
#include <string>
#include "EventBuilder.h"
#include "Time.h"

EventBuilder::EventBuilder() {
    std::string fileName;
    std::cout << "Please enter the name of the file: ";
    std::cin >> fileName;
    inputFile.open(fileName);
    while (!inputFile) {
        std::cout << "ERROR: There is no file with that name, please enter another: " << std::endl;
        std::cin >> fileName;
        inputFile.open(fileName);
    }
}

Event EventBuilder::createArrivalEvent(int number, int line) {
    Event curEvent{};
    if (inputFile.peek() != EOF) {
        int theTime, theDur;
        inputFile >> theTime;
        inputFile >> theDur;
        //std::cout << "Time is: " << theTime <<std::endl;
        //std::cout << "Duration is: " << theDur <<std::endl;
        curEvent.setType(EventType::ARRIVAL);
        curEvent.setNumber(number);
        curEvent.setTime(theTime);
        curEvent.setDuration(theDur);
        curEvent.setTeller(line);
    }
    if (inputFile.peek() == EOF) {
        curEvent.setType(EventType::NONE);
    }
    return curEvent;
}
    Event EventBuilder::createDepartureEvent(const Time &currentEventTime, const Time &transactionLength, int number, int line) {
        Event curEvent{};

        curEvent.setType(EventType::DEPARTURE);
        curEvent.setNumber(number);
        curEvent.setTime(currentEventTime + transactionLength);
        curEvent.setDuration(transactionLength);
        curEvent.setTeller(line);
        return curEvent;
    }
