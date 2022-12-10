#pragma once

#include <iostream>

//reqired for setup
#include "ConsoleUtils.h"
#include "UIModels.h"
#include "Methods.h"

//testing
#include "DBController.h"


//main tests, may be removed later
#include "LoginScreen.h"
#include "CardSellectionScreen.h"
#include "CardDataScreen.h"
#include "TransactionInfoScreen.h"
#include "SumInputScreen.h"




void setup()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	//each symbol ~= 10??
	ConsoleUtils::resize({ 200, 200, 1310, 880 });
	UIModels::loadModels();
}

//method for testing
void tests() {
	
	//cout << "\nTransactionDaoTest" << endl;
	//TransactionDao tdao = TransactionDao(DBController::getController());
	//Transaction t = tdao.getById(1);

	//cout << "Is from correct: " << (t.getFrom() == "") << endl;
	//cout << "Is to correct: " << (t.getTo() == "0000 0000 0000 0000") << endl;
	//cout << "Is sum correct: " << (t.getSum() == 5000.0) << endl;
	//cout << "Is date correct: " << (t.getDatetime() == "12/11/2022") << endl;

	//cout << "\nAuthDataDaoTest" << endl;

	//AuthDataDao adao = AuthDataDao(DBController::getController());
	//AuthenticationData a = adao.getByPhone("1231231234");
	
	Methods m = Methods();

	Transaction t = Transaction("", "0000 0000 0000 0000", 10, "05/12/2022");
	cout << m.insertNewTrans(t) << endl;
	vector<Transaction> tts = m.getAllTransByCard("0000 0000 0000 0000");

	for (Transaction const& i : tts) {
		cout << i.getFrom()  << " " << i.getTo() << " " << i.getSum() << " " << i.getDatetime() << endl;
	}

	//cout << "Is phone correct: " << (a.getPhone() == "1231231234") << endl;
	//cout << "Is password correct: " << (a.getPassword() == "pass with salt") << endl;
	// 
	//cout << "Is account correct: " << m.checkAccount("1231231234", "pass with salt") << endl;

	//m.getAllCards("1231231234");

	//cout << "\nCardDaoTest" << endl;
	//CardDao cdao = CardDao(DBController::getController());
	//CreditCard cc = cdao.getByNumberC("0000 0000 0000 0001", tdao);
	//DebitCard dc = cdao.getByNumberD("0000 0000 0000 0000", tdao);

	//cout << "Is number correct: " << (cc.getNumber() == "0000 0000 0000 0001") << endl;
	//cout << "Is pin correct: " << (cc.getPin() == "1112") << endl;
	//cout << "Is endDate correct: " << (cc.getEndDate() == "10/24") << endl;
	//cout << "Is cvv correct: " << (cc.getCvv() == 222) << endl;
	//cout << "Is currency correct: " << (cc.getCurrency() == "UAH") << endl;
	//cout << "Is active correct: " << (cc.getIsActive() == 1) << endl;
	//cout << "Is cred limit correct: " << (cc.getCredLim() == 15000.0) << endl;

	//cout << "Is number correct: " << (dc.getNumber() == "0000 0000 0000 0000") << endl;
	//cout << "Is pin correct: " << (dc.getPin() == "1111") << endl;
	//cout << "Is endDate correct: " << (dc.getEndDate() == "10/24") << endl;
	//cout << "Is cvv correct: " << (dc.getCvv() == 111) << endl;
	//cout << "Is currency correct: " << (dc.getCurrency() == "UAH") << endl;
	//cout << "Is active correct: " << (dc.getIsActive() == 1) << endl;

	
}

int main()
{
    setup();
	/*CardSellectionScreen screen({"1 ","2 ","3 ","4 ","5 ","6 ","7 ","8 ","9 ","10","11","12","13","14","15","16"});
	screen.draw();
	screen.execute();*/

	Methods methods;

	LoginScreen logScreen;
	logScreen.draw();

	while (true)
	{

		if (logScreen.execute() == 0)
		{
			if (methods.checkAccount(logScreen.getLogin(), logScreen.getPassword()))
			{
				vector<CreditCard> userCCards = methods.getAllCCards(logScreen.getLogin());
				vector<DebitCard> userDCards = methods.getAllDCards(logScreen.getLogin());
				vector<string> cardStrings = methods.getCardStringsVector(userCCards, userDCards);
				vector<string> cardNumbers = methods.getCardNumbersVector(userCCards, userDCards);

				CardSellectionScreen cardScreen(cardStrings);
				cardScreen.draw();
				if (cardScreen.execute() == 0)
				{
					string number = cardNumbers.at(cardScreen.getCursorPosition());

					CardDataScreen cardData(methods.getAllTransStringsByCard(number), methods.getCardInfoByNumber(userCCards, userDCards, number), "Card: " + number);
					cardData.draw();

					switch (cardData.execute())
					{
					case 0:
					{
						SumInputScreen sumInpScr;
						sumInpScr.draw();
						if (sumInpScr.execute() == 0)
						{
							methods.donateOnZSUByNumber(userCCards, userDCards, number, sumInpScr.getValue());
						}
						break;
					}
					case 1:
					{
						TransactionInfoScreen transInfoScr(methods.getAllTransByCard(number).at(cardData.getSelectedTransactionIndex()).getTransaction());
						transInfoScr.draw();
						transInfoScr.execute();
						break;
					}
					default:
						break;
					}
					break;
				}
			}
			else
			{
				MessageBox(NULL, L"Wrong login or password", L"Error", MB_ICONERROR);
				logScreen.clear();
			}
		}
	}

		/*switch (cardData.execute())
		{
		case 0:
			sumInpScr.draw();
			if (sumInpScr.execute() == 0)
			{
				methods.donateOnZSUByNumber(userCCards, userDCards, number, sumInpScr.getValue());
			}
			break;
		case 1:
			transInfoScr.draw();
			transInfoScr.execute();
			break;
		default:
			break;
		}*/
	DBController::dispose();

}