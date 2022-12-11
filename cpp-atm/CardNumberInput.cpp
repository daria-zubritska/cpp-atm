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
	if ((int)buffer.size() % 4 == 0)
		ConsoleUtils::setCursorPosition(xpos + 1 + ((int)buffer.size()) + (int)buffer.size() / multipliter * 3 - 3, ypos + 1);
	else
		ConsoleUtils::setCursorPosition(xpos + 1 + ((int)buffer.size()) + (int)buffer.size() / multipliter * 3, ypos + 1);
	buffer.resize((int)buffer.size() - 1);
	std::cout << " ";
	ConsoleUtils::setCursorPosition(xpos + 1 + ((int)buffer.size()) + (int)buffer.size() / multipliter * 3 + 1, ypos + 1);
}

void CardNumberInput::addSymbol(SHORT key)
{
	int multipliter = 4;
	if (key >= 48 && key <= 57 && (int)buffer.size() < length)
	{
		buffer += std::to_string((keyToIntValue(key)));
		std::cout << keyToIntValue(key);
		if ((int)buffer.size() < 15)
			ConsoleUtils::setCursorPosition(xpos + 1 + ((int)buffer.size()) + 1 + (int)buffer.size() / multipliter * 3, ypos + 1);
	}
}

int CardNumberInput::keyToIntValue(SHORT key)
{
	return key - 48;
}

int CardNumberInput::onReturn()
{
	if ((int)buffer.size() == length)
		return 0;
	return -1;
}