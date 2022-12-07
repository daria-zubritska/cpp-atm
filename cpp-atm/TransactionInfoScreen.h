#include "Screen.h"
#include "Label.h"
#include "Window.cpp"
#include "Menu.h"

class TransactionInfoScreen : Screen
{
private:
	std::vector<Window> windows;
	std::vector<Label> labels;
	std::vector<Menu> menus;

public:
	TransactionInfoScreen(std::string tranaction, std::string info);
	void draw();
	int excecute();
};