#pragma once

enum class Role
{
    HEAD, BODY, TAIL
};

class ListObject
{
public:



    int m_value;
    ListObject* m_next;
    ListObject* m_previous;
    

    ListObject();
    ~ListObject();

protected:

   


};

