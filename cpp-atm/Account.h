#pragma once
#include"UserData.h";
#include"AuthenticationData.h";

class Account
{

private:

    string name;
    AuthenticationData authData;
    UserData userData;

public:
    Account();

    Account(const string& name, const AuthenticationData& authData, UserData& userData);

    Account(const Account& toCopy);

    ~Account() {};

    string getName() { return name; }
};