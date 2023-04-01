#include<string>
#include<vector>
#pragma once


struct roadmap
{
public:
	
	std::string Name=" ";
	std::string Owner=" ";
	char Category=' ';
	int Mileage=0, SerialNum=0;
};

class menu
{
	
public:
	menu();
	~menu();
	void editRoadmap(int);
	void addRoadmap();
	void deleteRoadmap(int);
	void clearRoadmap(int);
	void displayMenu();
	void displayRoadmaps();
};
extern std::vector <roadmap> listOfRoadmaps;


