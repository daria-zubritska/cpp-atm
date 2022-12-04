#include "Input.h"

Input::Input(int xpos, int ypos, int xSize, int ySize, int length) : Control(xpos, ypos, {})
{
	model = generateFrame(xSize, ySize);
	this->length = length;
	buffer = "";
}

void Input::draw()
{
	ConsoleUtils::drawAt(xpos, ypos, model.getRows());
}

Model Input::generateFrame(int xsize, int ysize)
{
	Model model;
	model.symbols = "";
	for (int j = 0; j < ysize; ++j)
	{
		for (int i = 0; i < xsize; ++i)
		{
			if (i == 0 && j == 0)
			{
				model.symbols += UIModels::windowModel.getRows()[2]; //╔
				continue;
			}

			if (i == 0 && j == ysize - 1)
			{
				model.symbols += UIModels::windowModel.getRows()[3]; //╚
				continue;
			}

			if (i == xsize - 1 && j == 0)
			{
				model.symbols += UIModels::windowModel.getRows()[4]; //╗
				continue;
			}

			if (i == xsize - 1 && j == ysize - 1)
			{
				model.symbols += UIModels::windowModel.getRows()[5]; //╝
				continue;
			}

			if (i == 0 || i == xsize - 1)
			{
				model.symbols += UIModels::windowModel.getRows()[1];//║
				continue;
			}

			if (j == 0 || j == ysize - 1)
			{
				model.symbols += UIModels::windowModel.getRows()[6]; //═
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
int Input::execute()
{
	SHORT key;
	ConsoleUtils::setCursorPosition(xpos + 2 + buffer.length(), ypos + 1);
	while (true)
	{
		key = ConsoleUtils::GetKey();
		
		if (key == VK_TAB)
			return 1;

		if (key == VK_RETURN)
			return 0;

		//idk
		if (key == VK_ESCAPE)
		{
			continue;
		}

		//remove symbol
		if (key == VK_BACK)
		{
			if(buffer.length() != 0)
				removeSymbol(key);
			continue;
		}

		//else, any key, add symbol
		if (buffer.length() <= length)
		{
			addSymbol(key);
			continue;
		}
	}

	return 0;
}

void Input::addSymbol(SHORT key)
{
	ConsoleUtils::drawAt(xpos + 2 + buffer.length(), ypos + 1, (char)key);
	buffer += (char)key;
	if (buffer.length() < length)
		ConsoleUtils::setCursorPosition(xpos + 2 + buffer.length(), ypos + 1);
}

void Input::removeSymbol(SHORT key)
{
	ConsoleUtils::drawAt(xpos + 2 + buffer.size() - 1, ypos + 1, ' ');
	buffer.resize(buffer.length() - 1);
	ConsoleUtils::setCursorPosition(xpos + 2 + buffer.size(), ypos + 1);
}

std::string Input::getBuffer()
{
	return buffer;
}

void Input::clearBuffer()
{
	buffer = "";
}