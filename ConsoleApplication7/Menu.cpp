#include "pch.h"
#include "Menu.h"
#include "Stopwatch.h"
#include <iostream>
//#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

Menu::Menu()
{
}

// array of menu choices
string menuItems[] = {"Start simple stopwatch", "Set intervals and start", "Use preset 1", "Use preset 2", "Quit"};

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


	//if (itemNumber > sizeof(menuItemsPtr) && itemNumber < sizeof(menuItemsPtr)) 
	////if(cin.fail())
	//{
	//	
	//	cout << "wrong input!";
	//	cin.clear();

	//	choice();
	//}
	//else
	//{
		switch (itemNumber)
		{
			// runs simple stopwatch, no beep
		case '1':
			Stopwatch::run(0);
			break;
 
		case '2':
			cout << "enter 2";
			break;
		case '3':
			cout << "enter 3";
			break;
		case '4':
			cout << "enter 4";
			break;

			// throw exception to exit, catch in main()
		case '5':
			throw 0;
			//break;

			// wrong input case, clear console, show menu
		default:
			cout << "wrong input!" << endl;
			//cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.sync();
			itemNumber = 0;
			system("pause");
			system("cls");
			this->display();
			this->choice();
		}
	//}
}

int Menu::exit()
{
	cout << "exit";
	return 0;
}

Menu::~Menu()
{
}
