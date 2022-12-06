#pragma once
#include "ConsoleUtils.h"
#include <winnt.h>
#include "Menu.h"

Menu::Menu(int xpos, int ypos, int xSize,int ySize, std::vector<std::string> elements)
{
	this->xpos = xpos;
	this->ypos = ypos;
	this->model = generateModel(xSize, ySize);
	this->elements = elements;
	for (int i = 0; i < elements.size() && i < labels.size(); ++i)
		labels[i].setText(elements[i]);
}

Model Menu::generateModel(int xsize,int ysize)
{
	Model model;
	model.symbols = "";
	int columnOffcet{ 2 }, elementHeight{ 3 };
	int elementx, elementy;
	visibleCount = (ysize - 2) / 3;
	int c{ 0 };
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
			//sub elements rects

			if (i > columnOffcet && i < xsize - 1 - columnOffcet && j > 0 && j < ysize - 1 && c < visibleCount)
			{
				if ((j - 1) % 3 == 0)
				{
					if (i == columnOffcet + 1)
					{
						model.symbols += UIModels::windowModel.getRows()[2]; //╔
						continue;
					}

					if (i == xsize - 2 - columnOffcet)
					{
						model.symbols += UIModels::windowModel.getRows()[4]; //╗
						continue;
					}

					model.symbols += UIModels::windowModel.getRows()[6]; //═
					continue;
				}

				if ((j % 3) == 0)
				{
					if (i == columnOffcet + 1)
					{
						model.symbols += UIModels::windowModel.getRows()[3]; //╚
						continue;
					}

					if (i == xsize - 2 - columnOffcet)
					{
						model.symbols += UIModels::windowModel.getRows()[5]; //╝
						++c;
						continue;
					}

					model.symbols += UIModels::windowModel.getRows()[6]; //═
					continue;
				}

				if ((j - 2) % 3 == 0)
				{
					if (i == columnOffcet + 1)
					{
						model.symbols += UIModels::windowModel.getRows()[1];//║
						labels.push_back(Label{ i + 4 + xpos,j + ypos,"" });
						continue;
					}

					if (i == xsize - 2 - columnOffcet)
					{
						model.symbols += UIModels::windowModel.getRows()[1];//║
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

int Menu::execute()
{
	int xcursorOffcet{ 2 };
	SHORT key;
	if (cursorPosition == 0)
		drawCursor();
	ConsoleUtils::setCursorPosition(labels[0].getXpos() - xcursorOffcet, labels[0].getYpos());

	while (true)
	{
		key = ConsoleUtils::GetKey();

		if (key == VK_TAB)
		{
			ConsoleUtils::drawAt(labels[cursorPosition - scrollIndex].getXpos() - 2, labels[cursorPosition - scrollIndex].getYpos(), '-');
			return 1;
		}

		if (key == VK_RETURN)
			return 0;

		//idk
		if (key == VK_ESCAPE)
		{
			continue;
		}

		if (key == VK_UP)
		{
			if (cursorPosition != scrollIndex || cursorPosition == 0)
				eraseCursor();
			//move cursor
			--cursorPosition;
			if (cursorPosition == -1)
			{
				cursorPosition = elements.size() - 1;
				scrollIndex = elements.size() - visibleCount;
				for (int i = visibleCount - 1; i >= 0; --i)
				{
					labels[i].setText(elements[i + elements.size() - visibleCount]);
					labels[i].draw();
				}
			}


			if (cursorPosition == scrollIndex-1)
			{
				--scrollIndex;
				//shift up
				for (int i = scrollIndex; i < scrollIndex + visibleCount && i < elements.size(); ++i)
				{
					///TODO: extend value before pushing or modify label??
					labels[i - scrollIndex].setText(elements[i]);
					labels[i - scrollIndex].draw();
				}
			}
			else
				drawCursor();
			continue;
		}

		if (key == VK_DOWN)
		{
			if (cursorPosition != scrollIndex + visibleCount - 1 || cursorPosition == elements.size()-1)
				eraseCursor();

			//move cursor
			++cursorPosition;
			if (cursorPosition == elements.size())
			{
				cursorPosition = 0;
				scrollIndex = 0;
				//shift up
				for (int i = 0; i < labels.size(); ++i)
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
					///TODO: extend value before pushing or modify label??
					labels[i - scrollIndex].setText(elements[i]);
					labels[i - scrollIndex].draw();
				}
			}
			else
				drawCursor();
			continue;
		}

		if (key == VK_RIGHT || key == VK_LEFT)
		{
			continue;
		}
	}

	return 0;
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