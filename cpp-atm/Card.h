#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
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
	Card() : cvv{ 0 }, balance{ 0.0 }, isActive{ false } {};

	Card(const string& number, const string& pin, const string& endDate, const int& cvv,
		const long double& balance, const string& currency, const bool& isActive) :
		number{ number }, pin{ pin }, endDate{ endDate }, cvv{ cvv }, balance{ balance }, currency{ currency },
		isActive{ isActive }
	{};

	Card(const Card& toCopy) :
		number{ toCopy.getNumber() }, pin{ toCopy.getPin() }, endDate{ toCopy.getEndDate() }, cvv{ toCopy.getCvv()}, 
		balance{ toCopy.getBalance() }, currency{ toCopy.getCurrency()}, isActive{ toCopy.getIsActive() }
	{};

	~Card() {};

	string getNumber() const { return number; };
	string getPin() const { return pin; };
	string getEndDate() const { return endDate; };
	int getCvv() const { return cvv; };
	float getBalance() const { return balance; };
	string getCurrency() const { return currency; };
	bool getIsActive() const { return isActive; };

	void setNumber(string newNumber) { number = newNumber; };
	void setPin(string newPin) { pin = newPin; };
	void setEndDate(string newEndDate) { endDate = newEndDate; };
	void setCvv(int newCvv) { cvv = newCvv; };
	void setBalance(long double newBalance) { balance = newBalance; };
	void setCurrency(string newCurrency) { currency = newCurrency; };
	void setIsActive(bool newIsActive) { isActive = newIsActive; };

	virtual vector<string> getCard()
	{
		vector<string> cardInfo;

		cardInfo.push_back("Number: " + number);
		cardInfo.push_back("EndDate: " + endDate);
		cardInfo.push_back("CVV: " + to_string(cvv));
		auto buf = to_string(balance);
		buf.resize(buf.size() - 4);
		cardInfo.push_back("Balance: " + buf);
		cardInfo.push_back("Currency: " + currency);
		if (isActive)
		{
			cardInfo.push_back("This card is active");
		}
		else
		{
			cardInfo.push_back("This card is not active");
		}

		return cardInfo;
	}
};