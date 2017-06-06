#pragma once
#include "ListObject.h"
#include "Iterator.h"
#include <assert.h>

class linkList
{
public:
    linkList();
    ~linkList();

    ListObject* m_first;
    ListObject* m_last;

    // add new value to the front the list
   void pushFront(int value);

   //add new value to the end of the list
   void pushBack(int value);

   //add new value one past the specified iterator location
   void insert(iterator,int value);

   //return the iterator the the first element
   void begin();

   //move the iterator to the null element at the end
   void end();//what??

   //return the 1st element by value assert if no elements
   int first();

   //return last element by value assert if no elements
   int last();

   //return total number of elements in the list
   int count();

   //remove an element by it's iterator
   void erase(iterator);

   //remove all elements with a certain value
   void remove(int value);

   //remove the last element
   void popBack();

   //remove the front object
   void popFront();

   //return true if list is empty false if not
   bool empty();

   //remove all elements from the list
   void clear();






};

