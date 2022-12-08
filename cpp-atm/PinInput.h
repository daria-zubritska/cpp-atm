#pragma once
#include "Input.h"
class PinInput : public Input
{
private:
	const int multipliter = 4;
public:
	
	PinInput(int xpos, int ypos);

private:
	void preExcecute() override;
	int onReturn() override;
	void removeSymbol() override;
	void addSymbol(SHORT key) override;
	int keyToIntValue(SHORT key);
};