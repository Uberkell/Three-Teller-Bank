#ifndef PROJECT6_THREE_TELLER_PRIORITYQUEUE_H
#define PROJECT6_THREE_TELLER_PRIORITYQUEUE_H

#include <memory>

#include "PriorityQueueInterface.h"
#include "LinkedSortedList.h"

/** @class PriorityQueue PriorityQueue.h "PriorityQueue.h"
 *
 *  Specification of a sorted list-based ADT priority queue. */
template <typename ItemType>
class PriorityQueue : public PriorityQueueInterface<ItemType> {
private:
    std::unique_ptr<LinkedSortedList<ItemType>> sListPtr;

public:
    PriorityQueue();

    PriorityQueue(const PriorityQueue<ItemType>& pq);

    ~PriorityQueue() override = default;

    bool isEmpty() const override;

    bool enqueue(const ItemType& newEntry) override;

    bool dequeue() override;

    ItemType peekFront() const override;
};

#include "PriorityQueue.cpp"
#endif //PROJECT6_THREE_TELLER_PRIORITYQUEUE_H
