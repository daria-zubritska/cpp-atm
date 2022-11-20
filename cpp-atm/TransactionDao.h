#pragma once

#include <iostream>
#include "sqlite\sqlite3.h"
#include "DBController.h"
#include "Transaction.h"

using namespace std;

//класс обробки запитів до таблиці Transaction
class TransactionDao {
private:

	DBController* _db;

public:

	Transaction instance(const string& fromCard, const string& toCard, const long double& sum, const string& dateTime);

	TransactionDao(DBController*);

	~TransactionDao();

	Transaction getById(int id);

};