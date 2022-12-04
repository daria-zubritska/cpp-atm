#pragma once
#include <iostream>
#include "Screen.h"
#include "DBController.h"
#include "AuthDataDao.h"
#include "TransactionDao.h"
#include "CardDao.h"

#include "Security.h"

#include <windows.h>
#include "ConsoleUtils.h"
#include "UIModels.h"
#include "CardNumberInput.h"
#include <vector>
#include "Window.cpp"
#include "LoginScreen.h"

AuthDataDao adao = AuthDataDao(DBController::getController());
TransactionDao tdao = TransactionDao(DBController::getController());
CardDao cdao = CardDao(DBController::getController());

string hashingPass(const string& pass) {
	int hashInt = 0;
	string combine = pass + "salt";

	const unsigned int VALUE = combine.length();
	for (auto Letter : combine)
	{
		srand(VALUE * Letter);
		hashInt += 33 + rand() % 92;
	}

	return std::to_string(hashInt);
}

void setup()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	//each symbol ~= 10??
	ConsoleUtils::resize({ 200, 200, 1310, 880 });
	UIModels::loadModels();
}

vector<Card> getAllCards(const string& phone)
{
	
	vector<Card> userCards;

	list<CreditCard> clist = cdao.getAllByUserC(phone, tdao);

	for (Card const& i : clist) {
		userCards.push_back(i);
	}

	list<DebitCard> dlist = cdao.getAllByUserD(phone, tdao);

	for (Card const& i : dlist) {
		userCards.push_back(i);
	}

	return userCards;
}

bool checkAccount(const string& phone, const string& pass)
{
	Security sec = Security();
	AuthenticationData a = adao.getByPhone(phone);
	cout << a.getPhone()<< endl;
	cout << a.getPassword() << endl;
	cout << hashingPass(pass) << endl;
	return ((a.getPhone() == phone) && (a.getPassword() == hashingPass(pass)));
}

//method for testing
void tests() {
	
	cout << "\nTransactionDaoTest" << endl;
	Transaction t = tdao.getById(1);

	cout << "Is from correct: " << (t.getFrom() == "") << endl;
	cout << "Is to correct: " << (t.getTo() == "0000 0000 0000 0000") << endl;
	cout << "Is sum correct: " << (t.getSum() == 5000.0) << endl;
	cout << "Is date correct: " << (t.getDatetime() == "12/11/2022") << endl;

	cout << "\nAuthDataDaoTest" << endl;

	AuthenticationData a = adao.getByPhone("1231231234");
	string ph = "1231231234";
	string p1 = "pass1";

	cout << "Is phone correct: " << (a.getPhone() == "1231231234") << endl;
	cout << "Is password correct: " << (a.getPassword() == "564") << endl;
	cout << "Check Account: " << checkAccount(ph, p1) << endl;

	cout << "\nCardDaoTest" << endl;

	CreditCard cc = cdao.getByNumberC("0000 0000 0000 0001", tdao);
	DebitCard dc = cdao.getByNumberD("0000 0000 0000 0000", tdao);

	cout << "Is number correct: " << (cc.getNumber() == "0000 0000 0000 0001") << endl;
	cout << "Is pin correct: " << (cc.getPin() == "1112") << endl;
	cout << "Is endDate correct: " << (cc.getEndDate() == "10/24") << endl;
	cout << "Is cvv correct: " << (cc.getCvv() == 222) << endl;
	cout << "Is currency correct: " << (cc.getCurrency() == "UAH") << endl;
	cout << "Is active correct: " << (cc.getIsActive() == 1) << endl;
	cout << "Is cred limit correct: " << (cc.getCredLim() == 15000.0) << endl;

	cout << "Is number correct: " << (dc.getNumber() == "0000 0000 0000 0000") << endl;
	cout << "Is pin correct: " << (dc.getPin() == "1111") << endl;
	cout << "Is endDate correct: " << (dc.getEndDate() == "10/24") << endl;
	cout << "Is cvv correct: " << (dc.getCvv() == 111) << endl;
	cout << "Is currency correct: " << (dc.getCurrency() == "UAH") << endl;
	cout << "Is active correct: " << (dc.getIsActive() == 1) << endl;

	//мануальне видалення не забувати)
	DBController::dispose();
}

int main()
{
	
 //   setup();
	//LoginScreen screen{ 120,40,1005 + 200,700 + 200 };
	//screen.draw();
	//screen.excecute();
	


	/*while (true)
	{
		cout << _getch();
	}*/


	//setup();
	//CardNumberInput a(UIModels::cardNumberInput, 10, 10);
	//cout << std::endl << a.excecute();
	//system("pause");
	//ConsoleUtils::ClearScreen();
	//PinInput input{UIModels::pinInput, 10,10};
	//cout << std::endl << input.excecute();
	/*Screen screen{UIModels::terminalScreen};
	screen.excecute();*/


	//cout << UIModels::terminalScreen.symbols;
	
    /*Screen screen{50,20};
    for (int i = 0; i < 50; i++)
        cout << "0";*/
    /*CardNumberInput a(UIModels::cardNumberInput, 10, 10);
    cout << std::endl << a.excecute();
    system("pause");
    ConsoleUtils::ClearScreen();
    PinInput input{UIModels::pinInput, 10,10};
    cout << std::endl << input.excecute();*/
    /*Screen screen{UIModels::terminalScreen};
    screen.excecute();*/
    //cout << UIModels::terminalScreen.symbols;
    //мануальне видалення не забувати)
 

	tests();
}