#include "Menu.cpp"
#include "Stopwatch.cpp"
#include <iostream>
int main()
{
	try {
		Menu menu;
		menu.display();
		menu.choice();
	}
	catch (int x) {
		std::cout << "catch";
		return x;
		std::cout << "exit";
	}

	//Stopwatch swatch;
	//swatch.start(59);
}
