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


AuthDataDao::AuthDataDao() : _db(new DBController()){
    cout << "AuthDataDao created" << endl;
}

AuthDataDao::~AuthDataDao() {
    delete _db;
    cout << "AuthDataDao deleted" << endl;
}


CreditCardDao::CreditCardDao() : _db(new DBController()) {
    cout << "CreditCardDao created" << endl;
}

CreditCardDao::~CreditCardDao() {
    delete _db;
    cout << "CreditCardDao deleted" << endl;
}


DebitCardDao::DebitCardDao() : _db(new DBController()) {
    cout << "DebitCardDao created" << endl;
}

DebitCardDao::~DebitCardDao() {
    delete _db;
    cout << "DebitCardDao deleted" << endl;
}


TransactionDao::TransactionDao() : _db(new DBController()) {
    cout << "TransactionDao created" << endl;
}

TransactionDao::~TransactionDao() {
    delete _db;
    cout << "TransactionDao deleted" << endl;
}