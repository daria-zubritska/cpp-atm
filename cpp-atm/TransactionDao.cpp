#include <iostream>
#include "sqlite\sqlite3.h"
#include "DBController.h"
#include "TransactionDao.h"

using namespace std;

//Transaction TransactionDao::instance(const string& fromCard, const string& toCard, const long double& sum, const string& dateTime)
//{
//    return Transaction(fromCard, toCard, sum, dateTime);
//}

TransactionDao::TransactionDao(DBController* db) : _db(db) {
    cout << "TransactionDao created" << endl;
}

TransactionDao::~TransactionDao() {
    delete _db;
    cout << "TransactionDao deleted" << endl;
}

//Transaction TransactionDao::getById(int id)
//{
//    sqlite3_stmt* stmt;
//
//    sqlite3_prepare_v2(_db->db(), "SELECT * FROM transactions WHERE id = ?;", -1, &stmt, NULL);
//    sqlite3_bind_int(stmt, 1, id);
//
//    if (sqlite3_step(stmt) != SQLITE_DONE) {
//
//        return instance(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))),
//            string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2))), sqlite3_column_double(stmt, 3), 
//            string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4))));
//    }
//    return Transaction();
//
//    Transaction t = Transaction();
//
//    return t;
//}