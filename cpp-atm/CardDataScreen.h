#include "Screen.h"
#include "Label.h"
#include "Window.cpp"
#include "Menu.h"

class CardDataScreen : Screen
{
private:
	std::vector<Window> windows;
	std::vector<Label> labels;
	std::vector<Menu> menus;

public:
	CardDataScreen(std::vector<std::string> elements, std::string info);
	void draw();
	//if 1 -> transaction data if 0 -> thing
	int excecute();
	std::string getSelectedTransaction();
	std::string getSelectedElement();
	unsigned int getSelectedTransactionIndex();
	unsigned int getSelectedElementIndex();
};