#pragma once
#include "Model.h"
#include <vector>
#include <string>

class UIModels
{
public:
	static Model terminalScreen;
	static Model terminalFar;
	static Model pinInput;
	static Model cardNumberInput;
	static Model sumInput;
	static std::vector<std::string> letters;

public:
	static void loadModels();
private:
	static std::string load(const std::string filename);
	static std::vector<std::string> loadLetters(const std::string filename);
};