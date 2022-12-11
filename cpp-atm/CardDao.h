#pragma once

#include <iostream>
#include "sqlite/sqlite3.h"
#include "DBController.h"
#include "Card.h"
#include "CreditCard.h"
#include "DebitCard.h"
#include "TransactionDao.h"
#include "Transaction.h"
#include <list>

using namespace std;

//класс обробки запитів до таблиці CreditCard
class CardDao {
private:

	DBController* _db;

	CreditCard instanceC(const string& number, const string& pin, const string& endDate, const int& cvv,
		const float& balance, const string& currency, const bool& isActive, const float& credLim);
	DebitCard instanceD(const string& number, const string& pin, const string& endDate, const int& cvv,
		const float& balance, const string& currency, const bool& isActive);

public:

	CardDao(DBController*);

	~CardDao();

	//if one doesn`t return then card is of other type, try second method
	//if both return empty objects then card doesn`t exist
	CreditCard getByNumberC(const string&, TransactionDao);
	DebitCard getByNumberD(const string&, TransactionDao);

	list<CreditCard> getAllByUserC(const string&, TransactionDao);
	list<DebitCard> getAllByUserD(const string&, TransactionDao);
};
