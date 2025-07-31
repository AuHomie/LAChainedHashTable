#ifndef CHAINEDHASHTABLE_H
#define CHAINEDHASHTABLE_H

#include <iostream>
#include <iomanip>

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

    template<class Type>
    ChainedHashtable<Type>::ChainedHashtable(int max){
        sz = 0;
        capacity = max;
        htable = new Node<Type>*[capacity]();
    };

    template<class Type>
    ChainedHashtable<Type>::~ChainedHashtable(){
        delete[] htable;
    };

    template<class Type>
    bool ChainedHashtable<Type>::empty(){
        return sz == 0;
    };

    template<class Type>
    int ChainedHashtable<Type>::size(){
            return sz;
    };

    template<class Type>
    void ChainedHashtable<Type>::add(Type item){
        int key = item % capacity;


        //if there is a collistion
        if(htable[key]){
            auto node = new Node<Type>();
            node->info = item;
            node->link = htable[key];
            htable[key] = node;
            sz++;
        }
        else{
            htable[key] = new Node<Type>();
            htable[key]->info = item;
            sz++;
        }
    };

    template<class Type>
    bool ChainedHashtable<Type>::contains(Type item){
        int key = item % capacity;

        auto curr = htable[key];

        while (curr)
        {
           if (curr->info == item){
            return true
           }
           curr = curr->linkl
        }
        return false;
    };

    template<class Type>
    bool ChainedHashtable<Type>::remove(Type item){
        if (empty){
            std::runtime_error("Table is empty")
        }
        int key = item % capacity;
        auto curr = htable[key];
        Node<Type>* prev = nullptr;

        while (curr){
            if(curr->info == item){
                if(prev){
                    prev->link = curr->link;
                    delete curr;
                }
                else{
                    htable[key] = nullptr;
                    delete curr;
                }
                sz--;
                return true;
            }
            prev = curr;
            curr = curr->link;
        }
        return false;
    };

    /*
ChainedHashtable(int max);// Constructor for the Hashtable.  Creates an empty list
~ChainedHashtable(); //Deconstructor for the Hashtable.  Deallocates memory 
bool remove(Type item);//Removes an item from the hashtable.  Returns true if the item was successfully removed
bool contains(Type item);//Determines if the value is in the hashtable
bool empty();//Determines if the hashtable is empty
int size();//Determines the number of items in the hashtable
std::ostream& operator<<(std::ostream& out, ChainedHashtable<Type> & t);//Returns an output stream for displaying the Hashtable
*/

#endif // CHAINEDHASHTABLE_H