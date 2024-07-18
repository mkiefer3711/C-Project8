// Author: Maddison Kiefer
// Class that inherits the listType class and add some modifications

// Header Files
#pragma once
#include "stockType.h"
#include "listType.h"
#ifndef STOCKLISTTYPE_H
#define STOCKLISTTYPE_H

// Creates the class and the members list
class stockListType : public listType<stockType>
{
public:
	stockListType(int listSize = 50);
	int* getIndicesGainLoss();
	void printIndicesGainLoss();
	double getTotalClosingAssets();


};

// Constructor function
stockListType::stockListType(int listSize)
	:listType<stockType>(listSize)
{
}

// Function that will sort the array by the gain or loss
int* stockListType::getIndicesGainLoss()
{
	double min = 0;
	double max;

	int* sortIndicesGainLoss = new int[length];

	 for (int i = 0; i < length; i++)
		 sortIndicesGainLoss[i] = i;


	 for (int i = 0; i < length; i++)
	 {
		 for (int j = 0; j < length - 1; j++)
		 {
			 if (list[sortIndicesGainLoss[j]].getGainOrLoss() < list[sortIndicesGainLoss[j + 1]].getGainOrLoss())
			 {
				 int temp = sortIndicesGainLoss[j];
				 sortIndicesGainLoss[j] = sortIndicesGainLoss[j + 1];
				 sortIndicesGainLoss[j + 1] = temp;
			 }
		 }
	 }

	 return sortIndicesGainLoss;
}

// Function that will print the array by gain or loss percent
void stockListType::printIndicesGainLoss()
{
	int* temparr = getIndicesGainLoss();

	for (int i = 0; i < length; i++)
	{
		cout << list[temparr[i]];
	}

}

// Function that will calculate the closing assets value
double stockListType::getTotalClosingAssets()
{
	stockType temp;
	double totalAssetsValue = 0;
	
	for (int i = 0; i < length; i++)
	{
		temp = list[i];

		totalAssetsValue += (temp.getShares() * temp.getClosePrice());
	}

	return totalAssetsValue;
}

#endif
