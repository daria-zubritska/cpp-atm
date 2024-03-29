﻿#pragma once
#include "ConsoleUtils.h"
#include <winnt.h>
#include "Menu.h"

const int xCursorOffcet{ 2 };

Menu::Menu(int xpos, int ypos, int xSize, int ySize, std::vector<std::string> elements) : Control(xpos, ypos, {})
{
	this->elements = elements;
	this->model = generateModel(xSize,ySize);
	for (int i = 0; i < elements.size() && i < labels.size(); ++i)
		labels[i].setText(elements[i]);
}

Model Menu::generateModel(int xsize,int ysize)
{
	Model model;
	model.symbols = "";
	int columnOffcet{ 2 }, elementHeight{ 3 };
	visibleCount = (ysize - 2) / 3;
	int c{ 0 };
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
			//sub elements rects

			if (i > columnOffcet && i < xsize - 1 - columnOffcet && j > 0 && j < ysize - 1 && c < visibleCount)
			{
				if ((j - 1) % 3 == 0)
				{
					if (i == columnOffcet + 1)
					{
						model.symbols += ConsoleUtils::getFrameSymbols()[1]; //╔
						continue;
					}

					if (i == xsize - 2 - columnOffcet)
					{
						model.symbols += ConsoleUtils::getFrameSymbols()[3]; //╗
						continue;
					}

					model.symbols += ConsoleUtils::getFrameSymbols()[5]; //═
					continue;
				}

				if ((j % 3) == 0)
				{
					if (i == columnOffcet + 1)
					{
						model.symbols += ConsoleUtils::getFrameSymbols()[2]; //╚
						continue;
					}

					if (i == xsize - 2 - columnOffcet)
					{
						model.symbols += ConsoleUtils::getFrameSymbols()[4]; //╝
						++c;
						continue;
					}

					model.symbols += ConsoleUtils::getFrameSymbols()[5]; //═
					continue;
				}

				if ((j - 2) % 3 == 0)
				{
					if (i == columnOffcet + 1)
					{
						model.symbols += ConsoleUtils::getFrameSymbols()[0];//║
						labels.push_back(Label{ i + 4 + xpos,j + ypos,"" });
						continue;
					}

					if (i == xsize - 2 - columnOffcet)
					{
						model.symbols += ConsoleUtils::getFrameSymbols()[0];//║
						continue;
					}
					model.symbols += ' ';
					continue;
				}
			}
			else
				model.symbols += ' ';
		}
		model.symbols += '\n';
	}
	model.width = xsize;
	model.height = ysize;
	return model;

}

int Menu::onTab()
{
	ConsoleUtils::drawAt(labels[cursorPosition - scrollIndex].getXpos() - 2, labels[cursorPosition - scrollIndex].getYpos(), '-');
	return 1;
}

int Menu::onArrows(SHORT key)
{
	switch (key)
	{
	case VK_UP:
		if ((cursorPosition != scrollIndex || cursorPosition == 0) && elements.size() != 1)
			eraseCursor();
		//move cursor
		--cursorPosition;
		if (cursorPosition == -1)
		{
			cursorPosition = (int)elements.size() - 1;
			scrollIndex = (int)elements.size() - visibleCount;
			if (scrollIndex < 0)
			{
				scrollIndex = 0;
				cursorPosition = (int)elements.size() - 1;
			}
			else
			{
				int buf = (int)elements.size() < visibleCount ? (int)elements.size() - 1 : visibleCount - 1;
				for (int i = buf; i >= 0; --i)
				{
					labels[i].setText(elements[i + (int)elements.size() - buf - 1]);
					labels[i].draw();
				}
			}
		}


		if (cursorPosition == scrollIndex - 1)
		{
			--scrollIndex;
			//shift up
			for (int i = scrollIndex; i < scrollIndex + visibleCount && i < elements.size(); ++i)
			{
				labels[i - scrollIndex].setText(elements[i]);
				labels[i - scrollIndex].draw();
			}
		}
		else
			if (elements.size() > 1)
				drawCursor();
		return 0;
		break;
	case VK_DOWN:
		if ((cursorPosition != scrollIndex + visibleCount - 1 || cursorPosition == elements.size() - 1) && elements.size() != 1)
			eraseCursor();

		//move cursor
		++cursorPosition;
		if (cursorPosition == elements.size())
		{
			cursorPosition = 0;
			scrollIndex = 0;
			//shift up
			for (int i = 0; i < labels.size() && i < elements.size(); ++i)
			{
				labels[i].setText(elements[i]);
				labels[i].draw();
			}
		}

		if (cursorPosition == scrollIndex + visibleCount)
		{
			++scrollIndex;
			//shift down
			for (int i = scrollIndex; i < scrollIndex + visibleCount && i < elements.size(); ++i)
			{
				labels[i - scrollIndex].setText(elements[i]);
				labels[i - scrollIndex].draw();
			}
		}
		else
			drawCursor();
		return 0;
		break;
	}
	return -1;
}

void Menu::preExecute()
{
	drawCursor();
	ConsoleUtils::setCursorPosition(labels[0].getXpos() - xCursorOffcet, labels[0].getYpos());
}

void Menu::resetCursor()
{
	this->cursorPosition = 0;
}

int Menu::getCursorPosition()
{
	return cursorPosition;
}

void Menu::draw()
{
	drawCursor();
	ConsoleUtils::drawAt(xpos, ypos, model.getRows());
	for (int i = 0; i < labels.size(); ++i)
		labels[i].draw();
}

void Menu::eraseCursor()
{
	int xcursorOffcet{ 2 };
	ConsoleUtils::drawAt(labels[cursorPosition - scrollIndex].getXpos() - xcursorOffcet, labels[cursorPosition - scrollIndex].getYpos(), ' ');
}

void Menu::drawCursor()
{
	int xcursorOffcet{ 2 };
	ConsoleUtils::drawAt(labels[cursorPosition - scrollIndex].getXpos() - xcursorOffcet, labels[cursorPosition - scrollIndex].getYpos(), '>');
}

std::vector<std::string> Menu::getElements()
{
	return elements;
}