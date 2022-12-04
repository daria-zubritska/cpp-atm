#include <string>
#include "Card.h"
#include <windows.h>
using namespace std;


string Card::GetCard()
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

void Card::DonateOnZSU(const long double& sum)
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
