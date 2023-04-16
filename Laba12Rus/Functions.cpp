#include"Functions.h"
#include<string>
#include <iostream>
#include<stack>

using namespace std;

std::stack<int> stek;

extern void intCheck()
{
	while (cin.fail())
	{
		cout << "Incorrect input!";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}

extern void displayElements()
{
	while (!stek.empty())
	{
		cout << stek.top() << " ";
		stek.pop();
	}
}


extern unsigned int getMenu()
{
	cout << endl << "Меню" << endl;
	for (unsigned int i = 0; i < 11; i++) cout << "_";
	cout << endl;
	cout << "1. Отобразить стек" << endl;
	cout << "2. Ввести стек" << endl;
	cout << "3. Размер стека" << endl;
	cout << "4. Очистить стек" << endl;
	cout << "0. Выйти из программы " << endl;
	for (unsigned int i = 0; i < 11; i++) cout << "_";
	cout << endl << endl;
	cout << "Ваш ввод: ";
	unsigned int chooser;
	do
	{
		cin >> chooser;
		intCheck();
	} while (chooser < 0 || chooser>4);
	return chooser;
}

extern void fillStack()
{
	cout << "Введите размер стека: ";
	unsigned int size;
	do
	{
		cin >> size;
	} while (size < 0);
	int element;
	for (unsigned int i = 0; i < size; ++i)
	{
		cin >> element;
		stek.push(element);
	}
}