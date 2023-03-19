#include <iostream>
#include "roadmap.h"
#include<string>
#include<vector>
using namespace std;

vector<roadmap> listOfRoadmaps;

void deleteRoadmap();
void addRoadmap();
void displayMenu();
void displayAllRoadmaps();

int main()
{
	int clicker;
	while (true)
	{
		displayMenu();
		do
		{
			cin >> clicker;
			while (!cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		} while (clicker > 5 && clicker < 0);

		switch (clicker)
		{
		case 1:
		{
			displayAllRoadmaps();
		}
		case 2:
		{
			addRoadmap();
		}
		case 3:
		{
			cout << "Which roadmap you want to edit: ";
			do
			{
				cin >> clicker;
				while (!cin.fail())
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
			} while (clicker > 5 && clicker < listOfRoadmaps.size());
			listOfRoadmaps[clicker].editRoadmap();
		}
		case 4:
		{
			deleteRoadmap();
		}
		case 5:
		{
			cout << "Which roadmap you want to clear: ";
			do
			{
				cin >> clicker;
				while (!cin.fail())
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
			} while (clicker > 5 && clicker < listOfRoadmaps.size());
			listOfRoadmaps[clicker].clearRoadmap();
		}
		case 0:
		{
			return 0;
			break;
		}
		}
	}
}

void deleteRoadmap()
{
	int num;
	cout << "Which roadmap do you want to delete?";
	listOfRoadmaps.erase(listOfRoadmaps.begin() + num);
}
void addRoadmap()
{
	roadmap newroadmap;
	listOfRoadmaps.push_back(newroadmap);
}
void displayMenu()
{
	cout << "MENU:" << endl;
	cout << "1. Display all roadmaps" << endl;
	cout << "2. Add a new roadmap" << endl;
	cout << "3. Edit a roadmap" << endl;
	cout << "4. Delete a roadmap" << endl;
	cout << "5. Clear a roadmap" << endl;
	cout << "0. Exit the program" << endl;
}

void displayAllRoadmaps()
{
	for (int i = 0; i < listOfRoadmaps.size(); i++)
	{
		listOfRoadmaps[i].displayRoadmap();
	}
}