#include <iostream>
#include<locale>
#include"BinaryTree.h"
using namespace std;
extern unsigned int counter;
TreeNode* prev;
TreeNode* currNode;
unsigned int keys=0;
int main()
{
	TreeNode* root = NULL;
	srand(time(0));
	setlocale(LC_ALL, "russian");
	root = newBranch();
	currNode = root;
	while (true)
	{
		cout << endl << "МЕНЮ" << endl;
		for (unsigned int i = 0; i < 11; i++) cout << "_";
		cout << endl;
		cout << "1. Добавить элемент дерева" << endl;
		cout << "2. Посмотреть количество элементов справа" << endl;
		cout << "3. Удалить элемент по ключу" << endl;
		cout << "4. Найти элемент по ключу" << endl;
		cout << "5. Посмотреть все элементы" << endl;
		cout << "6. Выйти из программы" << endl;
		for (unsigned int i = 0; i < 11; i++) cout << "_";
		cout << endl << endl;
		cout << "Ваш выбор: ";
		unsigned int chooser;
		cin >> chooser;
		switch (chooser)
		{
		case 1:
		{
			cout << "Вы хотите добавить элемент справа или слева? l or r";
			char ch;
			cin.ignore();
			cin >> ch;
			if (ch == 'l') insertLeft(currNode);
			else insertRight(currNode); 
			break;
		}
		case 2:
		{
			cout << rightSub(root) << endl;
			counter = -1;
			break;
		}
		case 3:
		{
			cout << "Введите ключ, по которому нужно удалить лист: ";
			unsigned int newkey;
			cin >> newkey;
			deleteANode(root, newkey);
			break;
		}
		case 4:
		{
			cout << "Введите ключ, по которому нужно найти лист: ";
			unsigned int newkey;
			cin >> newkey;
			findANode(root,newkey);
			break;
		}
		case 5:
		{
			preorderPrint(root);
			break;
		}
		case 6:
		{
			deleteAll(root);
			return 0;
			break;
		}
		default:
			break;
		}
	}
}

