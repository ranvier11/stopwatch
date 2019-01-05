#pragma once
#include "Output.h"
class WindowsOutput :
	public Output
{
public:
	void clearScreen();
	void beep();
};

