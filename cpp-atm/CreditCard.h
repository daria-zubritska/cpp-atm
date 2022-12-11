#pragma once
#include <string>
#include "Card.h"
#include <vector>

using namespace std;

class CreditCard : public Card
{

private:

	float credLim;

public:
	CreditCard() : credLim{0.0} {};

	CreditCard(const string& number, const string& pin, const string& endDate, const int& cvv,
		const float& balance, const string& currency, const bool& isActive, const float& credLim) :
		Card{ number, pin, endDate, cvv, balance, currency, isActive }, credLim{ credLim }
	{};

	CreditCard(const CreditCard& toCopy) :
		Card{ toCopy }, credLim{ toCopy.getCredLim()}
	{};

	~CreditCard() {};

	float getCredLim() const { return credLim; };

	void setCredLim(float newCredLim) { credLim = newCredLim; };

	vector<string> getCard() override
	{
		vector<string> cardInfo = Card::getCard();
		cardInfo.push_back("Credit limit: " + to_string(credLim));
		return cardInfo;
	}

};