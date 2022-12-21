#pragma once
#include <iostream>
#include <string>

using namespace std;

class Utility {
private:

public:

	static string encryptPassword(const string& pass) {
        unsigned int hash = 0;

        const unsigned int VALUE = (unsigned int)pass.length();
        for (auto Letter : pass)
        {
            srand(VALUE * Letter);
            hash += 33 + rand() % 92;
        }
        return to_string(hash);
	};

};