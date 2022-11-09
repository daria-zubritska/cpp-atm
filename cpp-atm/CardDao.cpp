#include <iostream>
#include "sqlite\sqlite3.h"
#include "DBController.h"
#include "CardDao.h"

using namespace std;

CardDao::CardDao(DBController* db) : _db(db) {
    cout << "CardDao created" << endl;
}

CardDao::~CardDao() {
    delete _db;
    cout << "CreditCardDao deleted" << endl;
}

