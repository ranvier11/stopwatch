#include "pch.h"
#include "Stopwatch.h"
#include "iostream"
#include <thread>
#include <chrono>
#include "ncurses.h"


Stopwatch::Stopwatch()
{
	
}

void Stopwatch::start()
{
	this->run(0);
}

void Stopwatch::start(int intervalDuration)
{
	//this->intervalDuration = intervalDuration;
	this->run(intervalDuration);
}

// run only with duration
void Stopwatch::run(int intervalDuration)
{
	int hour = 0, min = 0, sec = 0;

	while (hour < 2)
	{
		system("clear");
		if (sec < 60)
		{
			sec++;

			if (intervalDuration != 0 && sec % intervalDuration == 0)
			{

				//std::cout << "\a";
				beep();
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
void Stopwatch::run(int intervalCount, int intervalDuration, int loops)
{
	intervalDuration = intervalDuration * 10;
	int pause = 60;
	
	for (int i = 1; i <= loops;)
	{
		for (int j = 1; j <= intervalCount;)
		{
			for (int s = 1; s <= intervalDuration;)
			{
				//std::cout << s;
				system("clear");
				std::cout << "\t\tSetting: intervals " << intervalCount << "| interval duration " << intervalDuration << "sec | loops " << loops << std::endl;
				std::cout << "\n\n\t\tLoop : " << i << " interval : " << j << " sec : " << s;
				std::this_thread::sleep_for(std::chrono::seconds(1));
				s++;
			}
			beep();
			//std::cout << "\a";
			if (j == intervalCount)
			{
				// 60 s pause, with beep on 3 last seconds
				std::cout << "\n\n\t\tPause for 60 seconds"<<std::endl;
				for (int x = 1; x <= pause;)
				{
					std::cout << x;
					std::this_thread::sleep_for(std::chrono::seconds(1));
					if (x >= pause-2)
					{
						beep();
						//std::cout << "\a";
						x++;
					}
					else
					{
						x++;
					}
				}
				j++;
			}
			else
			{
				j++;
			}
		}
		i++;
	}
}

void Stopwatch::runPresets(int presets[])
{

}

Stopwatch::~Stopwatch()
{
}