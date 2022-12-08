#pragma once
#include "Model.h"
class VirtualControl
{
protected:
	int xpos, ypos;
	Model model;
public:
	virtual int execute() = 0;
	virtual void draw() = 0;

	virtual int onReturn() = 0;
	virtual int onEscape() = 0;
	virtual int onTab() = 0;
	virtual int onArrows(SHORT key) = 0;
	virtual int otherInputs(SHORT key) = 0;
	virtual void preExcecute() = 0;
};