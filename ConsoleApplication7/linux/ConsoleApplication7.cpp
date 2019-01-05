#include "pch.h"
#include "Menu.h"
#include "Stopwatch.h"
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


