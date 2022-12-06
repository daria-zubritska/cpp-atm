#pragma once
#include <string>
class Label
{
protected:
	std::string text;
	int xpos, ypos;
public:
	Label(int xpos,int ypos,std::string text);
	void draw();
	int getXpos();
	int getYpos();
	void setXpos(int xpos);
	void setYpos(int ypos);
	std::string getText();
	void setText(std::string text);
};