#include <Windows.h>
class ConsoleUtils
{
public:
	static int height;
	static int width;
	static void resize(RECT rect);
	static void setCursorPosition(int x, int y);
};
