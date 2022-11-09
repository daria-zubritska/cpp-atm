#pragma once

#include <iostream>
#include "sqlite\sqlite3.h"
#include "DBController.h"

using namespace std;

//класс обробки запитів до таблиці Transaction
class TransactionDao {
private:

	DBController* _db;

public:

	TransactionDao(DBController*);

	~TransactionDao();

	/*
	методи обробки запитів
	*/

};