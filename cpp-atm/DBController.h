#pragma once

#include <iostream>
#include "sqlite\sqlite3.h"

using namespace std;

class DBController {
private:

	sqlite3* _DB;

public:

	DBController();

	~DBController();

	/*
	методи для роботи з таблицями
	*/

};