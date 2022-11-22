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

    delete db;
}
