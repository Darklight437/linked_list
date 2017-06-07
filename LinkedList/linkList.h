#pragma once
#include <assert.h>




template <class T>
class LinkList
{
    class Iterator;
    class ListObject;


/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
//
//    MAIN-CLASS
// 
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////



public:



    LinkList()
    {
        m_first = nullptr;
        m_last = nullptr;
    }

    ~LinkList() {};

    ListObject* m_first;
    ListObject* m_last;
    int m_numOfNodes;




/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
//
//    SUB-CLASSES
// 
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////


    class Iterator
    {
    public:

        Iterator() {};
        ~Iterator() {};
        ListObject* m_currentNode;

        void operator ++()
        {
            m_currentNode = m_currentNode->m_next;
        }

        void operator ++(int)
        {
            m_currentNode = m_currentNode->m_next;
        }

    };


private:
    class ListObject
    {
    public:



        T m_value;
        ListObject* m_next;
        ListObject* m_previous;


        ListObject() {};
        ~ListObject() {};


    };
public:

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
//
// FUNCTIONS
//
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

    // add new value to the front the list
    void pushFront(T value)
    {
        ListObject* newNode;
        ListObject* oldNode;

        oldNode = m_first;
        newNode = new ListObject;

        newNode->m_value = value;
        m_numOfNodes++;


        newNode->m_previous = oldNode;
        oldNode->m_next = newNode;
        m_first = newNode;
    }




   //add new value to the end of the list
    void pushBack(T value)
    {
        ListObject* newNode;
        ListObject* oldNode;

        oldNode = m_last;
        newNode = new ListObject;

        newNode->m_value = value;
        m_numOfNodes++;

        newNode->m_next = oldNode;
        oldNode->m_previous = newNode;
        m_last = newNode;
    }

   //add new value one past the specified iterator location
    void insert(T value, Iterator iterator)
    {
      //  iterator.
    }

   //return the iterator the the first element
    Iterator begin(Iterator iterator)
    {
        assert(m_first != nullptr && "linked list first node was null");
        iterator.currentNode = m_first;
        return iterator;
    }

   //move the iterator to the null element at the end
    Iterator end() {}

   //return the 1st element by value assert if no elements
    T first()
    {
        assert(m_first != nullptr);
        return m_first->m_value;
    }
    

   //return last element by value assert if no elements
    T last()
    {
        assert(m_last != nullptr);
        return m_last->m_value;
    }

   //return total number of elements in the list
    int count()
    {
        return m_numOfNodes;
    }

   //remove an element by it's iterator
    void erase(Iterator currentElement)
    {
        //afhwoohey
    }




   //remove all elements with a certain value
    void remove(T value)
    {
        m_iterator.m_currentNode = begin();

        for (int i = 0; i < count(); i++)
        {
            if (m_iterator.m_currentNode->m_value == value)
            {
                erase();

            }
            m_iterator++;
        }
    }

   //remove the last element
    void popBack()
    {
        
    }

   //remove the front object
    void popFront() {}

   //return true if list is empty false if not
    bool empty() {}

   //remove all elements from the list
    void clear() {}


};

