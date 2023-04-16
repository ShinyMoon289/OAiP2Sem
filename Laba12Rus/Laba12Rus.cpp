#include"Functions.h"
#include <iostream>
#include<locale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	while (true)
	{
		switch (getMenu())
		{
		case 1:
		{
			displayElements();
			break;
		}
		case 2:
		{
			fillStack();
			break;
		}
		case 3:
		{
			cout << stek.size();
			break;
		}
		case 4:
		{
			while (!stek.empty()) stek.pop();
			break;
		}
		case 0:
		{
			return 0;
			break;
		}
		}
	}
	switch (getMenu())
	{
	case 1:
	{
		displayElements();
		break;
	}
	case 2:
	{
		fillStack();
		break;
	}
	case 3:
	{
		cout << stek.size();
		break;
	}
	case 4:
	{
		while (!stek.empty()) stek.pop();
		break;
	}
	case 0:
	{
		return 0;
		break;
	}
	}
}

