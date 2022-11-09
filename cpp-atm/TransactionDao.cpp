#include <iostream>
#include "sqlite\sqlite3.h"
#include "DBController.h"
#include "TransactionDao.h"

using namespace std;

TransactionDao::TransactionDao(DBController* db) : _db(db) {
    cout << "TransactionDao created" << endl;
}

TransactionDao::~TransactionDao() {
    delete _db;
    cout << "TransactionDao deleted" << endl;
}