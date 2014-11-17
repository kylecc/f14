#include "hashtable.h"

HashTable::HashTable(const int s) {
  check(s <= 0, "HashTable::HashTable(int) : Invalid size");
  size = s;
  data = new LinkList*[size];
  check(data == NULL, "HashTable::HashTable(int) : Out of memory");
  for(int i = 0; i < size; ++i) {
    data[i] = NULL;
  }
}

HashTable::HashTable(const HashTable& h) {
  data = NULL;
  *this = h;
}

HashTable::~HashTable() {
  for(int i = 0; i < size; ++i) {
    kill(data[i]);
  }
  delete []data;
}

LinkList* HashTable::find(const String key) const {
  Hash h(key);
  int index = h.hash() % size;
  LinkList* ptr = data[index];
  while(ptr != NULL) {
    if(key == ptr->key) {
      return ptr;
    } else {
      ptr = ptr->next;
    }
  }
  return ptr;
}

void HashTable::kill(LinkList* link) {
  LinkList* ptr = link;
  while(ptr != NULL) {
    LinkList* temp = ptr;
    ptr = ptr->next;
    delete temp;
  }
}

bool HashTable::inTable(String key) const {
  return find(key) != NULL;
}

HashTable& HashTable::operator= (const HashTable& h) {
  if(data != NULL) {
    for(int i = 0; i < size; ++i) {
      kill(data[i]);
    }
    delete []data;
  }
  size = h.size;
  data = new LinkList*[size];
  check(data == NULL, "HashTable::operator= (HashTable) : Out of memory");
  for(int i = 0; i < size; ++i) {
    LinkList* ptr = h.data[i];
    while(ptr != NULL) {
      data[i] = new LinkList(ptr->key, ptr->data);
    }
  }
  return *this;
}

void HashTable::add(const String key, const int d) {
  Hash h(key);
  int index = h.hash() % size;
  check(inTable(key), "HashTable::add(String, int) : Duplicate key");
  data[index] = new LinkList(key, d, data[index]);
  check(data[index] == NULL, "HashTable::add(String, int) : Out of memory");
}

HashTable& HashTable::remove(const String key) {
  Hash h(key);
  int index = h.hash() % size;
  check(!inTable(key), "HashTable::remove(String) : Key not found");
  LinkList* ptr = data[index];
  LinkList* prv = NULL;
  while(ptr != NULL) {
    if(key == ptr->key) {
      LinkList* temp = ptr->next;
      if(prv == NULL) {
	data[index] = temp;
      } else {
	prv->next = temp;
      }
      delete ptr;
      return *this;
    } else {
      prv = ptr;
      ptr = ptr->next;
    }
  }
  return *this;
}

HashTable& HashTable::operator+= (const String key) {
  add(key);
  return *this;
}

int HashTable::operator[] (const String key) const {
  check(!inTable(key), "HashTable::operator[] const : Key not found");
  return find(key)->data;
}

int& HashTable::operator[] (const String key) {
  if(!inTable(key)) {
    add(key);
  }
  return find(key)->data;
}

ostream& operator<< (ostream& out, const HashTable& h) {
  for(int i = 0; i < h.size; ++i) {
    out << "Index = " << i << " ";
    LinkList* ptr = h.data[i];
    while(ptr != NULL) {
      out << "(" << ptr->key << ", " << ptr->data << ")--->";
      ptr = ptr->next;
    }
    out << "NULL" << endl;
  }
  return out;
}
