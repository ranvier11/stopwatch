#include "pch.h"
#include "Preset.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

//odczytuje ustawienia z pliku (zapis typu 2 4 6, 4 5 2), ka¿da linia ³adowana w while do stream, dalej do struct temp, temp do vector. struct temp jest incjalizowana
//na poczatku pêtli (b³¹d? powinienem j¹ usuwaæ na koniec?). funkcja zwraca vector ze struct zawieraj¹cymi dane do uruchomienia stopwatch.
std::vector<presetStruct> Preset::getPreset()
{
	std::vector<presetStruct> presetVector;
	std::ifstream file("presets.txt");
	//file.open("presets.txt", std::ios::in);

	std::string text;

	if (file)
	{
		int i = 0;
		
		while (getline(file, text))
		{
			std::stringstream ss;
			ss << text;
			
			presetStruct temp;
			
			ss >> temp.intervals;
			ss >> temp.intervalDuration;
			ss >> temp.loops;

			presetVector.push_back(temp);

			++i;
		}
	}
	else
	{
		std::cout << "no file...";
		
	}
	return presetVector;
}
