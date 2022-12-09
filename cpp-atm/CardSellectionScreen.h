#pragma once
#include "Screen.h"
#include "Window.cpp"
#include "Label.h"
#include "Menu.h"

class CardSellectionScreen : Screen
{
private:
	std::vector<Window> windows;
	std::vector<Label> labels;
	std::vector<Menu> menus;

public:
	CardSellectionScreen(std::vector<std::string> elements);
	//deprecated, will be removed soon
	std::string getSelectedCard();
	//
	int getCursorPosition();
	void draw();
	int execute();
private:
	void init(std::vector<std::string> elements);
};