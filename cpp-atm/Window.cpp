#pragma once
#include <iostream>
#include "Model.h"
#include "UIModels.h"
#include "ConsoleUtils.h"
#include "Control.h"

class Window : Control
{
public:
	Window(int xpos,int ypos,int xsize, int ysize) :Control(xpos,ypos,Model::generateFrame(xsize,ysize))
	{
		
	}

	void draw()
	{
		ConsoleUtils::drawAt(xpos,ypos,model.getRows());
	}
	
};