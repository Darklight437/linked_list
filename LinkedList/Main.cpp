#include <iostream>
#include "linkList.h"




// implement unit test here

// each unit of the list needs to point to the one ahead and the one behind
// also look at the exercise criteria

int main()
{
    LinkList<int> foo;

    LinkList<int>::Iterator bar;
    
    //WAI
    foo.pushFront(32);

    foo.pushBack(64);
    foo.pushBack(1);
    foo.pushBack(77);


    //good
    bar = foo.begin(bar);
    bar.m_currentNode->m_value;
    bar++;
    bar++;
    foo.insert(25, bar);

    //good
    foo.first();

    foo.popBack();

    foo.popFront();

    std::cout << "everything works i promise\n\n";
    system("pause");
    return 0;
}


//test pushing front and back


