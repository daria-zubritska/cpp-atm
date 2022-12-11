#pragma once
#include "Screen.h"
#include "Label.h"
#include "Window.h"
#include "Menu.h"
#include "SumInput.h"

class SumInputScreen : Screen
{
private:
	std::vector<Window> windows;
	std::vector<Label> labels;
	SumInput input;

public:
	SumInputScreen();
	void draw() override;
	int execute() override;
	std::string getValue();
	void clear() override;
};