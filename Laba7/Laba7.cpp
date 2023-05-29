#include <iostream>
#include<random>
#include<time.h>
#include<locale>
#include<algorithm>
using namespace std;

unsigned int divHash(unsigned int key, unsigned int size)
{
	return key % size;
}

int main()
{
	setlocale(LC_ALL, "russian");
	srand(time(0));
	cout << "Введите размер таблицы: ";
	unsigned int size;
	cin >> size;
	unsigned int* hashTab = new unsigned int[size];
	for (unsigned int i = 0; i < size; i++)
	{
		hashTab[i] = divHash(rand(),size);
		cout << hashTab[i] << " ";
	}
	for (unsigned int i = 0; i < size-1 ; i++)
	{
		for (unsigned int g = 0; g < size - i- 1; g++)
		{
			if (hashTab[g] < hashTab[g + 1]) swap(hashTab[g], hashTab[g + 1]);
		}
	}
	cout << endl;
	cout << "Отсортированная хэш-таблица: " << endl;
	for (unsigned int i = 0; i < size; i++)
	{
		cout << hashTab[i] << " ";
	}

}

