#pragma once

#include <iostream>
#include "sqlite/sqlite3.h"

using namespace std;

//класс що зберігає конекшн з базою даних
class DBController {
private:

	sqlite3* _DB;
	static DBController* controller;

	DBController();
	~DBController();

	//метод для оновлення бази даних на початку роботи. Використовується лише для тестування та демонстрації можливостей
	void init();

public:

	static void dispose();
	static DBController* getController();

	sqlite3* const db() const {
		return _DB;
	}

};