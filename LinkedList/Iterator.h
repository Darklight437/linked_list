#pragma once
#include "ListObject.h"

class Iterator
{
public:

    Iterator();
    ~Iterator();
    ListObject* m_currentNode;

   ListObject operator ++();

 
};

