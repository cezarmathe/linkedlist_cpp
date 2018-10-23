#include "linkedlist.cpp"

using namespace cezarmathe;

int main()
{
  LinkedList<int>* list = new LinkedList<int>();

  int size = list->getSize();

  for (int i = 1; i < 10000; i++)
    list->append(i);

  size = list->getSize();

  for (int i = 1; i < 10000; i+=4)
    list->remove(i);

  size = list->getSize();

  return 0;
}