
/*

-Chapter 8. Ʈ��
- Ʈ���� "������ ����"�� ǥ���ϴ� "������ �ڷᱸ��"�� �ش��Ѵ�.
- Ʈ���� ���� : �׷����� ��������, ���� ��尡 �� ��带 ����ų �� ���� ����.�����ϰԴ� ȸ��(Cycle)�� ����, ���� �ٸ� �� ��带 �մ� ���� �ϳ����� �׷����� Ʈ����� �θ���. (Ʈ������ �ֻ��� ��带 ��Ʈ ����� �Ѵ�.)

- Ʈ���� ��� : ���(node) = ����(vertex), ����(edge), ��Ʈ ��Ʈ(root node), �� ���(leaf node) = ���� ���(internal node), non - leaf node = terminal node
- Ʈ���� ��� : �θ� ���(parent node), �ڽ� ���(child node), ���� ���(sibling node), ����(uncle), ����(ancestor), �ļ�(descendant)
- Ʈ���� ��� : ���� Ʈ��(Binary Tree)�� ���� Ʈ��(Sub Tree), ��ȭ ���� Ʈ��(Full Binary Tree), ���� ���� Ʈ��(Complete Binary Tree)

- ���� Ʈ��(Binary Tree)�� �����ϱ� - �迭�� �����ϱ� vs linked list�� �����ϱ�
- ���� Ʈ���� ��ȸ(Traversal) : ���� ��ȸ(Preorder Traversal), ���� ��ȸ(Inorder Traversal), ���� ��ȸ(Postorder Traversal)

���� 319p���� Ŀ������

< ���� �ֱ��� �����ؾ� �� ����(����) >->�Ʒ� �������� Week 6->�ڱ� �̸����� �� ������ �ø� ��
1. Week 6 ���� �����ϱ�(�����ð��� �߰�����)
2. å 320 ~336p ���� Ʈ�� �����ϱ�(330p ExpressionTree.h, ExpressionTree.c, 332p ExpressionMain.c), ** �������� : ���� 08 - 2, 334 ~336p�� �ִ� �ҽ� �߰��ϱ�
3. Ʈ�� ���� ���� ������ �ϳ� Ǯ��
���� 8���� ������ ��, �ڽ��� �� �� �ִ� ������ �ϳ� ��� Ǯ��, 12 / 30(��)�� �ٸ� ����� �տ��� �� ������ ����� ������ �� �־�� ��!
���ؿ� judge���� ���(���� ĸó)�� �ҽ� �ڵ带 github�� �ø���(Week 6->�ڱ� �̸����� �� ������ �ø� ��)

*/

#include <iostream>
#include "ExpressionTree.h"

using namespace std;

int main(void)
{
	char exp[] = "25+11+*";
	BTreeNode* eTree = MakeExpTree(exp);

	cout << "���� ǥ���\n";
	ShowPrefixTypeExp(eTree);
	cout << endl;

	cout << "���� ǥ���\n";
	ShowInfixTypeExp(eTree);
	cout << endl;

	cout << "���� ǥ���\n";
	ShowPostfixTypeExp(eTree);
	cout << endl;

	cout << "���� ���: " << EvaluateExpTree(eTree) << endl;

	return 0;
}