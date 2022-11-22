#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "sqlite/sqlite3.h"
#include "DBController.h"

using namespace std;

void DBController::init()
{
	ifstream newfile;

	int exit = 0;
	char* messaggeError;

	newfile.open("init.txt", ios::in);

	if (newfile.is_open()) {
		string tp;

		while (getline(newfile, tp)) { //read data from file object and put it into string.

			exit = sqlite3_exec(_DB, tp.data(), NULL, 0, &messaggeError);

			if (exit != SQLITE_OK) {
				cout << tp << endl;

				cerr << "Error Initiating Database" << endl;
				sqlite3_free(messaggeError);
			}
		}
		newfile.close(); //close the file object.
	}
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