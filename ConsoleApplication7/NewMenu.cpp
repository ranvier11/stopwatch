#include "pch.h"
#include "NewMenu.h"
#include "Output.h"
#include "Input.h"
#include <string>
#include <vector>
#include <iostream>


void NewMenu::showMenu(std::vector<std::string> menuItems)
{
	int fieldNumber = 1;
	Output::displayText("\n\t\tStopwatch\n\n");

	for (const auto& item : menuItems)
	{
		Output::displayText(std::to_string(fieldNumber));
		Output::displayText(item);
		++fieldNumber;
	}

	Output::displayText("\n\tEnter number: ");
}

int NewMenu::getChoice()
{
	int itemNumber = Input::input();
	return itemNumber;
}

void NewMenu::settingsMenu(int x)
{
	switch (x)
	{
	case 1:
		Output::displayText("\n\tEnter number of intervals: ");
		break;
	case 2:
		Output::displayText("\n\tEnter duration of single interval x10sec: ");
		break;
	case 3:
		Output::displayText("\n\tEnter number of loops: ");
		break;
	default:
		Output::displayText("\n\tNothing to display...");
		break;
	}
}


void NewMenu::presetsMenu(std::vector<presetStruct> presets)
{
	std::vector<int> numbersForInput;
	int i = 1;

	for (const auto& item : presets)
	{
		Output::displayPreset(i, item.intervals, item.intervalDuration, item.loops);
		numbersForInput.push_back(i);
		++i;
	}

	Output::displayText("\n\tEnter preset number: ");
}
