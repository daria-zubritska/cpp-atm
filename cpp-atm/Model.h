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


	std::vector<std::string> getRows()
	{
		std::vector<std::string> out;
		std::string buf = "";

		for (int i = 1; i < symbols.length(); ++i)
		{
			
			if(symbols[i] == '\n')
			{ 
				out.push_back(buf);
				buf = "";
			}
			else
				buf += symbols[i];
		}
		return out;
	}
};