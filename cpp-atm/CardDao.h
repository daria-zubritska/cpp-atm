#pragma once

#include <iostream>
#include "sqlite\sqlite3.h"
#include "DBController.h"

using namespace std;

//класс обробки запитів до таблиці CreditCard
class CardDao {
private:

	DBController* _db;

public:

	CardDao(DBController*);

	~CardDao();

	/*
	методи обробки запитів
	*/

};
