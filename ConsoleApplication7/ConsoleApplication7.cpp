
#include "pch.h"
#include "NewMenu.h"
#include "Stopwatch.h"
#include "Output.h"
#include "WindowsOutput.h"
#include "Input.h"
#include "Preset.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::vector<std::string> menuItems = { ") Start simple stopwatch\n", ") Set intervals and start\n", ") Use presets\n", ") Quit\n" };
	NewMenu menu;
	Output * output = new WindowsOutput;
	int presetChoice;
	std::vector<presetStruct> mainPresets = Preset::getPreset();

	menu.showMenu(menuItems);

	int intervals;
	int intervalDuration;
	int loops;

	int userChoice = menu.getChoice();
	bool choiceMade = false;

	while (!choiceMade)
	{
		switch (userChoice)
		{
		case 1:
			Stopwatch::run(5, 6, 1, output);
			choiceMade = true;
			break;
		case 2:
			menu.settingsMenu(1);
			intervals = menu.getChoice();
			menu.settingsMenu(2);
			intervalDuration = menu.getChoice();
			menu.settingsMenu(3);
			loops = menu.getChoice();
			Stopwatch::run(intervals, intervalDuration, loops, output);
			choiceMade = true;
			break;
		case 3:
			menu.presetsMenu(mainPresets);
			presetChoice = menu.getChoice();
			Stopwatch::runPresets(presetChoice, mainPresets, output);
			choiceMade = true;
			break;
		case 4:
			return 0;

		default:
			Input::clearInput();
			userChoice = menu.getChoice();
			break;
		}
	}
	return 0;
}