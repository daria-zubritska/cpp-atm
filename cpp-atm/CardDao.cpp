#include <iostream>
#include "sqlite/sqlite3.h"
#include "DBController.h"
#include "CardDao.h"
#include "TransactionDao.h"
#include "Transaction.h"
#include <list>

using namespace std;

CreditCard CardDao::instanceC(const string& number, const string& pin, const string& endDate, const int& cvv, const double& balance, const string& currency, const bool& isActive, const double& credLim)
{
	CreditCard c(number, pin, endDate, cvv, balance, currency, isActive, credLim);
	return c;
}

DebitCard CardDao::instanceD(const string& number, const string& pin, const string& endDate, const int& cvv, const double& balance, const string& currency, const bool& isActive)
{
	DebitCard d(number, pin, endDate, cvv, balance, currency, isActive);
	return d;
}

CardDao::CardDao(DBController* db) : _db(db) {
	cout << "CardDao created" << endl;
}

CardDao::~CardDao() {
	cout << "CreditCardDao deleted" << endl;
}

CreditCard CardDao::getByNumberC(const string& number, TransactionDao tdao)
{
	sqlite3_stmt* stmt;

	sqlite3_prepare_v2(_db->db(), "SELECT * FROM card WHERE number = ?;", -1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, number.c_str(), -1, SQLITE_STATIC);

	if (sqlite3_step(stmt) != SQLITE_DONE) {

		if (sqlite3_column_double(stmt, 6)) {
			return instanceC(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
				sqlite3_column_int(stmt, 3),
				tdao.getBalance(number),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)),
				(sqlite3_column_int(stmt, 5) == 1 ? true : false),
				sqlite3_column_double(stmt, 6));
		}
	}
	return CreditCard();
}

DebitCard CardDao::getByNumberD(const string& number, TransactionDao tdao)
{
	sqlite3_stmt* stmt;

	sqlite3_prepare_v2(_db->db(), "SELECT * FROM card WHERE number = ?;", -1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, number.c_str(), -1, SQLITE_STATIC);

	if (sqlite3_step(stmt) != SQLITE_DONE) {

		if (!sqlite3_column_double(stmt, 6)) {
			return instanceD(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
				sqlite3_column_int(stmt, 3),
				tdao.getBalance(number),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)),
				(sqlite3_column_int(stmt, 5) == 1 ? true : false));
		}
	}
	return DebitCard();
}

list<CreditCard> CardDao::getAllByUserC(const string& phone, TransactionDao tdao)
{
	list<CreditCard> newList = list<CreditCard>();

	sqlite3_stmt* stmt;

	sqlite3_prepare_v2(_db->db(), "SELECT * FROM card WHERE owner = ?;", -1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, phone.c_str(), -1, SQLITE_STATIC);

	while (sqlite3_step(stmt) != SQLITE_DONE) {

		if (sqlite3_column_double(stmt, 6)) {
			newList.push_back(instanceC(
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
				sqlite3_column_int(stmt, 3),
				tdao.getBalance(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)),
				(sqlite3_column_int(stmt, 5) == 1 ? true : false),
				sqlite3_column_double(stmt, 6)));
		}
	}

	return newList;
}

list<DebitCard> CardDao::getAllByUserD(const string& phone, TransactionDao tdao)
{
	list<DebitCard> newList = list<DebitCard>();
	
	sqlite3_stmt* stmt;

	sqlite3_prepare_v2(_db->db(), "SELECT * FROM card WHERE number = ?;", -1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, phone.c_str(), -1, SQLITE_STATIC);

	while (sqlite3_step(stmt) != SQLITE_DONE) {

		if (!sqlite3_column_double(stmt, 6)) {
			newList.push_back(instanceD(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
				sqlite3_column_int(stmt, 3),
				tdao.getBalance(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))),
				reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)),
				(sqlite3_column_int(stmt, 5) == 1 ? true : false)));
		}
	}
	return newList;
}
