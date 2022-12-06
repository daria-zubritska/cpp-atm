#include "CardNumberInput.h"

CardNumberInput::CardNumberInput(Model model, int xpos, int ypos)
{
	this->model = model;
	this->xpos = xpos;
	this->ypos = ypos;
}

std::string CardNumberInput::execute()
{
	std::string buf = "";
	int* prev_size = new int{ 1 };
	SHORT key{ 0 };

	ConsoleUtils::drawAt(xpos, ypos, model.getRows());
	ConsoleUtils::setCursorPosition(xpos + 2, ypos + 1);
	int multipliter = 4;
	while (true)
	{
		key = ConsoleUtils::GetKey();

		if (key >= 48 && key <= 57 && buf.size() <= 15)
		{
			buf += std::to_string((keyToIntValue(key)));
			std::cout << keyToIntValue(key);
			if(buf.size() < 15)
				ConsoleUtils::setCursorPosition(xpos + 1 + (buf.size()) + 1 + buf.size() / 4 * 3, ypos + 1);
		}

		if (key == VK_RETURN && buf.length() == 16)
			return buf;

		if (key == VK_ESCAPE)
		{
			return "";
		}

		if (key == VK_BACK && buf.length() != 0)
		{
			if (buf.size() % 4 == 0)
				ConsoleUtils::setCursorPosition(xpos + 1 + (buf.size()) + buf.size() / 4 * 3-3, ypos + 1);
			else
				ConsoleUtils::setCursorPosition(xpos + 1 + (buf.size()) + buf.size() / 4 * 3, ypos + 1);
			buf.resize(buf.size() - 1);
			std::cout << " ";
			ConsoleUtils::setCursorPosition(xpos + 1 + (buf.size()) + buf.size() / 4 * 3 +1 , ypos + 1);
		}
	}
	return buf;
}

int CardNumberInput::keyToIntValue(SHORT key)
{
	return key - 48;
}