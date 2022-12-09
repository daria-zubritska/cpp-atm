#pragma once
#include "Control.h"
class Input : public Control
{
protected:
	int length;
	std::string buffer;
public:
	std::string getBuffer();
	void clearBuffer();
	Input(int xpos, int ypos, int xSize, int ySize, int length);

protected:
	virtual void onBack();
	virtual void removeSymbol();
	virtual void addSymbol(SHORT key);
	virtual void preExecute() override;
	virtual int otherInputs(SHORT key) override;
};