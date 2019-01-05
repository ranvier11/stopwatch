#include "pch.h"
#include "NewMenu.h"
#include "Output.h"
#include "Input.h"
#include <string>
#include <vector>
//#include <iostream>

//pokazuje menu 
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

//przyjmuje wybór uzytkownika
int NewMenu::getChoice()
{
	int itemNumber = Input::input();
	return itemNumber;
}

//menu do ustawien uzykownika, switch by kontrolowaæ wyswietlanie, na zmiane z przyjmowaniem danych od uzytkownika
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

//wywietla zawartoæ vectora ze struct preset
void NewMenu::presetsMenu(std::vector<presetStruct> presets)
{
	int i = 1;

	for (const auto& item : presets)
	{
		Output::displayPreset(i, item.intervals, item.intervalDuration, item.loops);
		++i;
	}

	Output::displayText("\n\tEnter preset number: ");
}
