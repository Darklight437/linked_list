#include "Iterator.h"



Iterator::Iterator()
{
}


Iterator::~Iterator()
{
}


ListObject Iterator::operator++()
{
    m_currentNode = m_currentNode->m_next;
}
