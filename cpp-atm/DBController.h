#pragma once

#include <iostream>
#include "sqlite\sqlite3.h"

using namespace std;

//класс що зберігає конекшн з базою даних
class DBController {
private:

	sqlite3* _DB;

public:

	DBController();

	~DBController();

};


//класс обробки запитів до таблиці AuthData
class AuthDataDao {
private:

	DBController* _db;

public:

	AuthDataDao();

	~AuthDataDao();

	/*
	методи обробки запитів
	*/

};

//класс обробки запитів до таблиці CreditCard
class CreditCardDao {
private:

	DBController* _db;

public:

	CreditCardDao();

	~CreditCardDao();

	/*
	методи обробки запитів
	*/

};

//класс обробки запитів до таблиці DebitCard
class DebitCardDao {
private:

	DBController* _db;

public:

	DebitCardDao();

	~DebitCardDao();

	/*
	методи обробки запитів
	*/

};

//класс обробки запитів до таблиці Transaction
class TransactionDao {
private:

	DBController* _db;

public:

	TransactionDao();

	~TransactionDao();

	/*
	методи обробки запитів
	*/

};