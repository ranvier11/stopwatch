#pragma once
#include <string>
#include <vector>
class Menu
{
private:
	
public:
	Menu();

	void display();
	void choice();
	int exit();
	void intervalSettings();
	std::vector<std::vector<int>> getPresets();
	void displayPresets(std::vector<std::vector<int>> presets);
	void runInput();
	int wrongInput(int input, int val1, int val2);
	~Menu();
};

