
 /* This program implements a template linked list as a hashed array. I will use the MD5 algorithm to derive the initial hash value. */

 /* Essentially, my code amounts to an array of (very short) linked lists. The idea of hashing is that, once you have derived the record's hash, you are able to access the array position at which it is stored directly. */
 
 /* For hash collision prevention, I've implemented the idea of making each array position the root of a linked list. Thus, for some arbitrary integer, i, roots[i] would be the root of the list containing all elements that hashed to that location. */

#include "ItemType.h"
#include "ListType.cpp"

int main(void)
{
    
    std::cout<<"\n*** Start Routine ***"<<std::endl;

    ItemType item;
    ListType<ItemType> list;
    // HASH_SPACE is 16

    item="aaaa";
    list.put(item);
    item="bbbb";
    list.put(item);
    item="cccc";
    list.put(item);
    item="dddd";
    list.put(item);
    item="eeee";
    list.put(item);
    item="ffff";
    list.put(item);
    item="gggg";
    list.put(item);
    item="hhhh";
    list.put(item);
    item="iiii";
    list.put(item);
    item="jjjj";
    list.put(item);
    item="kkkk";
    list.put(item);
    item="llll";
    list.put(item);
    item="mmmm";
    list.put(item);
    item="nnnn";
    list.put(item);
    item="oooo";
    list.put(item);
    item="pppp";
    list.put(item);

    list.print("part one");

    item="gggg";
    list.remove(item);
    item="kkkk";
    list.remove(item);
    item="hhhh";
    list.remove(item);
    item="llll";
    list.remove(item);

    list.print("part two");
    
    std::cout<<"\n*** End Routine ***"<<std::endl;
    std::exit(EXIT_SUCCESS);
}

// Get string from user
/*
 
 ItemType item;
 ListType<ItemType> list;

 string s;
 
 while(true)
 {
     std::cout<<"Enter string to hash: ";
     std::getline(cin, s);
     if(s=="")
         break;
     item = s;
     list.isThere( item );
 }
 
 */
