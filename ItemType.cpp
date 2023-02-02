#include "ItemType.h"

#include <sstream>
#include <bitset>
#include <string>

// MARK: Stubbed Constructor
ItemType::ItemType()
{
    identifier = "n/a";
}

// MARK: Copy Constructor
ItemType::ItemType(const ItemType &origItem)
{
    this->identifier = origItem.identifier;
}

// MARK: Copy Assignment Constructor
ItemType ItemType::operator =(const ItemType &rhs)
{
    this->identifier = rhs.identifier;
    return *this;
}

// MARK: Alternate Copy Assignment Constructor
ItemType ItemType::operator =(string s)
{
    this->identifier = s;
    return *this;
}

// MARK: 6 Relational Operators
bool ItemType::operator==(ItemType &rhs)
{
    return this->identifier==rhs.identifier;
}
bool ItemType::operator!=(ItemType &rhs)
{
    return this->identifier!=rhs.identifier;
}
bool ItemType::operator< (ItemType &rhs)
{
    return this->identifier<rhs.identifier;
}
bool ItemType::operator> (ItemType &rhs)
{
    return this->identifier>rhs.identifier;
}
bool ItemType::operator<=(ItemType &rhs)
{
    return this->identifier<=rhs.identifier;
}
bool ItemType::operator>=(ItemType &rhs)
{
    return this->identifier>=rhs.identifier;
}

// MARK: Overloaded Insertion Operator
ostream & operator << (ostream &out, const ItemType &item)
{
    out.clear();
    out << item.identifier;
    return out;
}

unsigned long ItemType::getHash()
{
    stringstream ss;
    unsigned int n;

    string s = md5(identifier).substr(0,8);

    ss << hex << s;
    ss >> n;
    bitset<32> b(n);

    //???
    return b.to_ulong();
}
