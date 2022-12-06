#include <iostream>
#include "sqlite/sqlite3.h"
#include "DBController.h"
#include "AuthDataDao.h"

using namespace std;

AuthenticationData AuthDataDao::instance(const string& phone, const string& password)
{
	return AuthenticationData(phone, password);
}

AuthDataDao::AuthDataDao(DBController* db) : _db(db) {
	//cout << "AuthDataDao created" << endl;
}

AuthDataDao::~AuthDataDao() {
	//cout << "AuthDataDao deleted" << endl;
}

AuthenticationData AuthDataDao::getByPhone(const string& phone)
{
	sqlite3_stmt* stmt;
	
	sqlite3_prepare_v2(_db->db(), "SELECT * FROM auth_data WHERE phone = ?;", -1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, phone.c_str(), -1, SQLITE_STATIC);

	if (sqlite3_step(stmt) != SQLITE_DONE) {
		return instance(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)), reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
	}
	return AuthenticationData();
}
