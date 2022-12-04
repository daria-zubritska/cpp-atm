#pragma once
#include "Screen.h"
#include "Window.cpp"
#include "Input.h"
#include "Label.h"

class LoginScreen : Screen
{
private:
	std::vector<Window> windows;
	std::vector<Input> inputs;
	std::vector<Label> labels;
	
public:

	std::string getPassword();
	std::string getLogin();
	void clearInputs();
	LoginScreen(int width, int height, int xSize, int ySize);

	void init();

	void draw();
	int excecute();

};