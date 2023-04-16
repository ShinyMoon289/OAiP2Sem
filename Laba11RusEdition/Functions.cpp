#include"Functions.h"
#include<string>
#include <iostream>

using namespace std;

std::forward_list<information> listOfInfos;


extern void intCheck()
{
	while (cin.fail())
	{
		cout << "������������ ����!";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}

const information getInfo(std::forward_list<information>::const_iterator itr)
{
	return *itr;
}

extern void displayInfos()
{
	for (std::forward_list<information>::const_iterator itr = listOfInfos.cbegin(); itr != listOfInfos.cend(); ++itr)
	{
		cout << endl;
		for (unsigned int i = 0; i < 30; ++i) cout << "_";
		cout << endl;
		cout << "��������: "<< getInfo(itr).Name << endl;
		cout << "�����: " << getInfo(itr).Author << endl;
		cout << "��������: " << getInfo(itr).Medium << endl;
		cout <<"�����: " << getInfo(itr).Volume << endl;

	}
}

extern unsigned int getSize()
{
	unsigned int count=0;
	for (std::forward_list<information>::const_iterator itr = listOfInfos.cbegin(); itr != listOfInfos.cend(); ++itr)
	{
		count++;
	}
	return count;
}

extern void addInfo()
{
	information newinfo;

	char chooser;
	cout << "������ ��������� ������� ������? y or n";
	cin >> chooser;
	if (chooser == 'y')
	{
		

		string newName, newAuthor, newMedium;
		unsigned int newvolume = 0;
		
		cout << "������� ���: ";
		cin.ignore();
		getline(cin, newName);
		newinfo.Name = newName;

		cout << "������� ������: ";
		getline(cin, newAuthor);
		newinfo.Author = newAuthor;

		cout << "������� ��������: ";
		getline(cin, newMedium);
		newinfo.Medium = newMedium;

		cout << "������� �����: ";
		do
		{
			cin >> newvolume;
			intCheck();
		} while (newvolume < 0);
		newinfo.Volume = newvolume;

	
	}
	listOfInfos.push_front(newinfo);
}

extern unsigned int getMenu()
{
	cout <<endl<< "����" << endl;
	for (unsigned int i = 0; i < 11; i++) cout << "_";
	cout << endl;
	cout << "1. �������� ��� ��������" << endl;
	cout << "2. �������� ����� �������" << endl;
	cout << "3. ��������� ����� ������" << endl;
	cout << "4. �������� ������" << endl;
	cout << "5. ����� ���������� ������� �� ������" << endl;
	cout << "6. ����� ���������� ������� �� ������" << endl;
	cout << "7. ������� ������������� ��������" << endl;
	cout << "8. ������������� �� �����" << endl;
	cout << "0. ����� �� ��������� " << endl;
	for (unsigned int i = 0; i < 11; i++) cout << "_";
	cout << endl << endl;
	cout << "��� ����: ";
	unsigned int chooser;
	do
	{
		cin >> chooser;
		intCheck();
	} while (chooser < 0 || chooser>8);
	return chooser;
}

extern bool nameCompare(const information& info1, const information& info2)
{
	return info1.Name[0] <= info2.Name[0];
}

extern bool sameName(const information &info1,const information &info2)
{
	return  info1.Name == info2.Name;
}

extern bool maxVol(const information& info1, const information& info2)
{
	return  info1.Volume > info2.Volume;
}
extern const information findMax()
{
	listOfInfos.sort(maxVol);
	auto itr = listOfInfos.cbegin();
	return *itr;
}

extern const information findMin()
{
	listOfInfos.sort(maxVol);
	auto itr = listOfInfos.cend();
	return *itr;
}