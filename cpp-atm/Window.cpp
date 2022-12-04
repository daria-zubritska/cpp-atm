#pragma once
#include <iostream>
#include "Model.h"
#include "UIModels.h"

class Window
{
private:
	int xsize, ysize;
public:
	Window(int xsize, int ysize)
	{
		this->xsize = xsize;
		this->ysize = ysize;
	}

	void draw()
	{
		for (int j = 0; j < ysize; ++j)
		{
			for (int i = 0; i < xsize; ++i)
			{
				if (i == 0 && j == 0)
				{
					std::cout << UIModels::windowModel.getRows()[2]; //╔
					continue;
				}

				if (i == 0 && j == ysize - 1)
				{
					std::cout << UIModels::windowModel.getRows()[3]; //╚
					continue;
				}

				if (i == xsize - 1 && j == 0)
				{
					std::cout << UIModels::windowModel.getRows()[4]; //╗
					continue;
				}

				if (i == xsize - 1 && j == ysize - 1)
				{
					std::cout << UIModels::windowModel.getRows()[5]; //╝
					continue;
				}

				if (i == 0 || i == xsize - 1)
				{
					std::cout << UIModels::windowModel.getRows()[1];//║
					continue;
				}

				if (j == 0 || j == ysize - 1)
				{
					std::cout << UIModels::windowModel.getRows()[6]; //═
					continue;
				}

				std::cout << ' ';
			}
			std::cout << '\n';
		}
	}
	
};