#include <iostream>
#include<string>
#include"Simulation.h"

Simulation::Simulation() {
    std::cout << "The Simulation has started!" << std::endl;
}


void Simulation::processArrival(){
    bool LineIsEmpty = true;
    int theLowest = -1;
    Event newEvent;
    if (currentEvent.getLine() == 1) {
        LineIsEmpty = line1.isEmpty();
        line1.enqueue(currentEvent);
        countOne++;
    }
    else if (currentEvent.getLine()==2) {
        LineIsEmpty = line2.isEmpty();
        line2.enqueue(currentEvent);
        countTwo++;
    }
    else if (currentEvent.getLine()) {
        LineIsEmpty = line3.isEmpty();
        line3.enqueue(currentEvent);
        countThree++;
    }

    eventList.dequeue();

    if (LineIsEmpty){
        //Time newTime = currentEvent.getTime() + currentEvent.getDuration();
        Event departEvent = eventBuilder.createDepartureEvent( currentEvent.getTime(),currentEvent.getDuration(),
                                                               currentEvent.getNumber(), currentEvent.getLine());
        eventList.enqueue(departEvent);
    }

    if ((countOne == countTwo) && (countOne == countThree)) {
        newEvent = eventBuilder.createArrivalEvent(currentEvent.getNumber() + 1, 1);
        if (newEvent.getType() != EventType::NONE) {
            eventList.enqueue(newEvent);
        }
    }

    if ((countOne < countTwo) && (countOne == countThree)) {
        newEvent = eventBuilder.createArrivalEvent(currentEvent.getNumber() + 1, 1);
        if (newEvent.getType() != EventType::NONE) {
            eventList.enqueue(newEvent);
        }
    }

    if ((countOne == countTwo) && (countOne < countThree)) {
        newEvent = eventBuilder.createArrivalEvent(currentEvent.getNumber() + 1, 1);
        if (newEvent.getType() != EventType::NONE) {
            eventList.enqueue(newEvent);
        }
    }

    else if ((countOne < countTwo) && (countOne < countThree)) {
        newEvent = eventBuilder.createArrivalEvent(currentEvent.getNumber() + 1, 1);
        if (newEvent.getType() != EventType::NONE) {
            eventList.enqueue(newEvent);
        }
    }

    else if ((countTwo < countOne) && (countTwo == countThree)) {
        newEvent = eventBuilder.createArrivalEvent(currentEvent.getNumber() + 1, 2);
        if (newEvent.getType() != EventType::NONE) {
            eventList.enqueue(newEvent);
        }
    }

    else if ((countTwo < countOne) && (countTwo < countThree)) {
        newEvent = eventBuilder.createArrivalEvent(currentEvent.getNumber() + 1, 2);
        if (newEvent.getType() != EventType::NONE) {
            eventList.enqueue(newEvent);
        }
    }

    else if ((countThree < countOne) && (countThree < countTwo)) {
        newEvent = eventBuilder.createArrivalEvent(currentEvent.getNumber() + 1, 3);
        if (newEvent.getType() != EventType::NONE) {
            eventList.enqueue(newEvent);
        }
    }

}
void Simulation::processDeparture(){

    int whichLine = currentEvent.getLine();

if (whichLine == 1) {
    line1.dequeue();
    countOne --;
    eventList.dequeue();
    if (!line1.isEmpty()) {
        Event frontEvent = line1.peekFront();
        Event newDepart = eventBuilder.createDepartureEvent(currentEvent.getTime(),
                                                            frontEvent.getDuration(), frontEvent.getNumber(), 1);
        eventList.enqueue(newDepart);

    }
}

if (whichLine == 2){
    line2.dequeue();
    countTwo--;
    eventList.dequeue();
    if (!line2.isEmpty()) {
        Event frontEvent = line2.peekFront();
        Event newDepart = eventBuilder.createDepartureEvent(currentEvent.getTime() ,
                                                            frontEvent.getDuration(),frontEvent.getNumber(),2);
        eventList.enqueue(newDepart);

    }

}

if (whichLine ==3) {
    line3.dequeue();
    countThree--;
    eventList.dequeue();
    if (!line3.isEmpty()) {
        Event frontEvent = line3.peekFront();
        Event newDepart = eventBuilder.createDepartureEvent(currentEvent.getTime() ,
                                                            frontEvent.getDuration(),frontEvent.getNumber(),3);
        eventList.enqueue(newDepart);

    }
}


}
/**
    line.dequeue();
    eventList.dequeue();
    if (!line.isEmpty()) {
        Event frontEvent = line.peekFront();
        Event newDepart = eventBuilder.createDepartureEvent(currentEvent.getTime() ,
                                                            frontEvent.getDuration(),frontEvent.getNumber());
        eventList.enqueue(newDepart);
    } **/

void Simulation::simulate() {

    eventList.enqueue(eventBuilder.createArrivalEvent(1,1));
    if ((eventList.peekFront()).getType() != EventType::NONE) {

        while (!eventList.isEmpty()) {
            currentEvent = eventList.peekFront();

            if (currentEvent.getType() == EventType::ARRIVAL) {
                //std::cout << "arrival member entered" << std::endl;
                processArrival();
            } else {
                //std::cout << "departing member" << std::endl;
                processDeparture();
            }
            stats.addEvent(currentEvent);
        }
    }
    stats.reportStats();
}