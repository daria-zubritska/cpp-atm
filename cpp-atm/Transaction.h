#pragma once

#include "Card.h";

using namespace std;

class Transaction
{

private:
    string fromCard;
    string toCard;
    long double sum;
    string time;

public:
    Transaction();

    Transaction(const string& fromCard, const string& toCard, const long double& sum, const string& dateTime);

    Transaction(const Transaction& toCopy);

    ~Transaction() {};

    string getFrom() {return fromCard;}
    string getTo() { return toCard; }
    long double getSum() {return sum;}
    string getDatetime(){return time;}


};