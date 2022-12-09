#include "CardNumberInputScreen.h"


CardNumberInputScreen::CardNumberInputScreen()
	: Screen(120, 40, 1005 + 200, 700 + 200),
	input(41, 13)
{
	windows.push_back({ 0,0,width,height });
	windows.push_back({ 41,0,36,3 });
	labels.push_back({ 47,1,"input card number" });
	windows.push_back({ 3,4,114,34 });

}

void CardNumberInputScreen::draw()
{
	windows[0].draw();
	windows[1].draw();
	windows[2].draw();
	for (auto i : labels)
		i.draw();
	input.draw();
}

int CardNumberInputScreen::execute()
{
	while (true)
		switch (input.execute())
		{
		case 0:
			return 0;
		case 2:
			return 2;
		}
}

std::string CardNumberInputScreen::getValue()
{
	return input.getBuffer();
}

void CardNumberInputScreen::clear()
{
	input.clearBuffer();
}