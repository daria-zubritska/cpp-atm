#include "Label.h"
#include "ConsoleUtils.h"

Label::Label(int xpos, int ypos, std::string text)
{
	this->xpos = xpos;
	this->ypos = ypos;
	this->text = text;
}

void Label::draw()
{
	ConsoleUtils::drawAt(xpos, ypos, text);
}

int Label::getXpos()
{
	return xpos;
}

int Label::getYpos()
{
	return ypos;
}

void Label::setXpos(int xpos)
{
	this->xpos = xpos;
}

void Label::setYpos(int ypos)
{
	this->ypos = ypos;
}

std::string Label::getText()
{
	return text;
}
void Label::setText(std::string text)
{
	this->text = text;
}