#include <vector>
#include <string>
#include "Model.cpp"

class UIModels
{
public:
	static Model terminalScreen;
	static Model terminalFar;
	static Model pinInput;
	static Model cardNumberInput;
	static std::vector<std::string> letters;

public:
	static void loadModels();
private:
	static std::string load(const std::string filename);
	static std::vector<std::string> loadLetters(const std::string filename);
};