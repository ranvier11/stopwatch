#include "pch.h"
#include "Input.h"
#include <iostream>
#include <limits>

int Input::input()
{
	int userInput;

	while (!(std::cin >> userInput))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "wrong input! please enter again \n";
	}

	return userInput;
}

void Input::clearInput()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
