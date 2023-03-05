#include <iostream>		
#include<iomanip>
using namespace std;

void displayMatrix(int** arrPntr,int rows,int columns) //display the array
{
	setw(4);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << arrPntr[i][j] << "  ";
		}
		cout << endl;
	}
}
void sortMatrix(int** arrPntr, int rows, int columns)		//sort the array using insertion
{
	int length = rows;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 1; j < length; j++)
		{
			int cntr = j;
			if (i % 2 == 1)
			{
				while (cntr > 0 && arrPntr[i][cntr - 1] > arrPntr[i][cntr])
				{
					swap(arrPntr[i][cntr - 1], arrPntr[i][cntr]);
					cntr--;
				}
			}
			else
			{
				while (cntr > 0 && arrPntr[i][cntr - 1] < arrPntr[i][cntr])
				{
					swap(arrPntr[i][cntr - 1], arrPntr[i][cntr]);
					cntr--;
				}
			}
			
		}
	}
}

int main()
{
	srand(time(NULL));	//seed for rand() function
	int rows = 0, columns = 0;
	cout << "Enter rows and columns no greater than 30: ";
	do
	{
		cin >> rows >> columns;
	} while (rows > 30 || columns > 30);
	int** arrayPtr = new int* [columns];	//dynamically allocating memory for the array
	for (int cntr = 0; cntr < columns; cntr++)
		arrayPtr[cntr] = new int[rows];
	if (!arrayPtr)
	{
		cout << "Not enough memory!";
	}
	for (int i = 0; i < rows; i++)	//filling the array
	{
		for (int j = 0; j < columns; j++)
		{
			arrayPtr[i][j] = rand() % 100;
		}
	}
	cout << "The original matrix is: " << endl;
	displayMatrix(arrayPtr,rows,columns);
	sortMatrix(arrayPtr,rows,columns);
	cout << "The sorted matrix is: " << endl;
	displayMatrix(arrayPtr,rows,columns);
	delete[]arrayPtr;	//erasing the array
	return 0;
}


