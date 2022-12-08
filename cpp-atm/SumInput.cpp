#include "SumInput.h"

SumInput::SumInput(int xpos, int ypos, int ySize, int xSize, int length) : Input(xpos,ypos,xSize,ySize,length)
{
}

int SumInput::otherInputs(SHORT key)
{
	switch (key)
	{
	case VK_BACK:
		onBack();
		break;
	default:
		if (buffer.length() <= length && key >= 48 && key <= 57 && buffer.size())
			addSymbol(key);
		break;
	}
	return 0;
}