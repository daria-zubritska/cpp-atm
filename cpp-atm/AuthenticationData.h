#pragma once
#include <string>
using namespace std;

class AuthenticationData
{

private:

    string phone;
    string password;

public:

    AuthenticationData() {};

    AuthenticationData(const string& phone, const string& password) :
        phone{ phone }, password{ password }
    {};

    AuthenticationData(const AuthenticationData& toCopy) :
        phone{ toCopy.getPhone() }, password{ toCopy.getPassword() }
    {};

    ~AuthenticationData() {};

    string getPhone() const { return phone; };
    string getPassword() const { return password; };

};