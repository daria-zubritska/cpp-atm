#pragma once

#include <iostream>
#include "sqlite\sqlite3.h"
#include "DBController.h"
#include "Card.h"
#include "CreditCard.h"
#include "DebitCard.h"

using namespace std;

//класс обробки запитів до таблиці CreditCard
class CardDao {
private:

	DBController* _db;

public:

	CreditCard instanceC(const string& number, const string& pin, const string& endDate, const int& cvv,
		const double& balance, const string& currency, const bool& isActive, const double& credLim);
	DebitCard instanceD(const string& number, const string& pin, const string& endDate, const int& cvv,
		const double& balance, const string& currency, const bool& isActive);

	CardDao(DBController*);

	~CardDao();

	/*
	методи обробки запитів
	*/

};
