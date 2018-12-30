#include "pch.h"
#include "Menu.h"
#include "Stopwatch.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

Menu::Menu()
{
}

// array of menu choices
string menuItems[] = {"Start simple stopwatch", "Set intervals and start", "Use presets", "Quit"};

// using pointer to get menuItems array in a static method dispaly()  
string* menuItemsPtr = menuItems;

// display menu method
void Menu::display()
{
	cout << endl;
	cout << setw(20);
	cout << internal << "stopwatch" << endl;
	cout << endl;

	// displaying menu items
	if (sizeof(menuItemsPtr > 0) )
	{
		for (int i = 0; i <= sizeof(menuItemsPtr);)
		{
			// x variable for menu item value
			int x = i;
			cout <<"\t"<< ++x << ") " << menuItemsPtr[i] << endl;
			i++;
		}
	}
	else
	{
		cout << "No menu items..."<<endl;
	}
	

}

void Menu::choice()
{
	cout << endl;
	char itemNumber;
	//bool cinValid;
	cin>>itemNumber;

		switch (itemNumber)
		{
			// runs simple stopwatch, no beep
		case '1':
			Stopwatch::run(0);
			break;
 
			// run with user input values
		case '2':
			runInput();
			break;

			// run with presets 
		case '3':
			this->displayPresets(this->getPresets());
			break;
			
			// throw exception to exit, catch in main()
		case '4':
			throw 0;
			//break;

			// wrong input case, clear console, show menu
		default:
			cout << "wrong input!" << endl;
			cin.sync();
			itemNumber = 0;
			system("pause");
			system("cls");
			this->display();
			this->choice();
		}
}

int Menu::exit()
{
	cout << "exit";
	return 0;
}

void Menu::intervalSettings()
{
	// fot interval number
	int x=0;

	// for interval duration
	int y=0;

	// number of loops
	int loops=0;

	system("cls");
	cout << "Number of intervals from 1 to 10: ";
	cin>>x;
	cout << endl;
	cout << "Interval duration from 1 to 6 x 10 seconds: ";
	cin >> y;
	cout << endl;
	cout << "Press enter to start or set number of loops: ";
	cin >> loops;


}

// function to get prestes from text file in app directory "presets.txt"
vector<vector<int>> Menu::getPresets()
{
	// array to hold 2 presets
	int presets[2][3];
	//array <int, 2>presets[2][3];

	ifstream file;
	string text;

	file.open("presets.txt");

	if (file.good())
	{
		// for array rows
		int i = 0;

		while (getline(file, text))
		{
			// initialize stringstream inside the loop needed for second iteration 
			stringstream ss;

			// for array collumns
			int j = 0;

			// send line to stringstream
			ss << text;
			string temp;
			
			// variable for ints found in text line
			int found;
			while (!ss.eof())
			{
				// send word to temp
				ss >> temp;

				// if int found
				if (stringstream(temp) >> found)
				{
					//cout << "found: " << found;
					presets[i][j] = found;
					//cout << presets[i][j] << endl;
					j++;
				}
			}
			// clearing stringstream does not work (skips second iteration), initializing stringstream at the begining of the loop
			//ss.str("");
			i++;
		}
	}
	else
	{
		cout << "Presets file couldn't be opened";

	}
	file.close();

	// from array to vector
	vector<vector<int>> presetsVtr = { vector<int>(begin(presets[0]), end(presets[0])), vector<int>(begin(presets[1]), end(presets[1])) };
	/*for (int i = 0; i < 3; )
	{
		cout << presetsVtr[1][i] << endl;
		++i;
	}*/
	return presetsVtr;
}

// display presets from presets.txt
void Menu::displayPresets(vector<vector<int>> presets)
{
	char presetChoice;
	int presetOne[3];
	int presetTwo[3];

	cout << "Presets";

	for (int i = 0; i < 3;)
	{
		cout << i;
		presetOne[i] = presets[0][i];
		presetTwo[i] = presets[1][i];
		i++;
	}

	// presets menu
	system("cls");
	cout << "Press 1 for preset one:\n" << "intervals " << presetOne[0] << " |interval duration " << presetOne[1] * 10<< "s |loops " << presetOne[2] << endl;
	cout << "Press 2 for preset two:\n" << "intervals " << presetTwo[0] << " |interval duration " << presetTwo[1] * 10<< "s |loops " << presetTwo[2] << endl;

	while( !(cin>>presetChoice) || (presetChoice < 1  && presetChoice > 2))
	{
		cout << presetChoice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "wrong input! please enter again \n";
	}

	// run witch choosen values
	switch (presetChoice)
	{
	case '1':
		Stopwatch::run(presetOne[0], presetOne[1], presetOne[2]);
		break;
	case '2':
		Stopwatch::run(presetTwo[0], presetTwo[1], presetTwo[2]);
		break;
	default:
		cout << "wrong input!" << endl;
		cin >> presetChoice;
	}
}

// user input values function
void Menu::runInput()
{
	int intervals =0;
	int intervalDuration = 0;
	int loops = 0;
	vector<int> inputData;
	system("cls");

	// put values into vector with different validation intervals, duration, loops
	cout << "\n\t\tSet number of intervals: ";
	inputData.push_back(this->wrongInput(intervals, 0, 100));
	cout << "\n\t\tSet interval duration x10 sec: ";
	inputData.push_back(this->wrongInput(intervalDuration, 0, 11));
	cout<< "\n\t\tSet number of loops: ";
	inputData.push_back(this->wrongInput(loops, 0, 11));

	/*for (vector<int>::iterator i = inputData.begin(); i != inputData.end(); ++i)
	{
		cout << *i;
	}*/

	// run stopwatch with given values
	Stopwatch::run(inputData[0], inputData[1], inputData[2]);
}

// return value for runInput(), after validation
int Menu::wrongInput(int input, int val1, int val2)
{
	while (!(cin >> input) || (input < val1 || input > val2))
	{
		cout << input;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "wrong input! please enter again \n";
	}
	return input;
}

Menu::~Menu()
{
}
