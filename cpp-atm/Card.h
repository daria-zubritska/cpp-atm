#pragma once
#include <windows.h>
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
	double getBalance() const { return balance; };
	string getCurrency() const { return currency; };
	bool getIsActive() const { return isActive; };

	void setNumber(string newNumber) { number = newNumber; };
	void setPin(string newPin) { pin = newPin; };
	void setEndDate(string newEndDate) { endDate = newEndDate; };
	void setCvv(int newCvv) { cvv = newCvv; };
	void setBalance(long double newBalance) { balance = newBalance; };
	void setCurrency(string newCurrency) { currency = newCurrency; };
	void setIsActive(bool newIsActive) { isActive = newIsActive; };

	string GetCard()
	{
		string cardInfo;

		cardInfo += "Number: " + number + "\n";
		cardInfo += "EndDate: " + endDate + "\n";
		cardInfo += "CVV: " + to_string(cvv) + "\n";
		cardInfo += "Balance: " + to_string(balance) + "\n";
		cardInfo += "Currency: " + currency + "\n";
		if (isActive)
		{
			cardInfo += "This card is active";
		}
		else
		{
			cardInfo += "This card is not active";
		}

		return cardInfo;
	}

	void DonateOnZSU(const long double& sum)
	{
		if (sum <= balance)
		{
			balance -= sum;
			MessageBox(NULL, L"The money has been successfully transferred", L"Success", MB_ICONINFORMATION);
		}
		else
		{
			MessageBox(NULL, L"You don't have enough money on your card", L"Error", MB_ICONERROR);
		}
	}
};