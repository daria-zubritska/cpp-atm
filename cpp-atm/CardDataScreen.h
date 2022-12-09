#include "Screen.h"
#include "Label.h"
#include "Window.cpp"
#include "Menu.h"

class CardDataScreen : Screen
{
private:
	std::vector<Window> windows;
	std::vector<Label> labels;
	Menu transactionMenu;
	Menu actionMenu;
	std::string cardNumber;

public:
	CardDataScreen(std::vector<std::string> elements, std::vector<std::string> info,std::string cardNumber);
	void draw();
	//if 1 -> transaction data if 0 -> thing 2 -> escape
	int excecute();
	std::string getSelectedTransaction();
	std::string getSelectedElement();
	unsigned int getSelectedTransactionIndex();
	unsigned int getSelectedElementIndex();
};