#pragma once
#include "Model.h"
#include "ConsoleUtils.h"
#include <iostream>
#include <functional>
#include <vector>
class Screen
{
private:
	Model model;


public:
	void update(int pos);

	Screen(Model model);
	std::string excecute(std::vector < std::function<std::string(void)>> uiFunctions, std::vector < std::function<void(std::string)>> functions);

private:
	void fillButton(char symbol, int xpos, int ypos, bool right);

	int cursorChange(int currentPos, SHORT key);
};