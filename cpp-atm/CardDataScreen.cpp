#include "CardDataScreen.h"

CardDataScreen::CardDataScreen(std::vector<std::string> elements, std::vector<std::string> info, std::string cardNumber) 
	: Screen(120, 40, 1005 + 200, 700 + 200), 
	transactionMenu{ 61-19,4,40,34, elements },
	actionMenu{ 101-20,4,40 - 4,34, {"donate to militaries"} }
{
	this->cardNumber = cardNumber;
	while(false)
		for (int i = 0; i < 36; ++i);
	/*for (auto i : elements)
		labels.push_back({})*/
	
	windows.push_back({ 0,0,width,height });
	windows.push_back({ 41,0,36,3 });
	labels.push_back({ 48,1,cardNumber});

	for (int i = 0; i < 10; ++i)
		labels.push_back({ 5, 5 + i, info.size() > i ? info[i] : " " });

	windows.push_back({ 3,4,56,34 });
}

void CardDataScreen::draw()
{
	windows[0].draw();
	windows[1].draw();
	windows[2].draw();
	transactionMenu.draw();
	actionMenu.draw();
	for (auto i : labels)
		i.draw();
}

int CardDataScreen::execute()
{
	while (true)
	{

		switch (transactionMenu.execute())
		{
		case 0:
			return 1;
		case 2:
			return 2;
		}

		switch (actionMenu.execute())
		{
		case 0:
			return 0;
		case 2:
			return 2;
		}
	}
}

unsigned int CardDataScreen::getSelectedTransactionIndex()
{
	return transactionMenu.getCursorPosition();
}

unsigned int CardDataScreen::getSelectedElementIndex()
{
	return actionMenu.getCursorPosition();
}

