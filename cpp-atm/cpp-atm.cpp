#include <iostream>
#include "DBController.h"
#include "AuthDataDao.h"


int main()
{
    DBController* db = new DBController();
    //видалення об'єкту відбувається у деструкторі дао
    AuthDataDao d = AuthDataDao(db);
}
