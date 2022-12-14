#include "ConsoleUtils.h"
#include <iostream>
#pragma once

int ConsoleUtils::height;
int ConsoleUtils::width;

const std::vector<std::string> frameSymbols = ConsoleUtils::getFrameSymbols();

void ConsoleUtils::resize(RECT rect)
{
    ConsoleUtils::width = rect.right - rect.left;
    ConsoleUtils::height = rect.bottom - rect.top;
    HWND consoleHwnd = GetConsoleWindow();
    MoveWindow(consoleHwnd, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, TRUE);
}

void ConsoleUtils::setCursorPosition(unsigned int x, unsigned int y)
{
    COORD pos = { (SHORT)x, (SHORT)y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

SHORT ConsoleUtils::GetKey() 
{
	keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
	int a;
	while (TRUE)
	{
		a = _getch();
		switch (a)
		{
		case(224):
			a = _getch();
			switch (a)
			{
			case 72:
				return VK_UP;
			case 80:
				return VK_DOWN;
			case 77:
				return VK_RIGHT;
			case 75:
				return VK_LEFT;
			}
			break;
		case 8:
			return VK_BACK;
		case 27:
			return VK_ESCAPE;
		case 13:
			return VK_RETURN;
		case 9:
			return VK_TAB;
		default:
			return a;
		}
	}
}

void ConsoleUtils::drawAt(int x, int y, std::vector<std::string> rows)
{
	for (int i = 0; i < rows.size(); ++i)
	{
		ConsoleUtils::setCursorPosition(x, y + i);
		std::cout << rows[i];
	}
}

void ConsoleUtils::drawAt(int x, int y, std::string row)
{
	ConsoleUtils::setCursorPosition(x, y);
	std::cout << row;
}

void ConsoleUtils::drawAt(int x, int y, char symbol)
{
	ConsoleUtils::setCursorPosition(x, y);
	std::cout << symbol;
}

void ConsoleUtils::ClearScreen()
{
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

std::string ConsoleUtils::extend(std::string val, int size)
{
	for (int i = 0; i < size; ++i)
		val += ' ';
	return val;
}

std::vector<std::string> ConsoleUtils::getFrameSymbols()
{
	std::vector<std::string> out;
	std::string preset = { (char)-30 };
	preset += (char)-107;
	out.push_back(preset + (char)-111);
	out.push_back(preset + (char)-108);
	out.push_back(preset + (char)-102);
	out.push_back(preset + (char)-105);
	out.push_back(preset + (char)-99);
	out.push_back(preset + (char)-112);
	return out;
}