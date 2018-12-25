#pragma once
#include <chrono>

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
	Stopwatch();

	int interval[3];

	// starts and restarts clock
	void start();
	void start(int intervalDuration);

	// stops stopwatch using current time
	void pause();

	// set & get intervals
	int setInterval(int intervalCount, int intervalDuration, int loops);
	int getInterval();

	void static run(int intervalDuration);

	~Stopwatch();
};

