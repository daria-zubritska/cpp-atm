#include <iostream>
#include "DBController.h"
#include "AuthDataDao.h"
#include "CardDao.h"

int main()
{
    //мануальне видалення не забувати)
    DBController* db = new DBController();
    
    CardDao d = CardDao(db);
    TransactionDao t = TransactionDao(db);
    string s("0000 0000 0000 0001");
    string s1("0000 0000 0000 0000");

    cout << d.getByNumberC(s, t).getBalance() << endl;
    cout << d.getByNumberD(s1, t).getBalance() << endl;

    delete db;
}
