#include "linkedlist.h"

#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

// the LinkedListNode is initialized with null values for every field
template <typename T>
cezarmathe :: LinkedListNode<T> :: LinkedListNode(T val) 
{

  previous = nullptr;
  value = val;
  next = nullptr;

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
cezarmathe :: LinkedListNode<T>* cezarmathe :: LinkedList<T> :: browse(int counter, LinkedListNode<T>* node) 
{

  if (node->next == nullptr) {
    return node;
  }

  if (counter > 0) {
    return this->browse(counter-1, node->next);
  }

  return node;

}

// add a new value to the list
template <typename T>
void cezarmathe :: LinkedList<T> :: append(T value) 
{

  LinkedListNode<T>* lastnode = browse(this->size, this->first_node);
  
  LinkedListNode<T>* newnode = new LinkedListNode<T>(value);

  lastnode->next = newnode;
  newnode->previous = lastnode;

  this->size++;

  return;

}

// return the size of the list
template <typename T>
int cezarmathe :: LinkedList<T> :: getSize() {

  return this->size;

}

// get a value from the list
template <typename T>
T cezarmathe :: LinkedList<T> :: getValue(int index) {

  if (index == 0)
  {
    throw;
  }

  if (index > this->size)
  {
    throw;
  }

  LinkedListNode<T>* node = browse(index, this->first_node);

  return node->value;

}

// remove an item from the list
template <typename T>
void cezarmathe :: LinkedList<T> :: remove(int index) {

  if (index == 0)
  {
    throw;
  }

  if (index > this->size)
  {
    return;
  }

  if (index == 1)
  {
    LinkedListNode<T>* node = browse(index+1, this->first_node);
    first_node->next = node;
    node->previous = first_node;

    node = browse(index, this->first_node);
    delete node;

    this->size--;

    return;
  }

  if (index == this->size)
  {
    LinkedListNode<T>* node = browse(this->size-1, this->first_node);
    node->next = nullptr;

    node = browse(this->size-1, this->first_node);
    delete node;

    this->size--;

    return;
  }

  LinkedListNode<T>* node = browse(index+1, this->first_node);
  node->previous = browse(index-1, this->first_node);

  node = browse(index-1, this->first_node);
  node->next = browse(index+1, this->first_node);

  node = browse(index, this->first_node);
  delete node;

  this->size--;

  return;

}

// set a value for a list item
template <typename T>
void cezarmathe :: LinkedList<T> :: setValue(int index, T val) {

  if (index == 0)
  {
    throw;
  }

  if (index > this->size)
  {
    throw;
  }

  LinkedListNode<T>* node = browse(index, this->first_node);
  node->value = val;

  return;

}

#endif