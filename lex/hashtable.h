#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "check.h"
#include "linklist.h"
#include "hash.h"

class HashTable {
private:
  LinkList** data;
  int size;
  static const int DEFSIZE = 47;

  void kill(LinkList* link);
  LinkList* find(const String key) const;
public:
  HashTable();
  HashTable(const int s);
  HashTable(const HashTable& h);
  ~HashTable();
  int operator[] (const String key) const;
  int& operator[] (const String key);
  bool inTable(const String key) const;
  void add(const String key, const int data = 0);
  HashTable& remove(const String key);
  HashTable& operator+= (const String key);
  HashTable& operator= (const HashTable& h);
  friend ostream& operator<< (ostream& out, const HashTable& h);
};

#endif
