#pragma once

#include <iostream>
#include "sqlite\sqlite3.h"
#include "DBController.h"
#include "AuthenticationData.h"

using namespace std;

//класс обробки запитів до таблиці AuthData
class AuthDataDao {
private:

	DBController* _db;

public:

	AuthenticationData instance(const string& phone, const string& password);

	AuthDataDao(DBController*);

	~AuthDataDao();

	/*
	методи обробки запитів
	*/

};