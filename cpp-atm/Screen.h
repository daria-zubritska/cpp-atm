#pragma once
#include "Model.h"
#include "ConsoleUtils.h"
#include <iostream>
#include <functional>
#include <vector>
#include "Control.h"
#include "IExecutable.h"
#include "IDrawable.h"

class Screen : public IExcecutable, public IDrawable
{
protected:
	int width, height;
public:
	Screen(int width, int height, int xSize, int ySize)
	{
		ConsoleUtils::resize(RECT{ 200,200,xSize,ySize });
		this->width = width;
		this->height = height;
	}
};