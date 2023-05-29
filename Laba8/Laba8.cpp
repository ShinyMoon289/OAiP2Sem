#include <iostream>
#include<locale>
using namespace std;
unsigned int** buildMatrix()
{
	unsigned int** smezhMatrix = new unsigned int* [5];
	for (unsigned int i = 0; i < 5; i++)
	{
		smezhMatrix[i] = new unsigned int[5];
		for (unsigned int g = 0; g < 5; g++)
		{
			smezhMatrix[i][g] = 0;
		}
	}
	smezhMatrix[0][1] = 2;
	smezhMatrix[0][2] = 3;
	smezhMatrix[0][3] = 1;

	smezhMatrix[1][2] = 4;
	smezhMatrix[1][3] = 1;
	smezhMatrix[1][4] = 3;

	smezhMatrix[2][3] = 4;

	smezhMatrix[3][4] = 2;
	return smezhMatrix;
}

void showMatrix(unsigned int** matr,unsigned int n,unsigned  int m)
{
	cout << "  ";
	for (unsigned int i = 0; i < n; i++)
	{
		cout << i << " ";
	}
	cout << endl;
	for (unsigned int i = 0; i < m; i++)
	{
		cout << i << " ";
		for (unsigned int g = 0; g < 5; g++)
		{
			cout << matr[i][g] << " ";
		}
		cout << endl;
	}
}

unsigned int** deleteOnes(unsigned int** matr)
{
	for (unsigned int i = 0; i < 5; i++)
	{
		for (unsigned int g = 0; g < 5; g++)
		{
			if (matr[i][g] == 1) matr[i][g] = 0;
		}
		cout << endl;
	}
	return matr;
}

void deleteThree(unsigned int** matr)
{
	for (unsigned int i = 0; i < 5; i++)
	{
		matr[i][3] = 0;
		for (unsigned int g = 0; g < 5; g++)
		{
			matr[3][g] = 0;
		}
	}
	
	cout << endl;
	cout << "  ";
	for (unsigned int i = 0; i < 5; i++)
	{
		if (i == 3) continue;
		cout << i << " ";
	}
	cout << endl;
	for (unsigned int i = 0; i < 5; i++)
	{
		if (i == 3) continue;
		cout << i << " ";
		for (unsigned int g = 0; g < 5; g++)
		{
			if (g == 3) continue;
			cout << matr[i][g] << " ";
		}
		cout << endl;
	}


}

int main()
{
	setlocale(LC_ALL, "russian");
	unsigned int** newMatrix = buildMatrix();
	while(true)
	{
		
		cout << endl << "МЕНЮ" << endl;
		for (unsigned int i = 0; i < 11; i++) cout << "_";
		cout << endl;
		cout << "1. Посмотреть оригинальную матрицу" << endl;
		cout << "2. Удалить ребра с номером 1 и показать" << endl;
		cout << "3. Удалить вершину 3" << endl;
		cout << "4. Выйти из программы" << endl;
		for (unsigned int i = 0; i < 11; i++) cout << "_";
		cout << endl << endl;
		cout << "Ваш выбор: ";
		unsigned int chooser;
		cin >> chooser;
		switch (chooser)
		{
		case 1:
		{
			showMatrix(newMatrix, 5, 5);
			break;
		}
		case 2:
		{
			deleteOnes(newMatrix);
			break;
		}
		case 3:
		{
			deleteThree(newMatrix);
			break;
		}
		case 4:
		{
			return 0;
			break;
		}
		}
	}
	
}

