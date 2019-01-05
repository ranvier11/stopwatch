#include "pch.h"
#include "Output.h"
#include <iostream>

void Output::displayText(std::string text)
{
	std::cout << text;
}

void Output::displayPreset(int counter,int intervals, int intervalDuration, int loops)
{
	std::cout << "\n\tPreset " << counter << " | intervals: " << intervals << " | interval duration: " << intervalDuration << "0sec | loops: "<<loops;
}

