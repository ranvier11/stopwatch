#include "pch.h"
#include "Stopwatch.h"
#include "Output.h"
#include "WindowsOutput.h"
#include "iostream"
#include <thread>
#include <chrono>



// run only with duration
void Stopwatch::run(int intervalDuration, Output * output)
{
	int hour = 0, min = 0, sec = 0;

	while (hour < 2)
	{
		output->clearScreen();
		if (sec < 60)
		{
			sec++;

			if (intervalDuration != 0 && sec % intervalDuration == 0)
			{

				output->beep();
			}

		}
		else if (sec == 60)
		{
			sec = 0;
			min++;
		}
		else if (min == 60)
		{
			min = 0;
			hour++;
		}
		std::cout << "\n\n\t\tHour : " << hour << " min : " << min << " sec : " << sec;

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

// run with set of values
void Stopwatch::run(int intervalCount, int intervalDuration, int loops, Output * output)
{
	intervalDuration = intervalDuration * 10;
	int pause = 60;
	
	for (int i = 1; i <= loops; ++i)
	{
		for (int j = 1; j <= intervalCount; ++j)
		{
			for (int s = 1; s <= intervalDuration; ++s)
			{
				output->clearScreen();
				std::cout << "\t\tSetting: intervals " << intervalCount << "| interval duration " << intervalDuration << "sec | loops " << loops << std::endl;
				std::cout << "\n\n\t\tLoop : " << i << " interval : " << j << " sec : " << s;
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
			output->beep();
			if (j == intervalCount)
			{
				// 60 s pause, with beep on 3 last seconds
				std::cout << "\n\n\t\tPause for 60 seconds"<<std::endl;
				for (int x = 1; x <= pause; ++x)
				{
					std::cout << x;
					std::this_thread::sleep_for(std::chrono::seconds(1));
					if (x >= pause-2)
					{
						output->beep();
					}
				}
			}
		}
	}
}

void Stopwatch::runPresets(int presetChoice, std::vector<presetStruct> presetVector, Output * output)
{
	Stopwatch::run(presetVector[presetChoice].intervals, presetVector[presetChoice].intervalDuration, presetVector[presetChoice].loops, output);
	std::cout << presetChoice;
}

