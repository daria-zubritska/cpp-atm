#pragma once
#include"Card.h";
#include"Transaction.h";
#include<vector>;
#include "sqlite/sqlite3.c"
using namespace std;

class UserData
{

private:
    vector<Card> userCards;
    vector<Transaction> userTransactions;

public:
    UserData();

    UserData(vector<Card>& userCards, vector<Transaction>& userTransactions);

    UserData(const UserData& toCopy);

    ~UserData() {};

    vector<Card> getCards() { return userCards; }
    vector<Transaction> getTransactions() { return userTransactions; }
};