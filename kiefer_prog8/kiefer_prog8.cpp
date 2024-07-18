// Author: Maddison Kiefer
// 
// Program: Print Stock Information
// This program will take a list of stock information and sort it by the stock symbol and by the 
// percent gain or loss

// Header Files
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <format>
#include "stockType.h"
#include "stockListType.h"
using namespace std;

// Mian Function
int main()
{
    // Gets the stock data from a text file
    ifstream inFile("StockData.txt");
    // Creating the stock array
    stockListType stockArray(50);
    // Temporary stock variable for inserting into stock array
    stockType localStock;
    
    int count = 0;
    // Checks for the correct text file
    if (!inFile)
    {
        cout << "Unable to open the correct text file, exiting from the program ";
        return 0;
    }
    // Reads each line, stores the data into the temp stock, and inserts that into the stock array
    while (!inFile.eof())
    {
        inFile >> localStock;
        stockArray.insertAt(localStock, count++);
    }

    // Sorts the stock array
    stockArray.sort();
    int* sortedbygainloss = stockArray.getIndicesGainLoss();
    // Formatting for the console
    cout << "****First Investor's Heaven******" << endl;
    cout << "****Financial Report******" << endl;
    cout << "Stock Today Previous Precent " << endl;
    cout << "Symbol   Open     Close      High      Low      Close      Gain      Volume" << endl;
    cout << "------   -----    -----      -----     -----    -----      -----     ------" << endl;
    // Prints the stock array
    stockArray.print();
    // Formatting for the console
    cout << "Closing Assets: $" << fixed << setprecision(2) << stockArray.getTotalClosingAssets() << endl;
    cout << "***************************************" << endl;
    cout << endl << endl;
    cout << "****First Investor's Heaven******" << endl;
    cout << "****Financial Report******" << endl;
    cout << "Stock Today Previous Precent " << endl;
    cout << "Symbol   Open     Close      High      Low      Close      Gain      Volume" << endl;
    cout << "------   -----    -----      -----     -----    -----      -----     ------" << endl;
    // Prints the stock array by gain and loss
    stockArray.printIndicesGainLoss();
    cout << "Closing Assets: $" << fixed << setprecision(2) << stockArray.getTotalClosingAssets() << endl;
    cout << endl;

    system("pause");
    return 0;
}

