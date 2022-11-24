#pragma once
#include <iostream>
#include "DBController.h"
#include "AuthDataDao.h"
#include "CardDao.h"
#include <windows.h>
#include "ConsoleUtils.h"
#include "UIModels.h"
#include "Screen.h"

void setup()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    //each symbol ~= 10??
    ConsoleUtils::resize({ 200, 200, 1310, 880 });
    UIModels::loadModels();
}

int main()
{
    setup();
    Screen screen{ UIModels::terminalScreen };
    screen.excecute();
    //cout << UIModels::terminalScreen.symbols;
    //мануальне видалення не забувати)
    /*DBController* db = new DBController();
    
    CardDao d = CardDao(db);
    TransactionDao t = TransactionDao(db);
    string s("0000 0000 0000 0001");
    string s1("0000 0000 0000 0000");

    cout << d.getByNumberC(s, t).getBalance() << endl;
    cout << d.getByNumberD(s1, t).getBalance() << endl;

    delete db;*/
}
