#include "hash.h"

Hash::Hash(String str)
{
    int temp = 0;
    int index = 0;
    while(index < str.length()){
        temp+= str[index];
        index++;
    }
    key = temp;
}

int Hash::hash() const
{
    return key;
}




