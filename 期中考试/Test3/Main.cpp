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

	cout << "建立的二叉树先序遍历：";
	bt.PreorderTraverse(Print);
	cout << endl;

	cout << "建立的二叉树中序遍历：";
	bt.InorderTraverse(Print);
	cout << endl;

	system("pause");
	return 0;
}