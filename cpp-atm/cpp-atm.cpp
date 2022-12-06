#pragma once
#include "UIModels.h"
#include <iostream>
#include "Screen.h"
#include "DBController.h"
#include "AuthDataDao.h"
#include "TransactionDao.h"
#include "CardDao.h"
#include "Methods.h"

#include "Menu.h"
#include <windows.h>
#include "ConsoleUtils.h"
#include "CardNumberInput.h"
#include <vector>
#include "Window.cpp"
#include "LoginScreen.h"
#include "CardSellectionScreen.h"
//AuthDataDao adao = AuthDataDao(DBController::getController());
//TransactionDao tdao = TransactionDao(DBController::getController());
//CardDao cdao = CardDao(DBController::getController());

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
	//LoginScreen screen{ 120,40,1005 + 200,700 + 200 };
	//screen.draw();
	//screen.excecute();
    setup();
	/*
	int visibleCount = 0;
	for (int i = 0; i < 50; ++i)
		if ((i - 2) % 3 == 0)
			++visibleCount;
	cout << visibleCount;
	visibleCount = 50 / 3;
	cout << visibleCount;
	*/
	
	CardSellectionScreen screen ({});
	screen.draw();
	screen.excecute();

	/*LoginScreen screen{120,40,1005 + 200,700 + 200};
	screen.draw();
	screen.execute();*/
	



	/*while (true)
	{
		cout << _getch();
	}*/


	//setup();
	//CardNumberInput a(UIModels::cardNumberInput, 10, 10);
	//cout << std::endl << a.execute();
	//system("pause");
	//ConsoleUtils::ClearScreen();
	//PinInput input{UIModels::pinInput, 10,10};
	//cout << std::endl << input.execute();
	/*Screen screen{UIModels::terminalScreen};
	screen.execute();*/


	//cout << UIModels::terminalScreen.symbols;
	
    /*Screen screen{50,20};
    for (int i = 0; i < 50; i++)
        cout << "0";*/
    /*CardNumberInput a(UIModels::cardNumberInput, 10, 10);
    cout << std::endl << a.execute();
    system("pause");
    ConsoleUtils::ClearScreen();
    PinInput input{UIModels::pinInput, 10,10};
    cout << std::endl << input.execute();*/
    /*Screen screen{UIModels::terminalScreen};
    screen.execute();*/
    //cout << UIModels::terminalScreen.symbols;
    //мануальне видалення не забувати)
 

	//tests();

	//мануальне видалення не забувати)
	DBController::dispose();
}