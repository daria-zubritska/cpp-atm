#pragma once
#include <iostream>
#include "Model.h"
#include "UIModels.h"
#include "ConsoleUtils.h"
#include "Control.h"

class Window : public Control
{
public:
	Window(int xpos, int ypos, int xsize, int ysize);
	void draw() override;
private:
	int execute() override;
	int onReturn() override;
	int onEscape() override;
	int onTab() override;
	int onArrows(SHORT key) override;
	int otherInputs(SHORT key) override;
	void preExecute() override;
};