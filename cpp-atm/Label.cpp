#include "Label.h"
#include "ConsoleUtils.h"

Label::Label(int xpos, int ypos,int length, std::string text)
{
	this->length = length;
	this->xpos = xpos;
	this->ypos = ypos;
	this->text = text;
}

Label::Label(int xpos, int ypos, std::string text) : Label(xpos, ypos, 0, text)
{}

void Label::draw()
{
	std::string buf = text;
	for (int i = 0; i < length; ++i)
		if (i >= text.size())
			buf += ' ';
	ConsoleUtils::drawAt(xpos, ypos, buf);
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