#pragma once
#include <vector>
#include <string>
#include "Preset.h"

class NewMenu
{
public:
	void showMenu(std::vector<std::string> menuItems);
	int getChoice();
	void settingsMenu(int x);
	void presetsMenu(std::vector<presetStruct>);
};

