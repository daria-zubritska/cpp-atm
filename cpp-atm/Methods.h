#pragma once
#include <iostream>
#include "DBController.h"
#include "AuthDataDao.h"
#include "TransactionDao.h"
#include "CardDao.h"
#include "Security.h"

class Methods {
private:

	AuthDataDao adao = AuthDataDao(DBController::getController());
	TransactionDao tdao = TransactionDao(DBController::getController());
	CardDao cdao = CardDao(DBController::getController());

	Security sec = Security();

public:

	bool checkAccount(const string& phone, const string& pass)
	{
		AuthenticationData a = adao.getByPhone(phone);
		return ((a.getPhone() == phone) && (a.getPassword() == sec.encryptPassword(pass)));
	};

	vector<CreditCard> getAllCCards(const string& phone)
	{

		vector<CreditCard> userCCards;

		list<CreditCard> clist = cdao.getAllByUserC(phone, tdao);

		for (CreditCard const& i : clist) {
			userCCards.push_back(i);
		}

		return userCCards;
	};

	vector<DebitCard> getAllDCards(const string& phone)
	{

		vector<DebitCard> userDCards;

		list<DebitCard> dlist = cdao.getAllByUserD(phone, tdao);

		for (DebitCard const& i : dlist) {
			userDCards.push_back(i);
		}

		return userDCards;
	};


	bool insertNewTrans(Transaction& t) {

		return tdao.insertTrans(t);

	};

	vector<Transaction> getAllTransByCard(const string& number) {

		vector<Transaction> tvec;
		list<Transaction> tlist = tdao.getAllByCard(number);


		for (Transaction const& i : tlist) {
			tvec.push_back(i);
		}

		return tvec;
	};

}; 