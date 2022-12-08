#pragma once
#include "PasswordInput.h"
#include "ConsoleUtils.h"

PasswordInput::PasswordInput(int xpos, int ypos, int xSize, int ySize) : Input(xpos, ypos, xSize, ySize, 16) {};

void PasswordInput::addSymbol(SHORT key)
{
	ConsoleUtils::drawAt(xpos + 2 + buffer.length(), ypos + 1, '*');
	buffer += (char)key;
	if (buffer.length() < length)
		ConsoleUtils::setCursorPosition(xpos + 2 + buffer.length(), ypos + 1);
}