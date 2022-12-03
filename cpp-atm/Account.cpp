#include "Account.h"
#include "AuthDataDao.h"
#include "Userdata.h"
#include "TransactionDao.h"
#include "CardDao.h"


AuthDataDao adao = AuthDataDao(DBController::getController());
TransactionDao tdao = TransactionDao(DBController::getController());
CardDao cdao = CardDao(DBController::getController());

bool Account::checkAccount(const string& phone, const string& pass)
{
	return ((adao.getByPhone(phone).getPhone() == phone) && (adao.getByPhone(phone).getPassword() == pass));
}

UserData UserData::getUserData(const string& phone)
{
	vector<Card> userCards;
	list<Card> clist = cdao.getAllByUserC(phone, tdao);
	//UserData data = UserData( , );
}
