#ifndef LISTELEMENT_H_INCLUDED
#define LISTELEMENT_H_INCLUDED

#pragma once
#include <iostream>

/**
    Node structure in the LinkedList;
    Data class, which contains a value with template (generic) type and a pointer to the next ListElement
*/
template <typename T>
struct ListElement
{
    private:
        T value;
        ListElement<T>* next;

    public:
        T getValue()
        {
            return this->value;
        }

        ListElement<T>* getNext()
        {
            return this->next;
        }

        void setValue(T value)
        {
            this->value = value;
        }

        void setNext(ListElement<T>* next)
        {
            this->next = next;
        }
};

#endif // LISTELEMENT_H_INCLUDED
