#pragma once
#include <vector>
#include <string>
#include <Windows.h>

struct Model
{
public:
	std::string symbols;
	int width = 0;
	int height = 0;
	std::vector<RECT> replacableRegions{};
	std::vector<char> replacableSymbols{};

	std::vector<std::string> getRows();
	static Model generateFrame(int xsize, int ysize);

	
};