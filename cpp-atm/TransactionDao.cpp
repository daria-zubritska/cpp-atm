#include <iostream>
#include "sqlite/sqlite3.h"
#include "DBController.h"
#include "TransactionDao.h"
#include <list>

using namespace std;

Transaction TransactionDao::instance(const string& fromCard, const string& toCard, const long double& sum, const string& dateTime)
{
	return Transaction(fromCard, toCard, sum, dateTime);
}

TransactionDao::TransactionDao(DBController* db) : _db(db) {
	cout << "TransactionDao created" << endl;
}

TransactionDao::~TransactionDao() {
	cout << "TransactionDao deleted" << endl;
}

Transaction TransactionDao::getById(int id)
{
	sqlite3_stmt* stmt;

	sqlite3_prepare_v2(_db->db(), "SELECT * FROM transactions WHERE id = ?;", -1, &stmt, NULL);
	sqlite3_bind_int(stmt, 1, id);

	if (sqlite3_step(stmt) != SQLITE_DONE) {

		return instance(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
			reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
			sqlite3_column_double(stmt, 3),
			reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
	}
	return Transaction();
}

double TransactionDao::getBalance(const string& number)
{
	double balance = 0;

	sqlite3_stmt* stmt;

	sqlite3_prepare_v2(_db->db(), "SELECT * FROM transactions WHERE card_to = ?;", -1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, number.c_str(), -1, SQLITE_STATIC);

	while (sqlite3_step(stmt) != SQLITE_DONE) {

		balance += sqlite3_column_double(stmt, 3);
	}

	sqlite3_prepare_v2(_db->db(), "SELECT * FROM transactions WHERE card_from = ?;", -1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, number.c_str(), -1, SQLITE_STATIC);

	while (sqlite3_step(stmt) != SQLITE_DONE) {

		balance -= sqlite3_column_double(stmt, 3);
	}

	return balance;
}

list<Transaction> TransactionDao::getAllByCard(const string& number)
{
	list<Transaction> newList = list<Transaction>();

	sqlite3_stmt* stmt;

	sqlite3_prepare_v2(_db->db(), "SELECT * FROM transactions WHERE card_from = ?;", -1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, number.c_str(), -1, SQLITE_STATIC);

	while (sqlite3_step(stmt) != SQLITE_DONE) {

		newList.push_back(instance(
			reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
			reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
			sqlite3_column_double(stmt, 3),
			reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4))));
	}

	sqlite3_prepare_v2(_db->db(), "SELECT * FROM transactions WHERE card_to = ?;", -1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, number.c_str(), -1, SQLITE_STATIC);

	while (sqlite3_step(stmt) != SQLITE_DONE) {

		newList.push_back(instance(
			reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
			reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
			sqlite3_column_double(stmt, 3),
			reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4))));
	}
	return newList;
}

bool TransactionDao::insertTrans(Transaction& t)
{
	sqlite3_stmt* stmt;

	sqlite3_prepare_v2(_db->db(), "INSERT INTO transactions(card_from, card_to, sum_change, date_time) VALUES (?, ?, ?, ?);", -1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, t.getFrom().c_str(), -1, SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, t.getTo().c_str(), -1, SQLITE_STATIC);
	sqlite3_bind_double(stmt, 3, t.getSum());
	sqlite3_bind_text(stmt, 4, t.getDatetime().c_str(), -1, SQLITE_STATIC);

	return sqlite3_step(stmt) == SQLITE_DONE;
}
