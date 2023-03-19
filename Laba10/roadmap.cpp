#include"roadmap.h"
#include<string>
#include<iostream>
using namespace std;

roadmap::roadmap() {}
roadmap::~roadmap() {}

string roadmap::getCarName()
{
	return name;
}
void roadmap::setCarName(string carname)
{
	name = carname;
}

string roadmap::getCarOwner()
{
	return owner;
}
void roadmap::setCarOwner(string own)
{
	owner = own;
}

char roadmap::getCarCategory() { return category; }
void roadmap::setCarCategory(char cat) { category = cat; }

int roadmap::getCarMileage() { return mileage; }
void roadmap::setCarMileage(int mil) { mileage = mil; }

int roadmap::getCarSerialNumber() { return SerialNum; }
void roadmap::setCarSerialNumber(int serial) { SerialNum = serial; }



void roadmap::editRoadmap()
{
	int chooser;
	cout << "Which field do you want to edit?" << endl;
	cout << "1. Name" << endl;
	cout << "2. Owner" << endl;
	cout << "3. Mileage" << endl;
	cout << "4. Serial Number" << endl;
	cout << "5. Cancel" << endl;

	do
	{
		cin >> chooser;
		while (!cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} while (chooser > 5 && chooser < 1);
	switch (chooser)
	{
	case 1:
	{
		string newname;
		cout << "Enter new name: ";
		getline(cin, newname);
		setCarName(newname);
		break;
	}
	case 2:
	{
		string newowner;
		cout << "Enter new owner: ";
		getline(cin, newowner);
		setCarName(newowner);
		break;
	}
	case 3:
	{
		int newmileage;
		cout << "Enter new mileage: ";

		do
		{
			cin >> newmileage;
			while (!cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		} while (newmileage < 0);
		setCarMileage(newmileage);
		break;
	}
	case 4:
	{
		int newserial;
		cout << "Enter new serial number: ";

		do
		{
			cin >> newserial;
			while (!cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		} while (newserial < 0);
		setCarMileage(newserial);
		break;
	}
	case 5:break;
	default: break;
	}
}

void roadmap::displayRoadmap()
{
	cout << "Car name: " << getCarName() << ".\t";
	cout << "Owner: " << getCarOwner() << ".\t";
	cout << "Category: " << getCarCategory() << ".\t";
	cout << "Mileage: " << getCarMileage() << ".\t";
	cout << "Serial number: " << getCarSerialNumber() << ".";
	cout << endl;
}

void roadmap::clearRoadmap()
{
	setCarName("");
	setCarOwner("");
	setCarCategory(' ');
	setCarMileage(0);
	setCarSerialNumber(0);
}
