#pragma once
#include <string>
class Output
{
public:
	virtual void clearScreen() = 0;
	virtual void beep() = 0;

	static void displayText(std::string text);
	static void displayPreset(int counter, int intervals, int intervalDuration, int loops);
};

