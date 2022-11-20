#pragma once
#include<string>;
#include "sqlite/sqlite3.c"
using namespace std;

class AuthenticationData
{

private:

    string phone;
    string password;

public:
    AuthenticationData();

    AuthenticationData(const string& phone, const string& password);

    AuthenticationData(const AuthenticationData& toCopy);

    ~AuthenticationData() {};

    string getFrom() { return phone; }
    string getTo() { return password; }
};