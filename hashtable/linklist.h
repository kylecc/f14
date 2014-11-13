#ifndef LINKLIST_H
#define LINKLIST_H

#include "check.h"
#include "String.h"

class LinkList {
public:
  String key;
  int data;
  LinkList* next;

  LinkList(String key, int data, LinkList* next = NULL);
  
  friend ostream& operator<< (ostream& out, LinkList& l);
};

#endif
