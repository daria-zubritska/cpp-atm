#include <iostream>
#include "sqlite\sqlite3.h"
#include "DBController.h"
#include "AuthDataDao.h"

using namespace std;

AuthDataDao::AuthDataDao(DBController* db) : _db(db) {
    cout << "AuthDataDao created" << endl;
}

AuthDataDao::~AuthDataDao() {
    delete _db;
    cout << "AuthDataDao deleted" << endl;
}
