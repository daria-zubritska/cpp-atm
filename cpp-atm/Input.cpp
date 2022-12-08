#pragma once
#include "Input.h"
#include "ConsoleUtils.h"

Input::Input(int xpos, int ypos, int xSize, int ySize, int length) : Control(xpos, ypos, {})
{
	model = Model::generateFrame(xSize, ySize);
	this->length = length;
	buffer = "";
}

void Input::preExcecute()
{
	ConsoleUtils::setCursorPosition(xpos + 2 + buffer.length(), ypos + 1);
}

int Input::otherInputs(SHORT key)
{
	switch (key)
	{
	case VK_BACK:
		onBack();
		break;
	default:
		if (buffer.length() <= length)
			addSymbol(key);
		break;
	}
	return 0;
}

void Input::onBack()
{
	if (buffer.length() != 0)
		removeSymbol();
}

void Input::addSymbol(SHORT key)
{
	ConsoleUtils::drawAt(xpos + 2 + buffer.length(), ypos + 1, (char)key);
	buffer += (char)key;
	if (buffer.length() < length)
		ConsoleUtils::setCursorPosition(xpos + 2 + buffer.length(), ypos + 1);
}

void Input::removeSymbol()
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