#pragma once
#include "Output.h"
class LinuxOutput :
	public Output
{
public:
	void clearScreen();
	void beep();
};

