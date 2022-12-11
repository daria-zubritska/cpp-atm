#pragma once
#include "Screen.h"
#include "Window.h"
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
	int getCursorPosition();
	void draw() override;
	int execute() override;
private:
	void init(std::vector<std::string> elements);
};