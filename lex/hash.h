#ifndef HASH_H
#define HASH_H

#include "String.h"
#include "check.h"
class Hash
{
  public:
    Hash(String s);
    int key;
    int hash() const;
};
#endif





