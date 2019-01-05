#pragma once
#include <vector>
struct presetStruct
{
	int intervals;
	int intervalDuration;
	int loops;
};
class Preset
{
public:
	static std::vector<presetStruct> getPreset();
	
};

