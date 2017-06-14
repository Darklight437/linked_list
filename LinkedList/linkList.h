#pragma once
#include <assert.h>




template <class T>
class LinkList
{


/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
//
//    MAIN-CLASS
// 
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

    class ListObject;

public:
    class Iterator;




    LinkList()
    {
        m_first = nullptr;
        m_last = nullptr;
    }

    ~LinkList() {};

    ListObject* m_first;
    ListObject* m_last;
    int m_numOfNodes = 0;




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
            m_currentNode = m_currentNode->m_previous;
        }

        void operator ++(int)
        {
            m_currentNode = m_currentNode->m_previous;
        }


    };


private:
    class ListObject
    {
    public:



        T m_value;
        ListObject* m_next;
        ListObject* m_previous;


        ListObject()
        {
            m_next = nullptr;
            m_previous = nullptr;
        };
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
        if (oldNode != nullptr)
        {
            oldNode->m_next = newNode;
        }
        
        m_first = newNode;
        if (m_last == nullptr)
        {
            m_last = newNode;
        }
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
        if (oldNode != nullptr)
        {
            oldNode->m_previous = newNode;
        }
       
        m_last = newNode;
        if (m_first == nullptr)
        {
            m_first = newNode;
        }
    }

   //add new value one past the specified iterator location
    void insert(T value, Iterator iterator)
    {
        ListObject* rightSide;
        ListObject* leftSide;
        ListObject* newNode;
        rightSide = iterator.m_currentNode->m_previous;
        leftSide = iterator.m_currentNode;
        
        newNode = new ListObject;
        newNode->m_value = value;
        m_numOfNodes++;

        newNode->m_previous = rightSide;
        newNode->m_next = leftSide;

        //ternary operators
        (rightSide == nullptr) ? (m_last = newNode) : (rightSide->m_next = newNode);

        (leftSide == nullptr) ? (m_first = newNode) : (leftSide->m_previous = newNode);
        

    }

   //return the iterator the the first element
    Iterator begin(Iterator iterator)
    {
        assert(m_first != nullptr && "linked list first node was null");
        iterator.m_currentNode = m_first;
        return iterator;
    }

   //move the iterator to the null element "at the end"
    Iterator end(Iterator iterator)
    {
        iterator.m_currentNode = nullptr;
    }

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
        ListObject* rightOf;
        ListObject* leftOf;

        rightOf = currentElement.m_currentNode->m_next;
        leftOf = currentElement.m_currentNode->m_previous;
        delete currentElement.m_currentNode;
        m_numOfNodes--;
        if (rightOf != nullptr)
        {
            rightOf->m_previous = leftOf;
        }
        if (leftOf != nullptr)
        {
            leftOf->m_next = rightOf;
        }
       
        if (rightOf != nullptr)
        {
            currentElement.m_currentNode = rightOf;
        }
        else if (leftOf != nullptr)
        {
            currentElement.m_currentNode = leftOf;
        }
        else
        {
            currentElement.m_currentNode = nullptr;
            assert(currentElement.m_currentNode != nullptr && "the iterator could not find a related node to either side of the deleted node");
        }
        
    }

   //remove all elements with a certain value
    void remove(T value, Iterator iter)
    {
        iter.m_currentNode = begin();

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
        //get the end value
        //grab the previous
		ListObject* nextInLine = m_last->m_next;
		delete m_last;
        m_numOfNodes--;
        m_last = nextInLine;
        m_last->m_previous = nullptr;
    }

   //remove the front object
    void popFront()
    {
        ListObject* nextInLine = m_first->m_previous;
        delete m_first;
        m_numOfNodes--;
        m_first = nextInLine;
        m_first->m_next = nullptr;
    }

   //return true if list is empty false if not
    bool empty()
    {
        //check if first has something
        if (m_first == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

   //remove all elements from the list
    void clear(Iterator frontOfList)
    {
        begin(frontOfList);
        while (frontOfList.m_currentNode != nullptr)
        {
            ListObject* deletThis = frontOfList.m_currentNode;
            frontOfList++;
            delete deletThis;
            
            
        }
        //set number of nodes to 0
        m_numOfNodes = 0;
        m_first = nullptr;
        m_last = nullptr;
        
    }


};

