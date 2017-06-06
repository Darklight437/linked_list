#include "linkList.h"



linkList::linkList()
{
    m_first = nullptr;
    m_last = nullptr;
}


linkList::~linkList()
{
}

void linkList::pushFront(int value)
{
    ListObject* newNode;
    ListObject* oldNode;

    oldNode = m_first;
    newNode = new ListObject;

    newNode->m_value = value;

    newNode->m_previous = oldNode;
    oldNode->m_next = newNode;
    m_first = newNode;
}

void linkList::pushBack(int value)
{
    ListObject* newNode;
    ListObject* oldNode;

    oldNode = m_last;
    newNode = new ListObject;

    newNode->m_value = value;

    newNode->m_next = oldNode;
    oldNode->m_previous = newNode;
    m_last = newNode;
}

int linkList::first()
{
    assert(m_first != nullptr);
     return m_first->m_value;
}

int linkList::last()
{
    assert(m_last != nullptr);
    return m_last->m_value;
}
