#pragma once
#include "Window.h"

Window::Window(int xpos, int ypos, int xsize, int ysize) :Control(xpos, ypos, Model::generateFrame(xsize, ysize))
{

}

void Window::draw()
{
	ConsoleUtils::drawAt(xpos, ypos, model.getRows());
}


int Window::execute() { return 0; };
int Window::onReturn() { return 0; };
int Window::onEscape() { return 0; };
int Window::onTab() { return 0; };
int Window::onArrows(SHORT key) { return 0; };
int Window::otherInputs(SHORT key) { return 0; };
void Window::preExecute() {};