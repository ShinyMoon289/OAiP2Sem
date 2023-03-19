#pragma once

extern class roadmap
{
	string name; 
	string owner;
	char category;
	int mileage, SerialNum;
public:

	roadmap();
	~roadmap();

	
	void displayRoadmap();
	void editRoadmap();
	void clearRoadmap();

	string getCarName();
	void setCarName(string);

	string getCarOwner();
	void setCarOwner(string);

	char getCarCategory();
	void setCarCategory(char);

	int getCarMileage();
	void setCarMileage(int);

	int getCarSerialNumber();
	void setCarSerialNumber(int);
};



