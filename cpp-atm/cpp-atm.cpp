#pragma once

#include <iostream>

//reqired for setup
#include "ConsoleUtils.h"
#include "UIModels.h"
#include "Methods.h"

#include "LoginScreen.h"
#include "CardSellectionScreen.h"
#include "CardDataScreen.h"
#include "TransactionInfoScreen.h"
#include "SumInputScreen.h"
#include "CardNumberInputScreen.h"

void setup();
void start();



int main()
{
    setup();
	start();
	DBController::dispose();

}

void setup()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	//each symbol ~= 10??
	ConsoleUtils::resize({ 200, 200, 1310, 880 });
	UIModels::loadModels();
}

void start()
{
	Methods methods;


	while (true)
	{

		LoginScreen logScreen;
		logScreen.draw();

		if (logScreen.execute() == 0)
		{
			if (methods.checkAccount(logScreen.getLogin(), logScreen.getPassword()))
			{
				while (true)
				{
					vector<CreditCard> userCCards = methods.getAllCCards(logScreen.getLogin());
					vector<DebitCard> userDCards = methods.getAllDCards(logScreen.getLogin());
					vector<string> cardStrings = methods.getCardStringsVector(userCCards, userDCards);
					vector<string> cardNumbers = methods.getCardNumbersVector(userCCards, userDCards);

					CardSellectionScreen cardScreen(cardStrings);
					cardScreen.draw();
					if (cardScreen.execute() == 0)
					{
						while (true)
						{
							string number = cardNumbers.at(cardScreen.getCursorPosition());

							CardDataScreen cardData(methods.getAllTransStringsByCard(number), methods.getCardInfoByNumber(userCCards, userDCards, number), "Card: " + number);
							cardData.draw();

							switch (cardData.execute())
							{
							case 0:
							{
								switch (cardData.getSelectedElementIndex())
								{
								case 0:
								{
									SumInputScreen sumInpScr;
									sumInpScr.draw();
									if (sumInpScr.execute() == 0)
									{
										bool success = methods.donateOnZSUByNumber(userCCards, userDCards, number, sumInpScr.getValue());

										if (success) MessageBox(NULL, L"The money has been successfully transferred", L"Success", MB_ICONINFORMATION);
										else MessageBox(NULL, L"You don't have enough money on your card", L"Error", MB_ICONERROR);
									}
									continue;
								}
								case 1:
								{
									CardNumberInputScreen cardNumInpScr;
									cardNumInpScr.draw();
									if (cardNumInpScr.execute() == 0)
									{
										SumInputScreen sumInpScr;
										sumInpScr.draw();
										if (sumInpScr.execute() == 0)
										{
											string to = cardNumInpScr.getValue();
											bool success = methods.newTransaction(userCCards, userDCards, number, to, sumInpScr.getValue());

											if (success) MessageBox(NULL, L"The money has been successfully transferred", L"Success", MB_ICONINFORMATION);
											else MessageBox(NULL, L"You don't have enough money on your card", L"Error", MB_ICONERROR);
										}
									}
									continue;
								}
								case 2:
								{
									SumInputScreen sumInpScr;
									sumInpScr.draw();
									if (sumInpScr.execute() == 0)
									{
										bool success = methods.moneyOut(userCCards, userDCards, number, sumInpScr.getValue());

										if (success) MessageBox(NULL, L"The money has been successfully withdrawn", L"Success", MB_ICONINFORMATION);
										else MessageBox(NULL, L"You don't have enough money on your card", L"Error", MB_ICONERROR);
									}
									continue;
								}
								case 3:
								{
									SumInputScreen sumInpScr;
									sumInpScr.draw();
									if (sumInpScr.execute() == 0)
									{
										bool success = methods.moneyIn(userCCards, userDCards, number, sumInpScr.getValue());

										if (success) MessageBox(NULL, L"The money has been successfully added", L"Success", MB_ICONINFORMATION);
										else MessageBox(NULL, L"Operation failed", L"Error", MB_ICONERROR);
									}
									continue;
								}
								}
								continue;
							}
							case 1:
							{
								TransactionInfoScreen transInfoScr(methods.getAllTransByCard(number).at(cardData.getSelectedTransactionIndex()).getTransaction());
								transInfoScr.draw();
								transInfoScr.execute();
								continue;
							}
							case 2:
							{
								break;
							}
							}

							break;
						}
					}
					else break;
				}
			}
			else
			{
				MessageBox(NULL, L"Wrong login or password", L"Error", MB_ICONERROR);
				logScreen.clear();
			}
		}
	}
}