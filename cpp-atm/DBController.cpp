#include <iostream>
#include "sqlite\sqlite3.h"
#include "DBController.h"

using namespace std;

DBController::DBController() {
    int exit = 0;
    exit = sqlite3_open("atm.db", &_DB);

    if (exit) {
        cout << "Error open DB " << sqlite3_errmsg(_DB) << endl;
        return;
    }
    else
        cout << "Opened Database Successfully!" << endl;
}

DBController::~DBController() {
    sqlite3_close(_DB);
    cout << "Database Closed Successfully!" << endl;
}
