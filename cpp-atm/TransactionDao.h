#pragma once

#include <iostream>
#include "sqlite/sqlite3.h"
#include "DBController.h"
#include "Transaction.h"

using namespace std;

//класс обробки запитів до таблиці Transaction
class TransactionDao {
private:

	DBController* _db;

	Transaction instance(const string& fromCard, const string& toCard, const long double& sum, const string& dateTime);

public:

	TransactionDao(DBController*);

	~TransactionDao();

	//NULL where number should be - means the money are from or going to the "real world"
	Transaction getById(int id);

	double getBalance(const string& number);
};