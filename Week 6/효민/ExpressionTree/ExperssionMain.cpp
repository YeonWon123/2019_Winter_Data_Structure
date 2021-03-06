#include <iostream>
#include "Experssion.h"
using namespace std;

int main()
{
	char exp[] = "12+7*";
	BTreeNode* eTree = MakeExpTree(exp);

	cout << "전위 표기법의 수식: ";
	ShowPrefixTypeExp(eTree);
	cout << '\n';

	cout << "중위 표기법의 수식: ";
	ShowInfixTypeExp(eTree);
	cout << '\n';

	cout << "후위 표기법의 수식: ";
	ShowPostfixTypeExp(eTree);
	cout << '\n';

	cout << "연산의 결과 : " << EvaluateExpTree(eTree);

	return 0;
}