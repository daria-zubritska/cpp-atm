#pragma once
#include "PinInput.h"
#include "ConsoleUtils.h"
#include <iostream>

PinInput::PinInput(Model model, int xpos, int ypos)
{
	this->model = model;
	this->xpos = xpos;
	this->ypos = ypos;
}

std::string PinInput::execute()
{
	std::string buf = "";
	SHORT key{ 0 };

	ConsoleUtils::drawAt(xpos, ypos, model.getRows());
	ConsoleUtils::setCursorPosition(xpos + 2, ypos + 1);
	int multipliter = 4;

	while (true)
	{
		key = ConsoleUtils::GetKey();

		if (key >= 48 && key <= 57 && buf.size() < 4)
		{
			//can i delete this???
			ConsoleUtils::setCursorPosition(xpos + 2 + (buf.size()) * multipliter, ypos + 1);
			buf += std::to_string((keyToIntValue(key)));
			std::cout << keyToIntValue(key);
			if(buf.size() < 3)
				ConsoleUtils::setCursorPosition(xpos + 2 + (buf.size()) * multipliter, ypos + 1);
		}

		if (key == VK_RETURN && buf.length() == 4)
			return buf;

		if (key == VK_ESCAPE)
		{
			//escape???
		}

		if (key == VK_BACK && buf.length() != 0)
		{
			ConsoleUtils::setCursorPosition(xpos + 2 + (buf.size() - 1) * multipliter, ypos + 1);
			buf.resize(buf.size() - 1);
			std::cout << " ";
			ConsoleUtils::setCursorPosition(xpos + 2 + (buf.size()) * multipliter, ypos + 1);
		}
	}
	return buf;
}

int PinInput::keyToIntValue(SHORT key)
{
	return key - 48;
}