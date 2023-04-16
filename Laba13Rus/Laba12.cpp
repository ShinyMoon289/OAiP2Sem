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
			displayQueue();
			break;
		}
		case 2:
		{
			fillQueue();
			break;
		}
		case 3:
		{
			cout << ochered.size();
			break;
		}
		case 4:
		{
			while (!ochered.empty()) ochered.pop();
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

