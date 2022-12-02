#include "Model.h"
#include "ConsoleUtils.h"
#include <iostream>
#pragma once

class CardNumberInput
{
private:
	Model model;
	int xpos, ypos;
public:

	CardNumberInput(Model model, int xpos, int ypos);

	std::string excecute();

private:
	int keyToIntValue(SHORT key);
};