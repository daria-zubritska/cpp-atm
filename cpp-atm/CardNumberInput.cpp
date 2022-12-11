#pragma once
#include "CardNumberInput.h"
#include "UIModels.h"


CardNumberInput::CardNumberInput(int xpos, int ypos) : Input(xpos,ypos,30,3,16)
{
	model = UIModels::cardNumberInput;
}

void CardNumberInput::preExecute()
{
	ConsoleUtils::drawAt(xpos, ypos, model.getRows());
	ConsoleUtils::setCursorPosition(xpos + 2, ypos + 1);
}

void CardNumberInput::removeSymbol()
{
	if (buffer.size() % 4 == 0)
		ConsoleUtils::setCursorPosition(xpos + 1 + (buffer.size()) + buffer.size() / multipliter * 3 - 3, ypos + 1);
	else
		ConsoleUtils::setCursorPosition(xpos + 1 + (buffer.size()) + buffer.size() / multipliter * 3, ypos + 1);
	buffer.resize(buffer.size() - 1);
	std::cout << " ";
	ConsoleUtils::setCursorPosition(xpos + 1 + (buffer.size()) + buffer.size() / multipliter * 3 + 1, ypos + 1);
}

void CardNumberInput::addSymbol(SHORT key)
{
	int multipliter = 4;
	if (key >= 48 && key <= 57 && buffer.size() < length)
	{
		buffer += std::to_string((keyToIntValue(key)));
		std::cout << keyToIntValue(key);
		if (buffer.size() < 15)
			ConsoleUtils::setCursorPosition(xpos + 1 + (buffer.size()) + 1 + buffer.size() / multipliter * 3, ypos + 1);
	}
}

int CardNumberInput::keyToIntValue(SHORT key)
{
	return key - 48;
}

int CardNumberInput::onReturn()
{
	if (buffer.size() == length)
		return 0;
	return -1;
}