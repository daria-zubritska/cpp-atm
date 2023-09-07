#pragma once
#include <string>
#include "IDrawable.h"
class Label : IDrawable
{
protected:
	std::string text;
	int xpos, ypos,length;
public:
	Label(int xpos,int ypos,int length,std::string text);
	Label(int xpos, int ypos, std::string text);
	void draw() override;
	int getXpos();
	int getYpos();
	void setXpos(int xpos);
	void setYpos(int ypos);
	std::string getText();
	void setText(std::string text);
};