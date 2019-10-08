#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#pragma once
#include <iostream>
#include "ListElement.h"

template <typename T>
class LinkedList;

template<typename T>
std::ostream& operator<< (std::ostream& output, const LinkedList<T>& other);

/**
    Template (Generic) LinkedList implementation.
    With the exposed API, users can add and remove elements from the front and back of the list structure.
    Moreover, users can iterate over the elements, access values by index, delete elements, change values of elements and more.
    The class overrides the << operator, so it is possible to directly 'cout' the list (assuming that the template type overrides the << operator).

    @author Radoslav Dimitrov
*/
template <typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	ListElement<T>* begin();
	ListElement<T>* next();
	ListElement<T>* end();
	void pushFront(T element);
	void pushBack(T element);
	T* popFront();
	T* popBack();
	void deleteNode(T element);
	T getValue(size_t index);
	T getValue();
	void setValue(T element, size_t index);
	bool contains(T element);
	bool isEmpty() const;
	bool hasNext();
	size_t size() const;
	friend std::ostream& operator<< <>(std::ostream& output, const LinkedList<T>& other);

private:
	ListElement<T>* first;
	ListElement<T>* last;
	ListElement<T>* current;
	size_t listSize;
	ListElement<T>* locate(size_t index);
	void addFirst(T element);
	T* removeOnly();
};

template <typename T>
LinkedList<T>::LinkedList()
{
	this->first = NULL;
	this->last = NULL;
	this->current = NULL;
	this->listSize = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	ListElement<T>* cursor;
    while (this->first != NULL)
    {
        cursor = this->first;
        this->first = this->first->getNext();
        delete cursor;
    }
    this->listSize = 0;
}

template <typename T>
ListElement<T>* LinkedList<T>::begin()
{
	this->current = this->first;
	return this->first;
}

template <typename T>
ListElement<T>* LinkedList<T>::next()
{
	this->current = this->current->getNext();
	return this->current;
}

template <typename T>
ListElement<T>* LinkedList<T>::end()
{
	return this->last;
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
	return this->listSize == 0;
}

template<typename T>
size_t LinkedList<T>::size() const
{
	return this->listSize;
}

template<typename T>
void LinkedList<T>::pushFront(T element)
{
	if (this->isEmpty())
    {
        this->addFirst(element);
    }
	else
	{
		ListElement<T>* node = new ListElement<T>();
        node->setValue(element);
        node->setNext(first);
		this->first = node;
	}
	this->listSize++;
}

template<typename T>
void LinkedList<T>::pushBack(T element)
{
	if (this->isEmpty())
    {
        this->addFirst(element);
    }
	else
	{
	    ListElement<T>* node = new ListElement<T>();
        node->setValue(element);
        node->setNext(NULL);
        this->last->setNext(node);
        this->last = node;
	}
	this->listSize++;
}

template<typename T>
T* LinkedList<T>::popFront()
{
	if (this->isEmpty())
    {
        return NULL;
    }
	else if (this->size() == 1)
    {
        return this->removeOnly();
    }
	else
    {
        ListElement<T>* cursor = this->first;
        this->first = this->first->getNext();
        this->listSize--;
        T* popValue = new T;
        *popValue = cursor->getValue();
        delete cursor;
        return popValue;
    }
}

template<typename T>
T* LinkedList<T>::popBack()
{
	if (this->isEmpty())
    {
        return NULL;
    }
	else if (this->size() == 1)
    {
        return this->removeOnly();
    }
    else
    {
        ListElement<T>* preLast = this->locate(this->size() - 2);
        T * popValue = new T;
        *popValue = this->last->getValue();
        delete this->last;
        this->last = preLast;
        this->last->setNext(NULL);
        this->listSize--;
        return popValue;
    }
}

template<typename T>
void LinkedList<T>::deleteNode(T element)
{
	if (this->size() <= 1 || this->first->getValue() == element)
    {
        this->popFront();
        return;
    }
	if (this->last->getValue() == element)
    {
        this->popBack();
        return;
    }
    ListElement<T>* cursor = this->first;
    ListElement<T>* preCursor;
    while (cursor->getValue() != element)
    {
        preCursor = cursor;
        cursor = preCursor->getNext();
    }
    preCursor->setNext(cursor->getNext());
    delete cursor;
    this->listSize--;
}

template<typename T>
T LinkedList<T>::getValue(size_t index)
{
	ListElement<T>* cursor = this->locate(index);
	return cursor->getValue();
}

template<typename T>
T LinkedList<T>::getValue()
{
	return this->current->getValue();
}

template<typename T>
void LinkedList<T>::setValue(T element, size_t index)
{
	ListElement<T>* cursor = this->locate(index);
	cursor->setValue(element);
}

template<typename T>
bool LinkedList<T>::contains(T element)
{
	if (this->isEmpty())
    {
        return false;
    }
    ListElement<T>* cursor = this->first;
    size_t i;
    for (i = 0; i < this->size(); i++, cursor = cursor->getNext())
    {
        if (cursor->getValue() == element)
        {
            return true;
        }
    }
    return false;
}

template<typename T>
bool LinkedList<T>::hasNext()
{
	return this->current != NULL && this->current->getNext() != NULL;
}

template<typename T>
std::ostream& operator<< (std::ostream& output, const LinkedList<T>& other)
{
    ListElement<T>* cursor = other.first;
    while (cursor != NULL)
    {
        output << cursor->getValue() << std::endl;
        cursor = cursor->getNext();
    }
    return output;
}

template<typename T>
ListElement<T>* LinkedList<T>::locate(size_t index)
{
    if (index < 0 || index >= this->size())
    {
        return NULL;
    }

    ListElement<T>* cursor = this->first;
    size_t i;
    for (i = 0; i != index; i++, cursor = cursor->getNext())
    {
        // iterate until the searched index is reached
    }
    return cursor;
}

template<typename T>
void LinkedList<T>::addFirst(T element)
{
    this->first = new ListElement<T>();
    this->first->setNext(NULL);
    this->first->setValue(element);
    this->last = this->first;
}

template<typename T>
T* LinkedList<T>::removeOnly()
{
    T* popValue = new T;
    *popValue = this->first->getValue();
    delete this->first;
    this->first = NULL;
    this->current = NULL;
    this->last = NULL;
    this->listSize = 0;
    return popValue;
}

#endif // LINKEDLIST_H_INCLUDED
