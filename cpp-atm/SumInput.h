#pragma once
#include "Input.h"

class SumInput : public Input
{

public:
	SumInput(int xpos, int ypos, int ySize, int xSize, int length);

private:
	int otherInputs(SHORT key) override;
};