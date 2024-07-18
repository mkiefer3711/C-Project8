// Author: Maddison Kiefer
// Class for handling lists

// Header Files
#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cassert>
#include <iomanip>
#ifndef LISTTYPE_H
#define LISTTYPE_H
using namespace std;

// Creating the class and the member list
template <class elemType>
class listType
{
public:
	bool isEmpty() const;
	bool isFull() const;
	int getLength() const;
	int getMaxSize() const;
	void sort();
	void print() const;
	void insertAt(const elemType& item, int position);
	listType(int listSize = 50);
	~listType();
protected:
	int maxSize;
	int length;
	elemType *list;
};

// Function to determine whether the list is empty
template <class elemType>
bool listType<elemType>::isEmpty()const
{
	return (length == 0);
}

// Function to determine whether the list is full
template <class elemType>
bool listType<elemType>::isFull() const
{
	return (length == maxSize);
}

// Function to return the number of elements in the list
template <class elemType>
int listType<elemType>::getLength() const
{
	return length;
}

// Function to return the maximum number of elements
template <class elemType>
int listType<elemType>::getMaxSize() const
{
	return maxSize;
}

// Constructor that creates an array of the size specified by the parameter listSize
template <class elemType>
listType<elemType>::listType(int listSize)
{
	maxSize = listSize;
	length = 0;
	list = new elemType[maxSize];
}

// Deconstructor that deletes all the elements of the list
template <class elemType>
listType<elemType>::~listType()
{
	delete[] list;
}

// Function that will sort the list
template <class elemType>
void listType<elemType>::sort()
{
	int i, j;
	int min;
	elemType temp;

	for (i = 0; i < length; i++)
	{
		min = i;
		for (j = i + 1; j < length; ++j)
			if (list[j] < list[min])
				min = j;
		temp = list[i];
		list[i] = list[min];
		list[min] = temp;
	}
}

// Function that outputs the elements of the list
template <class elemType>
void listType<elemType>::print() const
{
	int i;
	for (i = 0; i < length; ++i)
		cout << list[i] << " ";
	cout << endl;
}

// Function to insert item in the list at the location specified by the position
template <class elemType>
void listType<elemType>::insertAt(const elemType& item, int position)
{
	assert(position >= 0 && position < maxSize);
	list[position] = item;
	length++;
}

#endif

