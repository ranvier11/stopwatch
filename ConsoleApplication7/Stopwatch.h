#pragma once
#include "Output.h"
#include "WindowsOutput.h"
#include "Preset.h"
#include <chrono>
#include <vector>

class Stopwatch
{
public:
	
	void static run(int intervalDuration, Output * output);

	void static run(int intervalCount, int intervalDuration, int loops, Output * output);

	void static runPresets(int presetChoice, std::vector<presetStruct> presetVector, Output * output);
};

