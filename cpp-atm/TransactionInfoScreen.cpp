#include "TransactionInfoScreen.h"

TransactionInfoScreen::TransactionInfoScreen(std::vector<std::string> info)
	: Screen(120, 40, 1005 + 200, 700 + 200)
{
	windows.push_back({ 0,0,width,height });
	windows.push_back({ 41,0,36,3 });
	labels.push_back({ 47,1,"transaction information" });
	for (int i = 0; i < 10; ++i)
		labels.push_back({ 5, 5 + i, info.size() > i ? info[i] : " " });
	windows.push_back({ 3,4,114,34 });
}

void TransactionInfoScreen::draw()
{
	windows[0].draw();
	windows[1].draw();
	windows[2].draw();
	for (auto i : labels)
		i.draw();
}

int TransactionInfoScreen::execute()
{
	while (true)
	{
		if (ConsoleUtils::GetKey() == VK_ESCAPE)
			return 2;
	}
}