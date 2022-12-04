#include <string>
class Label
{
protected:
	std::string text;
	int xpos, ypos;
public:
	Label(int xpos,int ypos,std::string text);
	void draw();
};