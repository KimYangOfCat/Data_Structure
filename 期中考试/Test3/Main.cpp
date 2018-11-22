#include <iostream>
#include "BiTree.h"
using namespace std;

void Print(const char &e)
{
	cout << e << " ";
}

int main()
{
	BinaryTree<char> bt;
	
	bt.Create1("abd##eg##h##cf###", '#');

	cout << "�����Ķ��������������";
	bt.PreorderTraverse(Print);
	cout << endl;

	cout << "�����Ķ��������������";
	bt.InorderTraverse(Print);
	cout << endl;

	system("pause");
	return 0;
}