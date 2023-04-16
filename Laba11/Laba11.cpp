#include"Functions.h"
#include<iostream>
using namespace std;

int main()
{
	while (true)
	{
		switch (getMenu())
		{
		case 1:
		{
			displayInfos();
			break;
		}
		case 2:
		{
			addInfo();
			break;
		}
		case 3:
		{
			cout<<getSize();
			break;
		}
		case 4:
		{
			listOfInfos.clear();
			break;
		}
		case 5:
		{
			cout << findMax().Name;
			break;
		}
		case 6:
		{
			cout << findMin().Name;
			break;
		}
		case 7:
		{
			listOfInfos.unique(sameName);
			break;
		}
		case 8:
		{
			listOfInfos.sort(nameCompare);
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

