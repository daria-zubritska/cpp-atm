#include "Model.h"
#include "ConsoleUtils.h"
#include <iostream>

class Screen
{
private:
	Model model;


public:
	void update(int pos)
	{
		//{c1x,l1y} {c2x,l1y}
		//{c1x,l2y} {c2x,l2y}
		//{c1x,l3y} {c2x,l3y}
		int c1x{ 2 },c2x{120},l1y{13},l2y{20},l3y{28};
		std::cout << model.symbols;
		switch (pos)
		{
		case 0:
			fillButton(' ', c1x, l1y , false);
			break;
		case 1:
			fillButton(' ', c2x, l1y, true);
			break;
		case 2:
			fillButton(' ', c1x, l2y, false);
			break;
		case 3:
			fillButton(' ', c2x, l2y, true);
			break;
		case 4:
			fillButton(' ', c1x, l3y, false);
			break;
		case 5:
			fillButton(' ', c2x, l3y, true);
			break;
		default:
			break;
		}
	}

	Screen(Model model)
	{
		this->model = model;
	}

	std::string excecute()
	{
		ConsoleUtils::resize({ 200, 200, 1310, 1000 });
		int cursor = 0;
		int buff{ 0 };
		SHORT key{ 0 };
		while (true)
		{
			key = ConsoleUtils::GetKey();
			if (key == VK_RETURN || key == VK_ESCAPE)
			{
				//enter or escape
			}
			else
				buff = cursorChange(cursor, key);
			if (buff != cursor)
			{
				cursor = buff;
				ConsoleUtils::ClearScreen();
				update(cursor);
			}
		}

	}

private:

	void fillButton(char symbol, int xpos, int ypos, bool right)
	{
		int length;
		for (int j = 0; j < 3; ++j)
		{
			ConsoleUtils::setCursorPosition(xpos, ypos +j);
			if (j == 1)
				length = 12;
			else
			{
				length = 11;
				if (right)
					ConsoleUtils::setCursorPosition(xpos+1, ypos + j);
			}

			for (int i = 0; i < length; ++i)
				std::cout << symbol;
		}
	}

	int cursorChange(int currentPos, SHORT key)
	{
		//0 1
		//2 3
		//4 5
		switch (key)
		{
		case VK_RIGHT:
			if (currentPos % 2 == 0)
				return currentPos + 1;
		case VK_LEFT:
			if (currentPos % 2 != 0)
				return currentPos - 1;
		case VK_DOWN:
			if (currentPos < 4)
				return currentPos + 2;
		case VK_UP:
			if (currentPos > 1)
				return currentPos - 2;
		default:
			return currentPos;
			break;
		}
	}
	

};