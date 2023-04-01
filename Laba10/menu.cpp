#include"menu.h"
#include<iostream>
using namespace std;

menu::menu(){}
menu::~menu(){}
std::vector <roadmap> listOfRoadmaps;
void menu::deleteRoadmap(int num)
{
	listOfRoadmaps.erase(listOfRoadmaps.cbegin()+num);
}
void menu::addRoadmap()
{
	roadmap newroadmap;
	cout << "Do you wish to fill out the roadmap right now?y or n";
	char choose;
	cin >> choose;
	if (choose == 'y')
	{
		string newName,newOwner;
		char newCat;
		int newSerial, newMile;

		cout << "Enter name: ";
		cin.ignore();
		getline(cin, newName);
		newroadmap.Name = newName;
		
		cout << "Enter owner: ";
		getline(cin, newOwner);
		newroadmap.Owner = newOwner;

		cout << "Enter mileage: ";
		do
		{
			cin >> newMile;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		} while (newMile < 0);
		newroadmap.Mileage = newMile;

		cout << "Enter new serial number: ";
		do
		{
			cin >> newSerial;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		} while (newSerial < 0);
		newroadmap.SerialNum = newSerial;
		cout << "Enter new Category: ";
		cin >> newCat;
		newroadmap.Category = newCat;
	}
	listOfRoadmaps.push_back(newroadmap);
}
void menu::editRoadmap(int num)
{
	int chooser;
	cout << "Which field do you want to edit?" << endl;
	cout << "1. Name" << endl;
	cout << "2. Owner" << endl;
	cout << "3. Mileage" << endl;
	cout << "4. Serial Number" << endl;
	cout << "5. Category" << endl;
	cout << "6. Cancel" << endl;

	do
	{
		cin >> chooser;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (chooser > 6 && chooser < 1);
	switch (chooser)
	{
	case 1:
	{
		string newname;
		cout << "Enter new name: ";
		getline(cin, newname);
		listOfRoadmaps[num].Name = newname;
		break;
	}
	case 2:
	{
		string newowner;
		cout << "Enter new owner: ";
		getline(cin, newowner);
		listOfRoadmaps[num].Name=newowner;
		break;
	}
	case 3:
	{
		int newmileage;
		cout << "Enter new mileage: ";

		do
		{
			cin >> newmileage;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		} while (newmileage < 0);
		listOfRoadmaps[num].Mileage=newmileage;
		break;
	}
	case 4:
	{
		int newserial;
		cout << "Enter new serial number: ";

		do
		{
			cin >> newserial;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		} while (newserial < 0);
		listOfRoadmaps[num].SerialNum= newserial;
		break;
	}
	case 5:
	{
		char newCat;
		cout << "Enter new Category: ";
		cin >> newCat;
		listOfRoadmaps[num].Name = newCat;
		break;
	}
	case 6:break;
	default: break;
	}
}

void menu::displayRoadmaps()
{
	for (int num = 0; num < listOfRoadmaps.size(); num++)
	{
		cout << endl<<endl;
		cout << "Car name: " << listOfRoadmaps[num].Name << ".\t";
		cout << "Owner: " << listOfRoadmaps[num].Owner << ".\t";
		cout << "Category: " << listOfRoadmaps[num].Category << ".\t";
		cout << "Mileage: " << listOfRoadmaps[num].Mileage << ".\t";
		cout << "Serial number: " << listOfRoadmaps[num].SerialNum << ".";
		cout << endl;
	}
}

void menu::clearRoadmap(int num)
{
	listOfRoadmaps[num].Name = " ";
	listOfRoadmaps[num].Owner = " ";
	listOfRoadmaps[num].Category = ' ';
	listOfRoadmaps[num].Mileage = 0;
	listOfRoadmaps[num].SerialNum = 0;
}

void menu::displayMenu()
{
	cout << "MENU" << endl;
	for (unsigned int i = 0; i < 11; i++) cout << "_";
	cout << endl;
	cout << "1. Display all roadmaps" << endl;
	cout << "2. Add a new roadmap" << endl;
	cout << "3. Edit a roadmap" << endl;
	cout << "4. Clear a roadmap" << endl;
	cout << "5. Delete a roadmap" << endl;
	cout << "0. Quit program " << endl;
	for (unsigned int i = 0; i < 11; i++) cout << "_";
	cout << endl;
}
