#pragma once
#include "UIModels.h"
#include <iostream>
#include <fstream>

Model UIModels::terminalScreen;
Model UIModels::terminalFar;
Model UIModels::pinInput;
Model UIModels::cardNumberInput;
Model UIModels::sumInput;
std::vector<std::string> UIModels::letters;

void UIModels::loadModels()
{
	///TODO: add replacableRegions, replacable symbols
	// defenetely you won't do this 
	UIModels::terminalScreen.symbols = load("models/terminal_screen.txt");
	UIModels::terminalScreen.height = 40;
	UIModels::terminalScreen.width = 134;
	
	UIModels::terminalFar.symbols = load("models/terminal_far.txt");
	UIModels::terminalFar.height = 40;
	UIModels::terminalFar.width = 100;
	UIModels::letters = loadLetters("models/letters.txt");

	UIModels::pinInput.symbols = load("models/pin_input.txt");
	UIModels::pinInput.height = 3;
	UIModels::pinInput.width = 17;

	UIModels::cardNumberInput.symbols = load("models/card_number_input.txt");
	UIModels::cardNumberInput.height = 3;
	UIModels::cardNumberInput.width = 29;

	UIModels::sumInput.symbols = load("models/sum_input.txt");
	UIModels::sumInput.height = 3;
	UIModels::sumInput.width = 40;
}

std::string UIModels::load(const std::string filename)
{
	std::string data = "";
	std::string line;
	std::ifstream file(filename);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (line[0] == (char)-17)
			{
				for (int i = 1; i < line.length(); ++i)
					data += line[i];
				data += '\n';
			}
			else
				data += line + '\n';
		}
		file.close();
	}
	else
	{
		std::cout << "Unable to open file " << filename;
		file.close();
	}
	return data;
}

std::vector<std::string> UIModels::loadLetters(const std::string filename)
{
	std::ifstream file(filename);
	auto letter_vector = std::vector<std::string>{};
	std::string line;
	short q = 0;
	short iq = 0;
	if (file.is_open())
	{
		while (getline(file, line))
		{
			switch (q)
			{
			case 0:
				letter_vector.push_back(line + '\n');
				++q;
				break;
			case 1:
				letter_vector[iq] += line + '\n';
				++q;
				break;
			case 2:
				letter_vector[iq] += line + '\n';
				++iq;
				q = 0;
				break;
			}
		}
		file.close();
	}
	else
	{
		std::cout << "Unable to open file";
		file.close();
	}
	return letter_vector;

}

