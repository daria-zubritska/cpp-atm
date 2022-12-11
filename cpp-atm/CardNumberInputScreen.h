#pragma once
#include "Screen.h"
#include "Label.h"
#include "Window.h"
#include "Menu.h"
#include "CardNumberInput.h"

class CardNumberInputScreen :Screen
{
private:
	std::vector<Window> windows;
	std::vector<Label> labels;
	CardNumberInput input;

public:
	CardNumberInputScreen();
	void draw() override;
	int execute() override;
	std::string getValue();
	void clear() override;
};