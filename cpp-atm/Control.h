#pragma once
#include "UIModels.h"

class Control
{
private:
	int xpos, ypos;
	Model model;
public:
	std::string excecute(){}
	Control(int xpos, int ypos, Model model)
	{
		this->xpos = xpos;
		this->ypos = ypos;
		this->model = model;
	}
};