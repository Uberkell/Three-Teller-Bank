/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2023
 *
 *  Implementation file for a node that uses smart pointers.
 *
 *  Adapted from page 297 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 14 Mar 2023
 *
 *  @version 7.0 */

#include <memory>
#include <iostream>

template <typename ItemType>
Node<ItemType>::Node(const ItemType& anItem, std::shared_ptr<Node<ItemType>> nextNodePtr): item(anItem),next(nextNodePtr) {}

/**
#ifdef DTOR_TEST

#include <iostream>

template <typename ItemType>
Node<ItemType>::~Node() {

   std::cerr << "Node destructor called. on:"
             << "\n\titem: "
             << item
             << "\n\tnext: "
             << next
             << std::endl;
}

#endif **/

template <typename ItemType>
Node<ItemType>::~Node() {
/**
    std::cerr << "Node destructor called. on:"
              << "\n\titem: "
              << item
              << "\n\tnext: "
              << next
              << std::endl;
**/
}

template <typename ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {

    item = anItem;
}

template <typename ItemType>
void Node<ItemType>::setNext(const std::shared_ptr<Node<ItemType>>& nextNodePtr) {

next = nextNodePtr;
}

template <typename ItemType>
ItemType Node<ItemType>::getItem() const {

    return item;
}

template <typename ItemType>
auto Node<ItemType>::getNext() const {

    return next;
}