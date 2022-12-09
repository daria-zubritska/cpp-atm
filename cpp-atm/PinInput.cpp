#pragma once
#include "PinInput.h"
#include "ConsoleUtils.h"
#include <iostream>
#include "UIModels.h"

PinInput::PinInput(int xpos, int ypos) : Input(xpos, ypos, 18, 3, 4)
{
	this->model = UIModels::pinInput;
}

void PinInput::preExecute()
{	
	ConsoleUtils::drawAt(xpos, ypos, model.getRows());
	ConsoleUtils::setCursorPosition(xpos + 2, ypos + 1);
}

void PinInput::removeSymbol()
{
	ConsoleUtils::setCursorPosition(xpos + 2 + (buffer.size() - 1) * multipliter, ypos + 1);
	buffer.resize(buffer.size() - 1);
	std::cout << " ";
	ConsoleUtils::setCursorPosition(xpos + 2 + (buffer.size()) * multipliter, ypos + 1);
}

void PinInput::addSymbol(SHORT key)
{
	if (key >= 48 && key <= 57 && buffer.size() < 4)
	{
		//can i delete this???
		ConsoleUtils::setCursorPosition(xpos + 2 + (buffer.size()) * multipliter, ypos + 1);
		buffer += std::to_string((keyToIntValue(key)));
		std::cout << keyToIntValue(key);
		if (buffer.size() < 3)
			ConsoleUtils::setCursorPosition(xpos + 2 + (buffer.size()) * multipliter, ypos + 1);
	}
}

int PinInput::keyToIntValue(SHORT key)
{
	return key - 48;
}

int PinInput::onReturn()
{
	if (buffer.size() == length)
		return 0;
	return -1;
}