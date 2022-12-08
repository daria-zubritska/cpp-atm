#pragma once
#include "LoginScreen.h"
#include "PasswordInput.h"

LoginScreen::LoginScreen() : Screen(120, 40, 1005 + 200, 700 + 200)
{
	init();
}

void LoginScreen::init()
{
	int column1{41}, row1{10}, row2{12}, row3{13}, row4{16}, row5{17};
	windows.push_back({ 0,0,width,height });
	labels.push_back({ column1,row1,"LOGIN" });
	labels.push_back({ column1,row2,"phone number"});
	phoneInput = PhoneInput{ column1,row3,40,3 };
	labels.push_back({ column1,row4,"password" });
	passwordInput = PasswordInput{ column1,row5,40,3 };
}

void LoginScreen::draw()
{
	windows[0].draw();
	labels[0].draw();
	labels[1].draw();
	phoneInput.draw();
	labels[2].draw();
	passwordInput.draw();
}

int LoginScreen::execute()
{
	int buf;
	while (true)
	{
		phoneInput.execute();
		buf = passwordInput.execute();
		if (buf == 0)
			break;
	}
	return 0;
}

std::string LoginScreen::getLogin()
{
	return phoneInput.getBuffer();
}

std::string LoginScreen::getPassword()
{
	return passwordInput.getBuffer();
}

void LoginScreen::clearInputs()
{
	phoneInput.clearBuffer();
	passwordInput.clearBuffer();
	phoneInput.draw();
	passwordInput.draw();
}