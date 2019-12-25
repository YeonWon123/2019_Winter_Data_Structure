
/*

-Chapter 8. 트리
- 트리는 "계층적 관계"를 표현하는 "비선형적 자료구조"에 해당한다.
- 트리의 정의 : 그래프의 일종으로, 여러 노드가 한 노드를 가리킬 수 없는 구조.간단하게는 회로(Cycle)가 없고, 서로 다른 두 노드를 잇는 길이 하나뿐인 그래프를 트리라고 부른다. (트리에서 최상위 노드를 루트 노드라고 한다.)

- 트리의 용어 : 노드(node) = 정점(vertex), 간선(edge), 루트 노트(root node), 잎 노드(leaf node) = 내부 노드(internal node), non - leaf node = terminal node
- 트리의 용어 : 부모 노드(parent node), 자식 노드(child node), 형제 노드(sibling node), 사촌(uncle), 조상(ancestor), 후손(descendant)
- 트리의 용어 : 이진 트리(Binary Tree)와 서브 트리(Sub Tree), 포화 이진 트리(Full Binary Tree), 완전 이진 트리(Complete Binary Tree)

- 이진 트리(Binary Tree)를 구현하기 - 배열로 구현하기 vs linked list로 구현하기
- 이진 트리의 순회(Traversal) : 전위 순회(Preorder Traversal), 중위 순회(Inorder Traversal), 후위 순회(Postorder Traversal)

따라서 319p까지 커버했음

< 다음 주까지 정리해야 할 사항(과제) >->아래 과제들을 Week 6->자기 이름으로 된 폴더에 올릴 것
1. Week 6 폴더 정리하기(수업시간에 했겠지만)
2. 책 320 ~336p 수식 트리 구현하기(330p ExpressionTree.h, ExpressionTree.c, 332p ExpressionMain.c), ** 도전과제 : 문제 08 - 2, 334 ~336p에 있는 소스 추가하기
3. 트리 관련 백준 문제를 하나 풀기
다음 8개의 문제들 중, 자신이 할 수 있는 문제를 하나 골라서 풀고, 12 / 30(월)에 다른 사람들 앞에서 이 문제와 답안을 설명할 수 있어야 함!
백준에 judge받은 기록(사진 캡처)과 소스 코드를 github에 올리기(Week 6->자기 이름으로 된 폴더에 올릴 것)

*/

#include <iostream>
#include "ExpressionTree.h"

using namespace std;

int main(void)
{
	char exp[] = "25+11+*";
	BTreeNode* eTree = MakeExpTree(exp);

	cout << "전위 표기법\n";
	ShowPrefixTypeExp(eTree);
	cout << endl;

	cout << "중위 표기법\n";
	ShowInfixTypeExp(eTree);
	cout << endl;

	cout << "후위 표기법\n";
	ShowPostfixTypeExp(eTree);
	cout << endl;

	cout << "연산 결과: " << EvaluateExpTree(eTree) << endl;

	return 0;
}