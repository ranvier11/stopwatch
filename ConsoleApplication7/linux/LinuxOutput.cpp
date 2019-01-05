#include "pch.h"
#include "LinuxOutput.h"
#include <iostream>
void LinuxOutput::clearScreen()
{
	system("clear");
}

void LinuxOutput::beep()
{
	std::cout<<"\a";
}
