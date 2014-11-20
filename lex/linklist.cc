#include "linklist.h"

LinkList::LinkList(String key, int data, LinkList* next) {
  this->key = key;
  this->data = data;
  this->next = next;
}

ostream& operator<< (ostream& out, LinkList& l) {
  out << "(" << l.key << ", " << l.data << ")";
  return out;
}
