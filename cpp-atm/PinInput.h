#pragma once
#include "Model.h"

class PinInput
{
private:
	Model model;
	int xpos, ypos;
public:
	
	PinInput(Model model, int xpos, int ypos);
	std::string execute();

private:
	int keyToIntValue(SHORT key);
};