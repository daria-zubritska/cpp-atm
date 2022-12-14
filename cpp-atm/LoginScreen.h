#pragma once
#include "Screen.h"
#include "Window.h"
#include "Label.h"
#include "PasswordInput.h"
#include "PhoneInput.h"

class LoginScreen : public Screen
{
private:
	std::vector<Window> windows;
	
	PhoneInput phoneInput{ 0,0,0,0 };
	PasswordInput passwordInput{ 0,0,0,0 };
	std::vector<Label> labels;
	
public:
	LoginScreen();
	std::string getPassword();
	std::string getLogin();

	void init();
	void clear() override;
	void draw() override;
	int execute() override;
};