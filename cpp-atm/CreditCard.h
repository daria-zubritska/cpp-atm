#pragma once
#include <string>
#include "Card.h"
#include <vector>

using namespace std;

class CreditCard : public Card
{

private:

	double credLim;

public:
	CreditCard() : credLim{0.0} {};

	CreditCard(const string& number, const string& pin, const string& endDate, const int& cvv,
		const double& balance, const string& currency, const bool& isActive, const double& credLim) :
		Card{ number, pin, endDate, cvv, balance, currency, isActive }, credLim{ credLim }
	{};

	CreditCard(const CreditCard& toCopy) :
		Card{ toCopy }, credLim{ toCopy.getCredLim()}
	{};

	~CreditCard() {};

	double getCredLim() const { return credLim; };

	void setCredLim(double newCredLim) { credLim = newCredLim; };

	vector<string> getCard() override
	{
		vector<string> cardInfo = Card::getCard();
		cardInfo.push_back("Credit limit: " + to_string(credLim));
		return cardInfo;
	}

};