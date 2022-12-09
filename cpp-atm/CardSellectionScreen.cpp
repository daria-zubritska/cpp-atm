#pragma once
#include "CardSellectionScreen.h"

CardSellectionScreen::CardSellectionScreen(std::vector<std::string> elements) : Screen(120, 40, 1005 + 200, 700 + 200)
{
	init(elements);
}
//deprecated 
std::string CardSellectionScreen::getSelectedCard()
{
	return menus[0].getElements()[menus[0].getCursorPosition()];
}

int CardSellectionScreen::getCursorPosition()
{
	return menus[0].getCursorPosition();
}

void CardSellectionScreen::init(std::vector<std::string> elements)
{
	windows.push_back({ 0,0,width,height });
	//windows.push_back({41,9,})
	labels.push_back({ 41,5,"SELECT CARD" });
	menus.push_back({ 41,6,40,20,elements });
	
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