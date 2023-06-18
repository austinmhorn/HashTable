#ifndef LISTTYPE_CPP
#define LISTTYPE_CPP

#include <iostream>
using namespace std;

template <class T>
class ListType
{
private:
    static const int HASH_SPACE = 0x10; // 16 in hex

    struct NodeType
    {
        T payload;
        NodeType* next;
        NodeType() { this->next = nullptr; }
    };
    NodeType **roots;
    NodeType **envPtr;
public:
    ListType();
    void create();
    bool isRoom();
    bool isThere(T &);
    void put(T &);
    void remove(T &);
    void print(string);
    int getHashIndex(unsigned long);
};

template <class T>
ListType<T>::ListType()
{
    this->roots = nullptr;
    this->envPtr = nullptr;
    create();
}

template <class T>
void ListType<T>::create()
{
    this->roots = new NodeType*[HASH_SPACE];

    for(int i = 0; i < HASH_SPACE; i++)
        this->roots[ i ] = nullptr;

    this->envPtr = nullptr;
    
    
}

template <class T>
bool ListType<T>::isRoom()
{
    // Note: There is no standard way to do this with 100% certainty.
    NodeType *n1;
    n1 = new NodeType;
    // Allocation failure returns nullptr
    if ( n1 )
    {
        delete n1;
        return true;
    }
    else return false;
}

template <class T>
bool ListType<T>::isThere(T &unit)
{
    unsigned long h = unit.getHash();
    
    int i = getHashIndex(h);
    
    this->envPtr = &this->roots[ i ];
    while( *this->envPtr  &&  (*this->envPtr)->payload != unit )
        this->envPtr = &(*this->envPtr)->next;
    
    //cout << "Identifier: " << unit.identifier << "\tIndex: " << i << endl;
        
    return *this->envPtr && (*this->envPtr)->payload == unit;
    
    /*
    cout<<"The long int (in hex) returned from itemType is: "
        <<hex<<h<<'\n'<<"The index for "<<unit.identifier
        <<" will be "<<hex<<i<<" in hex or "<<dec<<i
        <<" in decimal.\n\n";
    */
}

template <class T>
void ListType<T>::put(T &unit)
{
    if ( !this->envPtr )
    {
        cout << "envPtr == nullptr" << endl;
    }
    
    if ( !isThere(unit) )
    {
        NodeType *n1 = *this->envPtr;
        *this->envPtr = new NodeType;
        (*this->envPtr)->payload = unit;
        (*this->envPtr)->next = n1;
    }
}

template <class T>
void ListType<T>::remove(T &unit)
{
    if ( isThere(unit) )
    {
        NodeType *n1;
        n1 = *this->envPtr;
        *this->envPtr = (*this->envPtr)->next;
        
        n1->next = nullptr;
        delete n1;
    }
}

template <class T>
void ListType<T>::print(string str)
{
    cout << str << endl;
    cout << endl << endl << endl;
    cout << "***********************" << endl;
    for (int i = 0; i < HASH_SPACE; i++)
    {
        cout << "Bucket: " << i << endl;
        
        this->envPtr = &roots[ i ];
        
        while ( *this->envPtr )
        {
            cout << (*this->envPtr)->payload << endl;
            this->envPtr = &(*this->envPtr)->next;
        }
        cout << endl;
    }
    cout << "***********************" << endl;
}

template <class T>
int ListType<T>::getHashIndex(unsigned long k)
{
    return (k % HASH_SPACE);
}

#endif // LISTTYPE_CPP
