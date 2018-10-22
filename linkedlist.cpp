#include "linkedlist.h"

#ifndef LINKEDLIST_C
#define LINKEDLIST_C

// the LinkedListNode is initialized with null values for every field
template <typename T>
cezarmathe :: LinkedListNode<T> :: LinkedListNode(T val) {
  previous = NULL;
  value = val;
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
cezarmathe :: LinkedListNode<T>* cezarmathe :: LinkedList<T> :: browse(int counter, LinkedListNode<T>* node) {

  if (node->next == NULL) {
    return node;
  }

  if (counter > 0) {
    return this->browse(counter-1, node->next);
  }

  return node;

}

// add a new value to the list
template <typename T>
int cezarmathe :: LinkedList<T> :: append(T value) {
  LinkedListNode<T>* lastnode = browse(this->size, this->first_node);
  
  LinkedListNode<T>* newnode = new LinkedListNode<T>(value);

  lastnode->next = newnode;
  newnode->previous = lastnode;

  this->size++;

  return size-1;
}

// return the size of the list
template <typename T>
int cezarmathe :: LinkedList<T> :: getSize() {
  return this->size;
}

// get a value from the list
template <typename T>
T cezarmathe :: LinkedList<T> :: getValue(int index) {
  LinkedListNode<T>* node = browse(index, this->first_node);
  return node->value;
}

#endif