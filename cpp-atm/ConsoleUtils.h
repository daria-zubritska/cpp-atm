#include <Windows.h>
#include <conio.h>
#pragma once
class ConsoleUtils
{
public:
	static int height;
	static int width;
	static void resize(RECT rect);
	static void setCursorPosition(int x, int y);

	static SHORT GetKey();
	static void ClearScreen();
};
