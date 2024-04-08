#ifndef PROJECT6_SINGLE_TELLER_PrioQUEUEINTERFACE_H
#define PROJECT6_SINGLE_TELLER_PrioQUEUEINTERFACE_H
/** @class PriorityQueInterface PriorityQueInterface.h "PriorityQueInterface.h"
 *
 *  Definition of PriorityQueInterface class template. */
template <typename ItemType>
class PriorityQueueInterface {
public:
    /** Virtual destructor. */
    virtual ~PriorityQueueInterface() = default;

    /** Sees whether this list is empty.
     *
     *  @return True if this list is empty, or false if not. */
    virtual bool isEmpty() const = 0;

    /** Adds an item to the queue and returns a bool value
    *
    *  @pre None.
    *
    *  @post None.
    *
    *  @param newEntry The desired item to add to the queue.
    *
    *  @return A true or false value depending on if it was successful in adding.
    */
    virtual bool enqueue(const ItemType& newEntry) = 0;

/** Adds an item to the queue and returns a bool value
    *
    *  @pre None.
    *
    *  @post None.
    *
    *  @param None.
    *
    *  @return A true or false value depending on if it was successful in removal.
    */
    virtual bool dequeue() = 0;

    /** returns item on the front of the list
    *
    *  @pre List most not be empty.
    *
    *  @post None.
    *
    *  @param None.
    *
    *  @return the item that is at the front of the list.
    */
    virtual ItemType peekFront() const = 0;
};
#endif //PROJECT6_SINGLE_TELLER_QUEUEINTERFACE_H
