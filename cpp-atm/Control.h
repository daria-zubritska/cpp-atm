#pragma once
#include "Model.h"


#include "IExecutable.h"
#include "IDrawable.h"

class Control : public IExcecutable,public IDrawable
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
	virtual int execute() override;
	virtual void draw() override;
protected:
	virtual int onReturn();
	virtual int onEscape();
	virtual int onTab();
	virtual int onArrows(SHORT key);
	virtual int otherInputs(SHORT key);
	virtual void preExecute();
};