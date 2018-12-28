#pragma once
#include <string>
#include <vector>
class Menu
{
private:
	std::string menuItems;
public:
	Menu();

	void display();
	void choice();
	int exit();
	void intervalSettings();
	std::vector<std::vector<int>> getPresets();
	void displayPresets(std::vector<std::vector<int>> presets);
	~Menu();
};

