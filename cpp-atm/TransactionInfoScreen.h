#pragma once
#include "Screen.h"
#include "Label.h"
#include "Window.h"
#include "Menu.h"

class TransactionInfoScreen : Screen
{
private:
	std::vector<Window> windows;
	std::vector<Label> labels;

public:
	TransactionInfoScreen(std::vector<std::string>);
	void draw() override;
	int execute() override;
};