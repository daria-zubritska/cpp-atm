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

	std::string getSelectedCard();
	void draw();
	int excecute();
private:
	void init(std::vector<std::string> elements);
};