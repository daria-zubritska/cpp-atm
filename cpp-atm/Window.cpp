#pragma once
#include <iostream>
#include "Model.h"
#include "UIModels.h"
#include "ConsoleUtils.h"
#include "Control.h"

class Window : public Control
{
public:
	Window(int xpos,int ypos,int xsize, int ysize) :Control(xpos,ypos,Model::generateFrame(xsize,ysize))
	{
		
	}

	void draw() override
	{
		ConsoleUtils::drawAt(xpos,ypos,model.getRows());
	}
	
private:
	int execute() override { return 0; };
	int onReturn() override { return 0; };
	int onEscape() override { return 0; };
	int onTab() override { return 0; };
	int onArrows(SHORT key) override { return 0; };
	int otherInputs(SHORT key) override { return 0; };
	void preExcecute() override {};
};