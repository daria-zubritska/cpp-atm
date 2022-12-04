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