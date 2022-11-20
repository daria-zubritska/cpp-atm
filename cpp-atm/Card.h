#pragma once
#include <string>
using namespace std;

class Card
{

private:

	string number;
	string pin;
	string endDate;
	int cvv;
	long double balance;
	string currency;
	bool isActive;

public:
	Card();

	Card(const string& number, const string& pin, const string& endDate, const int& cvv, 
		const long double& balance, const string& currency, const bool& isActive);

	Card(const Card& toCopy);

	~Card() {};

	string getNumber() const { return number; };
	string getPin() const { return pin; };
	string getEndDate() const { return endDate; };
	int getCvv() const { return cvv; };
	double getBalance() const { return balance; };
	string getCurrency() const { return currency; };
	bool getIsActive() const { return isActive; };

	void setPin(string newPin) { pin = newPin; };
	void setSum(int newBalance) { balance = newBalance; };
	void setIsActive(bool newIsActive) { isActive = newIsActive; };
};