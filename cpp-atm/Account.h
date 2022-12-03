#pragma once
#include"UserData.h"
#include"AuthenticationData.h"

class Account
{

private:

    string name;
    AuthenticationData authData;
    UserData userData;

public:
    Account() {};

    Account(const string& name, const AuthenticationData& authData, UserData& userData) :
        name{ name }, authData{ authData }, userData{ userData }
    {};

    Account(const Account& toCopy) :
        name{ toCopy.getName()}, authData{ getAuthenticationData()}, userData{ getUserData()}
    {};

    ~Account() {};

    string getName() const { return name; };
    AuthenticationData getAuthenticationData() const { return authData; };
    UserData getUserData() const { return userData; };

    bool checkAccount(const string& phone, const string& pass);
};