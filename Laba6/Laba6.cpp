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
		cout << endl << "����" << endl;
		for (unsigned int i = 0; i < 11; i++) cout << "_";
		cout << endl;
		cout << "1. �������� ������� ������" << endl;
		cout << "2. ���������� ���������� ��������� ������" << endl;
		cout << "3. ������� ������� �� �����" << endl;
		cout << "4. ����� ������� �� �����" << endl;
		cout << "5. ���������� ��� ��������" << endl;
		cout << "6. ����� �� ���������" << endl;
		for (unsigned int i = 0; i < 11; i++) cout << "_";
		cout << endl << endl;
		cout << "��� �����: ";
		unsigned int chooser;
		cin >> chooser;
		switch (chooser)
		{
		case 1:
		{
			cout << "�� ������ �������� ������� ������ ��� �����? l or r";
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
			cout << "������� ����, �� �������� ����� ������� ����: ";
			unsigned int newkey;
			cin >> newkey;
			deleteANode(root, newkey);
			break;
		}
		case 4:
		{
			cout << "������� ����, �� �������� ����� ����� ����: ";
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

