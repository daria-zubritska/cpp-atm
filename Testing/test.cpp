#include "pch.h"
#include "../cpp-atm/DBController.h"
#include "../cpp-atm/CardDao.h"
#include "../cpp-atm/TransactionDao.h"
#include "../cpp-atm/AuthDataDao.h"
#include "../cpp-atm/Transaction.h"
#include "../cpp-atm/CreditCard.h"
#include "../cpp-atm/DebitCard.h"


TEST(TransactionGetByIdTest, correctInfo) {
	DBController* db = new DBController();
	TransactionDao td(db);

	Transaction t = td.getById(0);

	EXPECT_TRUE(t.getFrom().length() == 0);
	EXPECT_EQ(t.getTo(), "0000 0000 0000 0000");
	EXPECT_EQ(t.getSum(), 5000.0);
	EXPECT_EQ(t.getDatetime(), "12/11/2022");

	delete db;
}

TEST(CardGetByNumberTest, correctInfo) {
	DBController* db = new DBController();
	TransactionDao td(db);
	CardDao cd(db);

	CreditCard c = cd.getByNumberC("0000 0000 0000 0000", td);
	DebitCard d = cd.getByNumberD("0000 0000 0000 0000", td);

	EXPECT_TRUE(c.getNumber().length() == 0);
	EXPECT_TRUE(d.getNumber().length() != 0);

	EXPECT_EQ(d.getNumber(), "0000 0000 0000 0000");
	EXPECT_EQ(d.getPin(), "1111");
	EXPECT_EQ(d.getCvv(), 111);
	EXPECT_EQ(d.getEndDate(), "10/24");
	EXPECT_EQ(d.getCurrency(), "UAH");
	EXPECT_EQ(d.getBalance(), 2000.0);
	EXPECT_TRUE(d.getIsActive());

	delete db;
}