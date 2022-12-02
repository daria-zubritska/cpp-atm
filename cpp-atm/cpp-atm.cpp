#pragma once
#include <iostream>
#include "Screen.h"

#include "DBController.h"
#include "AuthDataDao.h"
#include "TransactionDao.h"
#include "CardDao.h"

#include <windows.h>
#include "ConsoleUtils.h"
#include "UIModels.h"
#include "PinInput.h"
#include "CardNumberInput.h"
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
	//мануальне видалення не забувати)
	DBController* db = new DBController();

	cout << "\nTransactionDaoTest" << endl;
	TransactionDao tdao = TransactionDao(db);
	Transaction t = tdao.getById(1);

	cout << "Is from correct: " << (t.getFrom() == "") << endl;
	cout << "Is to correct: " << (t.getTo() == "0000 0000 0000 0000") << endl;
	cout << "Is sum correct: " << (t.getSum() == 5000.0) << endl;
	cout << "Is date correct: " << (t.getDatetime() == "12/11/2022") << endl;

	cout << "\nAuthDataDaoTest" << endl;

	AuthDataDao adao = AuthDataDao(db);
	AuthenticationData a = adao.getByPhone("1231231234");

	cout << "Is phone correct: " << (a.getPhone() == "1231231234") << endl;
	cout << "Is password correct: " << (a.getPassword() == "pass with salt") << endl;

	cout << "\nCardDaoTest" << endl;
	CardDao cdao = CardDao(db);
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

	delete db;
}

int main()
{
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
	

	tests();
}