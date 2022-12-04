#pragma once
#include "LoginScreen.h"

LoginScreen::LoginScreen(int width, int height, int xSize, int ySize) : Screen(width, height, xSize, ySize)
{
	init();
}

void LoginScreen::init()
{
	int column1{41}, row1{10}, row2{12}, row3{13}, row4{16}, row5{17};
	windows.push_back({ width,height });
	labels.push_back({ column1,row1,"LOGIN" });
	labels.push_back({ column1,row2,"phone number"});
	inputs.push_back({ column1,row3,40,3,10 });
	labels.push_back({ column1,row4,"password" });
	inputs.push_back({ column1,row5,40,3,12 });
}

void LoginScreen::draw()
{
	windows[0].draw();
	labels[0].draw();
	labels[1].draw();
	inputs[0].draw();
	labels[2].draw();
	inputs[1].draw();
}

int LoginScreen::excecute()
{
	int buf;
	while (true)
	{
		inputs[0].execute();
		buf = inputs[1].execute();
		if (buf == 0)
			break;
	}
	return 0;
}

std::string LoginScreen::getLogin()
{
	return inputs[0].getBuffer();
}

std::string LoginScreen::getPassword()
{
	return inputs[1].getBuffer();
}

void LoginScreen::clearInputs()
{
	inputs[0].draw();
	inputs[1].draw();
	inputs[0].clearBuffer();
	inputs[1].clearBuffer();
}