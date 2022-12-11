#pragma once
#include "CardSellectionScreen.h"

CardSellectionScreen::CardSellectionScreen(std::vector<std::string> elements) : Screen(120, 40, 1005 + 200, 700 + 200)
{
	init(elements);
}

int CardSellectionScreen::getCursorPosition()
{
	return menus[0].getCursorPosition();
}

void CardSellectionScreen::init(std::vector<std::string> elements)
{
	windows.push_back({ 0,0,width,height });
	labels.push_back({ 31,5,"SELECT CARD" });
	menus.push_back({ 31,6,60,20,elements });
}

void CardSellectionScreen::draw()
{
	windows[0].draw();
	labels[0].draw();
	menus[0].draw();
}

int CardSellectionScreen::execute()
{
	return menus[0].execute();
}

