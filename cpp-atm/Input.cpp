#pragma once
#include "Input.h"
#include "ConsoleUtils.h"

Input::Input(int xpos, int ypos, int xSize, int ySize, int length) : Control(xpos, ypos, {})
{
	model = Model::generateFrame(xSize, ySize);
	this->length = length;
	buffer = "";
}

void Input::draw()
{
	ConsoleUtils::drawAt(xpos, ypos, model.getRows());
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
		//filter arrows to evade weird input
		if (key == VK_UP || key == VK_DOWN || key == VK_RIGHT || key == VK_LEFT)
			continue;

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