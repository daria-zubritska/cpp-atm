#pragma once
#include "Control.h"
#include "ConsoleUtils.h"



int Control::otherInputs(SHORT key) { return 0; }

int Control::execute()
{
	SHORT key;
	preExcecute();
	int buf = 0;
	while (true)
	{
		key = ConsoleUtils::GetKey();
		switch (key)
		{
		case VK_ESCAPE:
			return onEscape();
		case VK_RETURN:
			buf = onReturn();
			if (buf != -1)
				return buf;
			break;
		case VK_TAB:
			return onTab();
		case VK_UP:
		case VK_DOWN:
		case VK_RIGHT:
		case VK_LEFT:
			onArrows(key);
			break;
		default:
			otherInputs(key);
		}
	}
}

int Control::onReturn()
{
	return 0;
}

int Control::onTab()
{
	return 1;
}

int Control::onEscape()
{
	return 2;
}

int Control::onArrows(SHORT key)
{
	return 0;
}

void Control::preExcecute()
{

}

void Control::draw()
{
	ConsoleUtils::drawAt(xpos, ypos, model.getRows());
}