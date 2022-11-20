#pragma once

#include"Card.h";

using namespace std;

class Transaction
{

private:
    Card fromCard;
    Card toCard;
    long double sum;
    string time;

public:
    Transaction();

    Transaction(const Card& fromCard, const Card& toCard, const long double& sum, const string& dateTime);

    Transaction(const Transaction& toCopy);

    ~Transaction() {};

    Card getFrom() {return fromCard;}
    Card getTo() { return toCard; }
    long double getSum() {return sum;}
    string getDatetime(){return time;}


};