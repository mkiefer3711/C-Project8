// Author: Maddison Kiefer
// Class for all of the componenets of a stock

// Header Files
#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#ifndef STOCKTYPE_H
#define STOCKTYPE_H
using namespace std;

// Creating the class and creating the member list
class stockType
{
public:
	stockType(string symbols, double openPrice, double closePrice, double todayHigh, double todayLow, double prevClose, int volume);
	friend istream& operator >> (istream& ins, stockType& stock);
	friend ostream& operator << (ostream& outs, const stockType& stock);
	void setStockInfo(string symb, double open, double close, double high, double prevLow, double prevClosePrice, int numShares);
	void calculateGainOrLoss(double closeP, double prevP);
	
	bool operator == (const stockType& stock1) const;
	bool operator != (const stockType& stock1) const;
	bool operator <= (const stockType& stock1) const;
	bool operator < (const stockType& stock1) const;
	bool operator >= (const stockType& stock1) const;
	bool operator > (const stockType& stock1) const;
	
	string getSymbol()const { return symbol; }
	double getOpenPrice()const { return newOpenPrice; }
	double getClosePrice()const { return newClosePrice; }
	double getTodayHigh()const { return newTodayHigh; }
	double getTodayLow()const { return newTodayLow; }
	double getPrevClose()const { return newPrevClose; }
	int getShares()const { return shares; }
	double getGainOrLoss()const { return gainOrLoss; }
	

private:
	string symbol;
	double newOpenPrice, newClosePrice, newTodayHigh, newTodayLow, newPrevClose, gainOrLoss;
	int shares;
};

// Constructor function for the class
stockType::stockType(string symbols = "", double openPrice = 0.0, double closePrice = 0.0, double todayHigh = 0.0, double todayLow = 0.0, double prevClose = 0.0, int volume = 0)
{
	setStockInfo(symbol, openPrice, closePrice, todayHigh, todayLow, prevClose, volume);
}

// Function to set all of the info to different variables
void stockType::setStockInfo(string symb, double open, double close, double high, double prevLow, double prevClosePrice, int numShares)
{
	symbol = symb;
	newOpenPrice = open;
	newClosePrice = close;
	newTodayHigh = high;
	newTodayLow = prevLow;
	newPrevClose = prevClosePrice;
	shares = numShares;
}

// Function that splits each line by white space and inserts into each of the stocks variables
istream& operator >> (istream& ins, stockType& stock)
{
	ins >> stock.symbol;
	ins >> stock.newOpenPrice;
	ins >> stock.newClosePrice;
	ins >> stock.newTodayHigh;
	ins >> stock.newTodayLow;
	ins >> stock.newPrevClose;
	ins >> stock.shares;
	stock.calculateGainOrLoss(stock.newClosePrice, stock.newPrevClose);
	return ins;
}

// Prints each of the stocks variables
ostream& operator << (ostream& outs, const stockType& stock)
{
	outs << stock.getSymbol()
	<< fixed << showpoint << setprecision(2)
	<<setw(10) << stock.getOpenPrice() << setw(10)
	<< stock.getClosePrice() << setw(10)
	<< stock.getTodayHigh() << setw(10)
	<< stock.getTodayLow() << setw(10)
	<< stock.getPrevClose() << setw(10)
	<< stock.getGainOrLoss() << "%" << setw(10)
	<< stock.getShares() << endl << endl;
	return outs;
}

// Function to calculate the percent of gain or loss
void stockType::calculateGainOrLoss(double closeP, double prevP)
{
	gainOrLoss = (closeP - prevP) * 100 / prevP;
}

// Functions to overload the operators
bool stockType::operator == (const stockType& stock1) const
{
	return (symbol == stock1.symbol);
}

bool stockType::operator != (const stockType& stock1) const
{
	return (symbol != stock1.symbol);
}

bool stockType::operator >= (const stockType& stock1) const
{
	return (symbol >= stock1.symbol);
}

bool stockType::operator > (const stockType& stock1) const
{
	return (symbol > stock1.symbol);
}

bool stockType::operator <= (const stockType& stock1) const
{
	return (symbol <= stock1.symbol);
}

bool stockType::operator < (const stockType& stock1) const
{
	return (symbol < stock1.symbol);
}

#endif
