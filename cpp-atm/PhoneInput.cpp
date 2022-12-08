#include "PhoneInput.h"

PhoneInput::PhoneInput(int xpos, int ypos, int xSize, int ySize) : Input(xpos, ypos, xSize, ySize, 10){}

int PhoneInput::otherInputs(SHORT key)
{
	switch (key)
	{
	case VK_BACK:
		onBack();
		break;
	default:
		if (buffer.length() < length && key >= 48 && key <= 57)
			addSymbol(key);
		break;
	}
	return 0;
}