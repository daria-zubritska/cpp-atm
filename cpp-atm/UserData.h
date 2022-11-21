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
    UserData() {};

    UserData(vector<Card>& userCards, vector<Transaction>& userTransactions) :
        userCards{ userCards }, userTransactions{ userTransactions }
    {};

    UserData(const UserData& toCopy) :
        userCards{ toCopy.getCards()}, userTransactions{ toCopy.getTransactions()}
    {};

    ~UserData() {};

    vector<Card> getCards() const { return userCards; };
    vector<Transaction> getTransactions() const { return userTransactions; };
};