#include<iostream>
#include "ExpressionTree.h"
using namespace std;
int main(void) 
{
	char exp[] = "12+7*";
	BTreeNode * eTree = MakeExpTree(exp);

	cout << "���� ǥ����� ����: ";
	ShowPrefixTypeExp(eTree); cout << '\n';

	cout<<"���� ǥ����� ����: ";
	ShowInfixTypeExp(eTree); cout << '\n';

	cout<<"���� ǥ����� ����: ";
	ShowPostfixTypeExp(eTree); cout << '\n';

	cout << "������ ���:" << EvaluateExpTree(eTree) << "\n";

	DeleteTree(eTree);

	return 0;
}