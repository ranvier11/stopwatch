#pragma once
#include <string>
class Menu
{
private:
	std::string menuItems;
public:
	Menu();

	void display();
	void choice();
	int exit();
	~Menu();
};

