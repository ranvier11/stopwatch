#include "pch.h"
#include "Stopwatch.h"
#include "iostream"
#include <thread>
#include <chrono>


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


void Stopwatch::run(int intervalDuration)
{
	int hour = 0, min = 0, sec = 0;

	while (hour < 2)
	{
		system("cls");
		if (sec < 60)
		{
			sec++;

			if (intervalDuration != 0 && sec % intervalDuration == 0)
			{

				std::cout << "\a";
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

Stopwatch::~Stopwatch()
{
}
