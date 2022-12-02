#include "Model.h"
#include "ConsoleUtils.h"
#include <iostream>
#pragma once

class PinInput
{
private:
	Model model;
	int xpos, ypos;
public:
	
	PinInput(Model model, int xpos, int ypos);

	std::string excecute();

private:
	int keyToIntValue(SHORT key);
};