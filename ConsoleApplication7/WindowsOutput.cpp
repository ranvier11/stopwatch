#include "pch.h"
#include "WindowsOutput.h"
#include <iostream>;

void WindowsOutput::clearScreen()
{
	system("cls");
}

void WindowsOutput::beep()
{
	std::cout << "\a";
}
