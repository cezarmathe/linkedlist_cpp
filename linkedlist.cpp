#include "linkedlist.h"

// the LinkedListNode is initialized with null values for every field
template <typename T>
cezarmathe :: LinkedListNode<T> :: LinkedListNode() {
  previous = NULL;
  value = NULL;
  next = NULL;
}

// the LinkedList is initialized with no size
// and the first LinkedListNode is initialized with the specified type
template <typename T> 
cezarmathe :: LinkedList<T> :: LinkedList()
{
  this->size = 0;
}

// destructor
template <typename T> 
cezarmathe :: LinkedList<T> :: ~LinkedList()
{

}

// go through each node until reaching the end of the counter
// or there is no node ahead
// internal method, not failproof
template <typename T> 
cezarmathe :: LinkedListNode<T>& cezarmathe :: LinkedList<T> :: browse(int counter, LinkedListNode<T>* node) {

  if (node->next == NULL) {
    return node;
  }

  if (counter > 0) {
    return this->browse(counter-1, node->next);
  }

  return node;

}