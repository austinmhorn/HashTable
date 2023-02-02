#ifndef ITEMTYPE_HPP
#define ITEMTYPE_HPP

#include "md5.h"
#include <iostream>
#include <string>

using namespace std;

struct ItemType
{
    string identifier;
    
    ItemType();
    ItemType(const ItemType &);
    
    ItemType operator =(const ItemType &);
    ItemType operator =(string);
    
    bool operator==(ItemType &);
    bool operator!=(ItemType &);
    bool operator< (ItemType &);
    bool operator> (ItemType &);
    bool operator<=(ItemType &);
    bool operator>=(ItemType &);
    
    unsigned long getHash();
    
    friend ostream & operator << (ostream &, const ItemType &);
};

#endif // ITEMTYPE_HPP
