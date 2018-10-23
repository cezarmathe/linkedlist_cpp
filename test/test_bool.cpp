#include "linkedlist.cpp"

using namespace cezarmathe;

int main()
{
  LinkedList<bool>* list = new LinkedList<bool>();

  int size = list->getSize();

  for (int i = 1; i < 10000; i++)
    if (i % 2 == 0)
    {
      list->append(true);
      continue;
    }
    list->append(false);

  size = list->getSize();

  for (int i = 1; i < 10000; i+=4)
    list->remove(i);

  size = list->getSize();

  return 0;
}