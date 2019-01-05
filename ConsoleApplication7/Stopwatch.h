#pragma once
#include "Output.h"
#include "WindowsOutput.h"
#include "Preset.h"
#include <chrono>
#include <vector>

class Stopwatch
{
private:
	// clock is running flag
	bool running = false;

	// number of intervals
	int intervalCount = 0;

	// number of loops
	int loops = 0;

	// duration of intervals in 10 seconds unit
	int intervalDuration = 0;

	// type for current time;
	//typedef std::chrono::steady_clock  swatch;



public:

	int interval[3];

	// stops stopwatch using current time
	void pause();

	// set & get intervals
	
	int getInterval();
	int setInterval(int intervalCount, int intervalDuration, int loops);
	void static run(int intervalDuration, Output * output);

	void static run(int intervalCount, int intervalDuration, int loops, Output * output);

	void static runPresets(int presetChoice, std::vector<presetStruct> presetVector, Output * output);
};

