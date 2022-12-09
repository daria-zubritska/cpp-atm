#pragma once
#include "Screen.h"
#include "Label.h"
#include "Window.cpp"
#include "Menu.h"


class CardNumberInputScreen :Screen
{
private:
	std::vector<Window> windows;
	std::vector<Label> labels;
	std::vector<Menu> menus;

public:
	CardNumberInputScreen();
	void draw() override;
	int execute() override;
	int getValue();
};