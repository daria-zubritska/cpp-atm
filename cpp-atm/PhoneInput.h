#include "Input.h"


class PhoneInput :public Input
{
public:
	PhoneInput(int xpos, int ypos, int xSize, int ySize);
private:
	int otherInputs(SHORT key) override;
};