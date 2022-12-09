#include "SumInputScreen.h"

SumInputScreen::SumInputScreen()
	: Screen(120, 40, 1005 + 200, 700 + 200),
	input(41, 13, 40, 3,20)
{
	windows.push_back({ 0,0,width,height });
	windows.push_back({ 41,0,36,3 });
	labels.push_back({ 47,1,"input sum" });
	windows.push_back({ 3,4,114,34 });

}

void SumInputScreen::draw()
{
	windows[0].draw();
	windows[1].draw();
	windows[2].draw();
	for (auto i : labels)
		i.draw();
	input.draw();
}

int SumInputScreen::execute()
{
	while(true)
		switch (input.execute())
		{
		case 0:
			return 0;
		case 2:
			return 2;
		}
}

std::string SumInputScreen::getValue()
{
	return input.getBuffer();
}

void SumInputScreen::clear()
{
	input.clearBuffer();
}