#include <iostream>
#include <fstream>
#include <string>
#include "sqlite\sqlite3.h"
#include "DBController.h"

using namespace std;

void DBController::init()
{
	int exit = 0;
	char* messaggeError;

	exit = sqlite3_exec(_DB, readInit().c_str(), NULL, 0, &messaggeError);

	if (exit != SQLITE_OK) {
		std::cerr << "Error Initiating Database" << std::endl;
		sqlite3_free(messaggeError);
	}
}

string DBController::readInit() {
	fstream newfile;
	string init = "";

	newfile.open("init.txt", ios::in);

	if (newfile.is_open()) {
		string tp;

		while (getline(newfile, tp)) { //read data from file object and put it into string.
			init += tp;
		}
		newfile.close(); //close the file object.
	}

	return init;
}

DBController::DBController() {
	int exit = 0;
	exit = sqlite3_open("atm.db", &_DB);

	if (exit) {
		cout << "Error open DB " << sqlite3_errmsg(_DB) << endl;
		return;
	}
	else {
		cout << "Opened Database Successfully!" << endl;
		init();
	}

}

DBController::~DBController() {

	sqlite3_close(_DB);
	cout << "Database Closed Successfully!" << endl;
}