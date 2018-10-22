
#ifndef LINKEDLIST_H

#define LINKEDLIST_H

#ifndef NULL
#define NULL 0
#endif

namespace cezarmathe {

  // a list node
  template <typename T> 
  struct LinkedListNode
  {
    // the address of the previous node
    LinkedListNode* previous;
    // the value of this node
    T value;
    // the address of the next node
    LinkedListNode* next;

    LinkedListNode();
  };

  // the list
  template <typename T> 
  class LinkedList
  {
  private:
    // address of the first node
    LinkedListNode<T>* first_node;
    // the size of the list
    int size;

    // browse to a certain list node
    LinkedListNode<T>& browse(int counter, LinkedListNode<T>* node);

  public:
    LinkedList();
    ~LinkedList();

    // insert a value at the end of the list
    void append(const T value);

    // get the size of the list
    int getSize();

    // get a value from the list
    T getValue(const int index);

    // same as getValue
    T operator[](const int index);

    // deletes a value from the list and changes
    // the addresses for the surrounding nodes
    void remove(const int index);

  }; 
}

#endif