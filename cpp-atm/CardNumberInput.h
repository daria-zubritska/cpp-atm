#pragma once
#include "Input.h"
#include "ConsoleUtils.h"
#include <iostream>

class CardNumberInput : public Input
{
private:
	const int multipliter = 4;
public:
	CardNumberInput(int xpos, int ypos);

private:
	int keyToIntValue(SHORT key);
	void preExcecute() override;
	void addSymbol(SHORT key) override;
	void removeSymbol() override;
	int onReturn() override;
}; 