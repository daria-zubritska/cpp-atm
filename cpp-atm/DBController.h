#pragma once

#include <iostream>
#include "sqlite/sqlite3.h"

using namespace std;

//класс що зберігає конекшн з базою даних
class DBController {
private:
	sqlite3* _DB;
	static DBController* controller;
	//метод для оновлення бази даних на початку роботи. Використовується лише для тестування та демонстрації можливостей


	string readInit();

	DBController();
	~DBController();
public:
	void init();
	static void dispose();
	static void create();
	static DBController* getController();
	sqlite3* const db() {
		return _DB;
	}
};