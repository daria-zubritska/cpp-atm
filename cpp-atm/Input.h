#pragma once
#include "Control.h"
#include "ConsoleUtils.h"
class Input : Control
{
private:
	int length;
	std::string buffer;
public:
	std::string getBuffer();
	void clearBuffer();
	Input(int xpos, int ypos, int xSize, int ySize, int length);

	int execute();
	void draw();

private:

protected:
	Model generateFrame(int xsize, int ysize);
	void addSymbol(SHORT key);
	void removeSymbol(SHORT key);
};