#include "ConsoleUtils.h"

int ConsoleUtils::height;
int ConsoleUtils::width;

void ConsoleUtils::resize(RECT rect)
{
    //if(ConsoleUtils::consoleHwnd == nullptr)
    ConsoleUtils::width = rect.right - rect.left;
    ConsoleUtils::height = rect.bottom - rect.top;
    HWND consoleHwnd = GetConsoleWindow();
    MoveWindow(consoleHwnd, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, TRUE);
}

void ConsoleUtils::setCursorPosition(int x, int y)
{
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}