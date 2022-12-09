#include <Windows.h>
#include <conio.h>
#include <string>
#include <vector>
#pragma once
class ConsoleUtils
{
public:
	//delete this???
	static int height;
	static int width;
	static void resize(RECT rect);
	static void setCursorPosition(int x, int y);
	static const std::vector<std::string> frameSymbols;

	static void drawAt(int x, int y, std::vector<std::string> rows);
	static void drawAt(int x, int y, std::string row);
	static void drawAt(int x, int y, char symbol);
	static SHORT GetKey();
	static void ClearScreen();
	static std::string extend(std::string val, int size);
	static std::vector<std::string> getFrameSymbols();
};
