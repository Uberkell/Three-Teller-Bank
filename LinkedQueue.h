/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2023
 *
 *  Header file for a pointer-based implementation of the ADT queue.
 *
 *  Adapted from page 421 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 14 Mar 2023
 *
 *  @version 7.0 */


#ifndef PROJECT6_THREE_TELLER_LINKEDQUEUE_H
#define PROJECT6_THREE_TELLER_LINKEDQUEUE_H
#include <memory>

#include "QueueInterface.h"
#include "Node.h"

/** @class LinkedQueue LinkedQueue.h "LinkedQueue.h"
 *
 *  Specification of a pointer-based ADT queue. */
template <typename ItemType>
class LinkedQueue : public QueueInterface<ItemType> {
private:
    using NodePtr = std::shared_ptr<Node<ItemType>>;

    NodePtr backPtr;
    NodePtr frontPtr;

public:
    LinkedQueue() = default;

    LinkedQueue(const LinkedQueue<ItemType>& aQueue);

    ~LinkedQueue() override = default;

    bool isEmpty() const override;

    bool enqueue(const ItemType& newEntry) override;

    bool dequeue() override;

    ItemType peekFront() const override;
};

#include "LinkedQueue.cpp"
#endif //PROJECT6_THREE_TELLER_LINKEDQUEUE_H
