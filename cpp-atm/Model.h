#include <vector>
#include <string>
#include <Windows.h>
#pragma once
struct Model
{
public:
	std::string symbols;
	int width;
	int height;
	std::vector<RECT> replacableRegions{};
	std::vector<char> replacableSymbols{};
};