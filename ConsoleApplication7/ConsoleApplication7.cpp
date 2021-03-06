
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
	//vector z opcjami menu
	std::vector<std::string> menuItems = { ") Start simple stopwatch\n", ") Set intervals and start\n", ") Use presets\n", ") Quit\n" };
	
	NewMenu menu;
	//inicjalizacja obiektu output dla windows
	Output * output = new WindowsOutput;

	// zmienna dla wyboru presetów
	int presetChoice;

	//zmienna na vector z preset
	std::vector<presetStruct> mainPresets = Preset::getPreset();

	// pokaż menu + vector z opcjami
	menu.showMenu(menuItems);

	//zmienne dla "set intervals..."
	int intervals;
	int intervalDuration;
	int loops;

	//wybór opcji menu
	int userChoice = menu.getChoice();

	//flaga, czy dokonano wyboru
	bool choiceMade = false;

	while (!choiceMade)
	{
		switch (userChoice)
		{
			//uruchom podstawowy stopwatch
		case 1:
			Stopwatch::run(5, 6, 1, output);
			choiceMade = true;
			break;

			//ustaw dane dla stopwatch
		case 2:
			//pokaż prośbe o wpis
			menu.settingsMenu(1);
			//odbież wpis
			intervals = menu.getChoice();

			menu.settingsMenu(2);
			intervalDuration = menu.getChoice();

			menu.settingsMenu(3);
			loops = menu.getChoice();

			Stopwatch::run(intervals, intervalDuration, loops, output);
			choiceMade = true;
			break;

			//uruchom z preset
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