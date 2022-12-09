#pragma once
#include <string>
#include <vector>
#include "Control.h"
#include "Label.h"

class Menu: public Control
{
private:
	std::vector<Label> labels;
	std::vector<std::string> elements;
	int cursorPosition{ 0 }, visibleCount{ 0 }, scrollIndex{ 0 };
	static const int xCursorOffcet{ 2 };
public:
	Menu(int xpos,int ypos, int xsize, int ysize, std::vector<std::string> elements);
	Model generateModel(int xsize, int ysize);
	void draw() override;
	void resetCursor();
	int getCursorPosition();
	std::vector<std::string> getElements();
private:
	void drawCursor();
	void eraseCursor();
	int onTab() override;
	int onArrows(SHORT key) override;
	void preExecute() override;
};