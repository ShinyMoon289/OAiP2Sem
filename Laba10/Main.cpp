#include <iostream>
#include "menu.h"
using namespace std;



int main()
{
	menu Menu;
	unsigned int clicker;
	while (true)
	{
		Menu.displayMenu();
		do
		{
			cin >> clicker;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		} while (clicker > 5 && clicker < 0);

		switch (clicker)
		{
		case 1:
		{
			Menu.displayRoadmaps();
			break;
		}
		case 2:
		{
			Menu.addRoadmap();
			break;
		}
		case 3:
		{
			cout << "Which roadmap you want to edit: ";
			do
			{
				cin >> clicker;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
			} while (clicker <0 || clicker > listOfRoadmaps.size());
			Menu.editRoadmap(clicker);
			break;
		}
		case 4:
		{
			cout << "Which roadmap you want to delete: ";
			cin >> clicker;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
				if (clicker <0 || clicker > listOfRoadmaps.size())
				{
					cout << "Incorrect input!" << endl;
					break;
				}
			Menu.deleteRoadmap(clicker);
			break;
		}
		case 5:
		{
			cout << "Which roadmap you want to clear: ";
			cin >> clicker;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			if (clicker <0 || clicker > listOfRoadmaps.size())
			{
				cout << "Incorrect input!"<<endl;
				break;
			}
			Menu.clearRoadmap(clicker);
			break;
		}
		case 0:
		{
			return 0;
			break;
		}
		}
	}
}
