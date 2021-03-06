#include <iostream>
#include "linkList.h"




// implement unit test here

// each unit of the list needs to point to the one ahead and the one behind
// also look at the exercise criteria

int main()
{
    LinkList<int> foo;

    LinkList<int>::Iterator bar;
    
    bool testPassed = true;
    //WAI
    foo.pushFront(32);

    foo.pushBack(64);
    foo.pushBack(1);
    foo.pushBack(77);

    if (foo.first() == 32 && foo.last() == 77)
    {
        std::cout << "pushfront & back working as intended";
    }
    else
    {
        std::cout << "push functions failed";
        testPassed = false;
    }
    //good
    bar = foo.begin(bar);
    bar.m_currentNode->m_value;
    bar++;
    bar++;
    foo.insert(25, bar);

    if (bar.m_currentNode->m_value == 25)
    {
        std::cout << "iterator insertion working as intended";
    }
    else
    {
        testPassed = false;
    }
    //good
  

    foo.popBack();

    foo.popFront();


    if (foo.empty() == false)
    {
        foo.clear(bar);
    }

    if (testPassed)
    {
        std::cout << "everything works i promise\n\n";
        system("pause");
        return 0;
    }
    else
    {
        std::cout << "system failed tests\n\n";
        system("pause");
        return 0;
    }
   
}


//test pushing front and back


