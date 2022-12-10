#pragma once
#include <iostream>
#include "DBController.h"
#include "AuthDataDao.h"
#include "TransactionDao.h"
#include "CardDao.h"
#include "Utility.h"

class Methods {
private:

	AuthDataDao adao = AuthDataDao(DBController::getController());
	TransactionDao tdao = TransactionDao(DBController::getController());
	CardDao cdao = CardDao(DBController::getController());

public:

	bool checkAccount(const string& phone, const string& pass)
	{
		AuthenticationData a = adao.getByPhone(phone);
		return ((a.getPhone() == phone) && (a.getPassword() == Utility::encryptPassword(pass)));
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


	bool insertNewTrans(Transaction& t) 
	{

		return tdao.insertTrans(t);

	};

	Transaction getTransById(int id)
	{
		return tdao.getById(id);
	}


	vector<Transaction> transVector(const string& number)
	{
		vector<Transaction> userTransactions;
		list<Transaction> tlist = tdao.getAllByCard(number);


		for (Transaction const& i : tlist) {
			userTransactions.push_back(i);
		}
		return userTransactions;
	}

	vector<string> getAllTransStringsByCard(const string& number) 
	{

		vector<string> transactionStrings;
		unsigned int k = 1;

		for (Transaction const& i : transVector(number))
		{
			transactionStrings.push_back(to_string(k) + " " + i.getDatetime() + " " + to_string(i.getSum()));
			k++;
		}

		return transactionStrings;
	};

	vector<Transaction> getAllTransByCard(const string& number)
	{

		vector<Transaction> userTransactions = transVector(number);

		return userTransactions;
	};

	vector<string> getCardInfoByNumber(vector<CreditCard>& userCCards, vector<DebitCard>& userDCards, string& number)
	{
		vector<string> info;
		for (CreditCard& i : userCCards) {
			if (i.getNumber() == number)
			{
				info = i.getCard();
			}
		}

		for (DebitCard& i : userDCards) {
			if (i.getNumber() == number)
			{
				info = i.getCard();
			}
		}
		return info;
	}

	void donateOnZSUByNumber(vector<CreditCard>& userCCards, vector<DebitCard>& userDCards, string& number, string sum)
	{
		for (CreditCard& i : userCCards) {
			if (i.getNumber() == number)
			{
				i.DonateOnZSU(stold(sum));
			}
		}

		for (DebitCard& i : userDCards) {
			if (i.getNumber() == number)
			{
				i.DonateOnZSU(stold(sum));
			}
		}
	}




}; 