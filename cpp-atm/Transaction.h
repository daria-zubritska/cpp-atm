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
    Transaction() : sum{0.0} {};

    Transaction(const string& fromCard, const string& toCard, const long double& sum, const string& time) :
        fromCard{ fromCard }, toCard{ toCard }, sum{ sum }, time{ time }
    {};

    Transaction(const Transaction& toCopy) :
        fromCard{ toCopy.getFrom() }, toCard{ toCopy.getTo() }, sum{ toCopy.getSum() }, time{ toCopy.getDatetime() }
    {};

    ~Transaction() {};

    string getFrom() const { return fromCard; };
    string getTo() const { return toCard; };
    long double getSum() const { return sum; };
    string getDatetime() const { return time; };


};