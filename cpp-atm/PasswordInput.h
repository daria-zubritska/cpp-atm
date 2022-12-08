#pragma once
#include "Input.h"

class PasswordInput : public Input
{
public:
	PasswordInput(int xpos, int ypos, int xSize, int ySize);

private:
	void addSymbol(SHORT key) override;
};