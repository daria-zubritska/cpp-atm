#pragma once
#include <string>;
#include "Card.h";
using namespace std;

class DebitCard : public Card
{

private:

public:
	DebitCard() {};

	DebitCard(const string& number, const string& pin, const string& endDate, const int& cvv,
		const double& balance, const string& currency, const bool& isActive):
		Card(number, pin, endDate, cvv, balance, currency, isActive)
	{};

	DebitCard(const DebitCard& toCopy) :
		Card{ toCopy } 
	{};

	~DebitCard() {};


};