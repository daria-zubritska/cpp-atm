#pragma once
#include "Model.h"
#include "ConsoleUtils.h"
#include <iostream>
#include <functional>
#include <vector>
#include "Control.h"
class Screen
{
protected:
	int width, height;
	std::vector<Control> controls;
public:
	Screen(int width, int height, int xSize, int ySize)
	{
		ConsoleUtils::resize(RECT{ 200,200,xSize,ySize });
		this->width = width;
		this->height = height;
	}
};