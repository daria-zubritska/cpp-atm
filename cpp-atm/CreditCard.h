#pragma once
#include <string>;
#include "Card.h";
using namespace std;

class CreditCard : public Card
{

private:

	double credLim;

public:
	CreditCard();

	CreditCard(const string& number, const string& pin, const string& endDate, const int& cvv,
		const double& balance, const string& currency, const bool& isActive, const double& credLim);

	CreditCard(const CreditCard& toCopy);

	~CreditCard() {};

	double getCredLim() const { return credLim; };

	void setCredLim(double newCredLim) { credLim = newCredLim; };