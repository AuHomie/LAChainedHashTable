#ifndef CHAINEDHASHTABLE_H
#define CHAINEDHASHTABLE_H

#include <iostream>

template<class Type>
struct Node{
    Type info;
    Node<Type>*link;
};

template<class Type>
class ChainedHashtable;

template<class Type>
std::ostream& operator<<(std::ostream& out, ChainedHashtable<Type> & t);


template<class Type>
class ChainedHashtable{

    public:
        ChainedHashtable(int max);// Constructor for the Hashtable.  Creates an empty list


        ~ChainedHashtable(); //Deconstructor for the Hashtable.  Deallocates memory 


        void add(Type item);//Adds to the hashtable


        bool remove(Type item);//Removes an item from the hashtable.  Returns true if the item was successfully removed


        bool contains(Type item);//Determines if the value is in the hashtable


        bool empty();//Determines if the hashtable is empty


        int size();//Determines the number of items in the hashtable


        friend std::ostream& operator<<(std::ostream& out, ChainedHashtable<Type> & t);//Returns an output stream for displaying the Hashtable



    protected:

    int sz;
    int capacity; // size of hashtable
    Node<Type>** htable;


};
/*
ChainedHashtable(int max);// Constructor for the Hashtable.  Creates an empty list
~ChainedHashtable(); //Deconstructor for the Hashtable.  Deallocates memory 
void add(Type item);//Adds to the hashtable
bool remove(Type item);//Removes an item from the hashtable.  Returns true if the item was successfully removed
bool contains(Type item);//Determines if the value is in the hashtable
bool empty();//Determines if the hashtable is empty
int size();//Determines the number of items in the hashtable
std::ostream& operator<<(std::ostream& out, ChainedHashtable<Type> & t);//Returns an output stream for displaying the Hashtable
*/

#endif // CHAINEDHASHTABLE_H