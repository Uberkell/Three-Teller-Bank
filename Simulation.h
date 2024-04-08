#ifndef SIMULATION_
#define SIMULATION_

#include "Event.h"
#include "EventBuilder.h"
#include "LinkedQueue.h"
#include "PriorityQueue.h"
#include "Statistics.h"

class Simulation {
private:
   Event currentEvent;
   EventBuilder eventBuilder;
   LinkedQueue<Event> line1;
   LinkedQueue<Event> line2;
   LinkedQueue<Event> line3;
   PriorityQueue<Event> eventList;
   Statistics stats;
   int countOne = 0, countTwo = 0, countThree = 0;

   void processArrival();
   void processDeparture();

public:
   Simulation();
   virtual ~Simulation() = default;

   void simulate();
};

#endif
