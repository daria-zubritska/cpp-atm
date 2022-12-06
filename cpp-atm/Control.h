#pragma once
#include "UIModels.h"

class Control
{
protected:
	int xpos, ypos;
	Model model;
public:
	Control(){}
	Control(int xpos, int ypos, Model model)
	{
		this->xpos = xpos;
		this->ypos = ypos;
		this->model = model;
	}

	int execute(){}
	void draw(){}
	
};