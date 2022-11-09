#pragma once

#include <iostream>
#include "sqlite\sqlite3.h"
#include "DBController.h"

using namespace std;

//класс обробки запитів до таблиці AuthData
class AuthDataDao {
private:

	DBController* _db;

public:

	AuthDataDao(DBController*);

	~AuthDataDao();

	/*
	методи обробки запитів
	*/

};