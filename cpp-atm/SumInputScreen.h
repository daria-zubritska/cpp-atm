#include "Screen.h"
#include "Label.h"
#include "Window.cpp"
#include "Menu.h"


class SumInputScreen:Screen
{
private:
	std::vector<Window> windows;
	std::vector<Label> labels;
	std::vector<Menu> menus;

public:
	SumInputScreen();
	void draw();
	int excecute();
	int getValue();
};