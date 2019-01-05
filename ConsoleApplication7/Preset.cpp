#include "pch.h"
#include "Preset.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>


std::vector<presetStruct> Preset::getPreset()
{
	std::vector<presetStruct> presetVector;
	std::ifstream file;
	file.open("presets.txt", std::ios::in);

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
		std::cout << "bad file";
		
	}
	return presetVector;
}
