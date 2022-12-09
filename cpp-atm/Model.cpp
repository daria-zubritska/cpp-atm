#pragma once
#include "Model.h"
#include <iostream>
#include "ConsoleUtils.h"

std::vector<std::string> Model::getRows()
{
	std::vector<std::string> out;
	std::string buf = "";

	for (int i = 0; i < symbols.length(); ++i)
	{

		if (symbols[i] == '\n')
		{
			out.push_back(buf);
			buf = "";
		}
		else
			buf += symbols[i];
	}
	return out;
}

Model Model::generateFrame(int xsize, int ysize)
{
	Model model;
	model.symbols = "";

	for (int j = 0; j < ysize; ++j)
	{
		for (int i = 0; i < xsize; ++i)
		{
			if (i == 0 && j == 0)
			{
				model.symbols += ConsoleUtils::getFrameSymbols()[1]; //╔
				continue;
			}

			if (i == 0 && j == ysize - 1)
			{
				model.symbols += ConsoleUtils::getFrameSymbols()[2]; //╚
				continue;
			}

			if (i == xsize - 1 && j == 0)
			{
				model.symbols += ConsoleUtils::getFrameSymbols()[3]; //╗
				continue;
			}

			if (i == xsize - 1 && j == ysize - 1)
			{
				model.symbols += ConsoleUtils::getFrameSymbols()[4]; //╝
				continue;
			}

			if (i == 0 || i == xsize - 1)
			{
				model.symbols += ConsoleUtils::getFrameSymbols()[0];//║
				continue;
			}

			if (j == 0 || j == ysize - 1)
			{
				model.symbols += ConsoleUtils::getFrameSymbols()[5]; //═
				continue;
			}

			model.symbols += ' ';
		}
		model.symbols += '\n';
	}
	model.width = xsize;
	model.height = ysize;
	return model;
}