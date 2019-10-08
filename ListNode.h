#ifndef LISTNODE_H_INCLUDED
#define LISTNODE_H_INCLUDED

#pragma once
#include <iostream>

template <typename T>
struct ListElement
{
    private:
        T value;
        ListElement<T>* next;

    public:
        T getValue()
        {
            return this.value;
        }

        ListElement<T>* getNext()
        {
            return this.next;
        }

        void setValue(T value)
        {
            this.value = value;
        }

        void setNext(ListElement<T>* next)
        {
            this.next = next;
        }
};

#endif // LISTNODE_H_INCLUDED
