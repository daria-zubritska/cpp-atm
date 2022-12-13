#pragma once
#include <iostream>
#include "DBController.h"
#include "AuthDataDao.h"
#include "TransactionDao.h"
#include "CardDao.h"
#include "Utility.h"
#include <ctime>

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

		for (CreditCard const& i : clist)
		{
			userCCards.push_back(i);
		}

		return userCCards;
	};

	vector<DebitCard> getAllDCards(const string& phone)
	{

		vector<DebitCard> userDCards;

		list<DebitCard> dlist = cdao.getAllByUserD(phone, tdao);

		for (DebitCard const& i : dlist)
		{
			userDCards.push_back(i);
		}

		return userDCards;
	};


	Transaction getTransById(int id)
	{
		return tdao.getById(id);
	}


	vector<Transaction> transVector(const string& number)
	{
		vector<Transaction> userTransactions;
		list<Transaction> tlist = tdao.getAllByCard(number);


		for (Transaction const& i : tlist)
		{
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
			auto buf = to_string(i.getSum());
			buf.resize(buf.size() - 4);
			transactionStrings.push_back(to_string(k) + " " + i.getDatetime() + " " + buf);
			k++;
		}

		return transactionStrings;
	};

	vector<Transaction> getAllTransByCard(const string& number)
	{

		vector<Transaction> userTransactions = transVector(number);

		return userTransactions;
	};

	vector<string> getCardInfoByNumber(string& number)
	{
		CreditCard c = cdao.getByNumberC(number, tdao);
		DebitCard d = cdao.getByNumberD(number, tdao);
		vector<string> info = (c.getCvv() != 0) ? c.getCard() : d.getCard();
		return info;
	}

	bool donateOnZSUByNumber(vector<CreditCard>& userCCards, vector<DebitCard>& userDCards, string& number, string sum)
	{

		if (stod(sum) <= 0) return false;

		double lim = 0;
		for (CreditCard& i : userCCards)
		{
			if (i.getNumber() == number)
			{
				lim = i.getBalance() + i.getCredLim();
				if (!i.getIsActive()) return false;
			}
		}

		for (DebitCard& i : userDCards)
		{
			if (i.getNumber() == number)
			{
				lim = i.getBalance();
				if (!i.getIsActive()) return false;
			}
		}

		if (lim - stod(sum) < 0) return false;
		else {

			time_t t = time(0);
			struct tm timeStruct;
			localtime_s(&timeStruct, &t);
			string str = to_string(timeStruct.tm_mday) + '/' + to_string(timeStruct.tm_mon) + '/' + to_string(1900 + timeStruct.tm_year);
			string to = "ZSU";

			return tdao.insertTrans(number, to, stod(sum), str);
		}
	}

	bool newTransaction(vector<CreditCard>& userCCards, vector<DebitCard>& userDCards, string& numberFrom, string& numberTo, string sum)
	{

		if (stod(sum) <= 0) return false;
		if (numberFrom == numberTo) return false;

		bool exists = false;
		double lim = 0;
		for (CreditCard& i : userCCards)
		{
			if (i.getNumber() == numberFrom)
			{
				lim = i.getBalance() + i.getCredLim();
				if (!i.getIsActive()) return false;
			}
			if (i.getNumber() == numberTo) {
				exists = true;
				if (!i.getIsActive()) return false;
			}
		}

		for (DebitCard& i : userDCards)
		{
			if (i.getNumber() == numberFrom)
			{
				lim = i.getBalance();
				if (!i.getIsActive()) return false;
			}
			if (i.getNumber() == numberTo) {
				exists = true;
				if (!i.getIsActive()) return false;
			}
		}

		if (!exists) return exists;

		if (lim - stod(sum) < 0) return false;
		else {

			time_t t = time(0);
			struct tm timeStruct;
			localtime_s(&timeStruct, &t);
			string str = to_string(timeStruct.tm_mday) + '/' + to_string(timeStruct.tm_mon) + '/' + to_string(1900 + timeStruct.tm_year);

			return tdao.insertTrans(numberFrom, numberTo, stod(sum), str);
		}
	}

	bool moneyOut(vector<CreditCard>& userCCards, vector<DebitCard>& userDCards, string& number, string sum)
	{

		if (stod(sum) <= 0) return false;

		double lim = 0;
		for (CreditCard& i : userCCards)
		{
			if (i.getNumber() == number)
			{
				lim = i.getBalance() + i.getCredLim();
				if (!i.getIsActive()) return false;
			}
		}

		for (DebitCard& i : userDCards)
		{
			if (i.getNumber() == number)
			{
				lim = i.getBalance();
				if (!i.getIsActive()) return false;
			}
		}

		if (lim - stod(sum) < 0) return false;
		else {

			time_t t = time(0);
			struct tm timeStruct;
			localtime_s(&timeStruct, &t);
			string str = to_string(timeStruct.tm_mday) + '/' + to_string(timeStruct.tm_mon) + '/' + to_string(1900 + timeStruct.tm_year);
			string to = "";

			return tdao.insertTrans(number, to, stod(sum), str);
		}
	}

	bool moneyIn(vector<CreditCard>& userCCards, vector<DebitCard>& userDCards, string& number, string sum)
	{

		if (stod(sum) <= 0) return false;

		for (CreditCard& i : userCCards)
		{
			if (i.getNumber() == number)
			{
				if (!i.getIsActive()) return false;
			}
		}

		for (DebitCard& i : userDCards)
		{
			if (i.getNumber() == number)
			{
				if (!i.getIsActive()) return false;
			}
		}

		time_t t = time(0);
		struct tm timeStruct;
		localtime_s(&timeStruct, &t);
		string str = to_string(timeStruct.tm_mday) + '/' + to_string(timeStruct.tm_mon) + '/' + to_string(1900 + timeStruct.tm_year);
		string to = "";

		return tdao.insertTrans(to, number, stod(sum), str);

	}

	vector<string> getCardStringsVector(vector<CreditCard>& userCCards, vector<DebitCard>& userDCards)
	{
		vector<string> cardStrings;
		unsigned int j = 1;

		for (CreditCard const& i : userCCards) {
			cardStrings.push_back(to_string(j) + " " + "Credit card" + " " + i.getNumber());
			j++;
		}

		for (DebitCard const& i : userDCards) {
			cardStrings.push_back(to_string(j) + " " + "Debit card" + " " + i.getNumber());
			j++;
		}

		return cardStrings;
	}

	vector<string> getCardNumbersVector(vector<CreditCard>& userCCards, vector<DebitCard>& userDCards)
	{
		vector<string> cardNumbers;
		unsigned int j = 1;

		for (CreditCard const& i : userCCards)
		{
			cardNumbers.push_back(i.getNumber());
			j++;
		}

		for (DebitCard const& i : userDCards)
		{
			cardNumbers.push_back(i.getNumber());
			j++;
		}

		return cardNumbers;
	}




};