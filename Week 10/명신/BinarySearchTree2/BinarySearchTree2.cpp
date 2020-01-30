#include <iostream>
#include "BinaryTree3.h"
#include "BinarySearchTree2.h"
using namespace std;

void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	BTreeNode* pNode = NULL;	//parent node
	BTreeNode* cNode = *pRoot;	//current node
	BTreeNode* nNode = NULL;	//new node

	//���ο� ��尡 �߰��� ��ġ�� ã�´�.
	while (cNode != NULL) 
	{
		if (data == GetData(cNode)) 
		{
			return;
		}

		pNode = cNode;

		if (GetData(cNode) > data) 
		{
			cNode = GetLeftSubTree(cNode);
		}
		else 
		{
			cNode = GetRightSubTree(cNode);
		}
	}

	//pNode�� �ڽ� ���� �߰��� �� ����� ����
	nNode = MakeBTreeNode();	//�� ����� ����
	SetData(nNode, data);		//�� ��忡 ������ ����

	//pNode�� �ڽ� ���� �� ��带 �߰�
	if (pNode != NULL) 
	{		//�� ��尡 ��Ʈ ��尡 �ƴ϶��,
		if (data < GetData(pNode)) 
		{
			MakeLeftSubTree(pNode, nNode);
		}
		else 
		{
			MakeRightSubTree(pNode, nNode);
		}
	}
	else 
	{						//�� ��尡 ��Ʈ �����,
		*pRoot = nNode;
	}
}

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	BTreeNode* cNode = bst;	//current node
	BSTData cd;				//current data

	while (cNode != NULL) 
	{
		cd = GetData(cNode);

		if (target == cd) 
		{
			return cNode;
		}
		else if (target < cd) 
		{
			cNode = GetLeftSubTree(cNode);
		}
		else 
		{
			cNode = GetRightSubTree(cNode);
		}
	}
	return NULL;		//Ž������� ����Ǿ� ���� ����
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	//���� ����� ��Ʈ ����� ��츦 ������ ����ؾ� �Ѵ�.
	BTreeNode* pVRoot = MakeBTreeNode();	//���� ��Ʈ ���
	BTreeNode* pNode = pVRoot;				//parent node
	BTreeNode* cNode = *pRoot;				//current node
	BTreeNode* dNode;						//delete node

	//��Ʈ ��带 pVRoot�� ����Ű�� ����ǿ����� �ڽ� ��尡 �ǰ� �Ѵ�.
	ChangeRightSubTree(pVRoot, *pRoot);

	//���� ����� ��带 Ž��
	while (cNode != NULL && GetData(cNode) != target) 
	{
		pNode = cNode;
		if (target < GetData(cNode)) 
		{
			cNode = GetLeftSubTree(cNode);
		}
		else 
		{
			cNode = GetRightSubTree(cNode);
		}
	}

	if (cNode == NULL)	//���� ����� �������� �ʴ´ٸ�,
	{
		return NULL;
	}

	dNode = cNode;	//���� ����� dNode�� ����Ű�� �Ѵ�.

	//ù��° ��� : ���� ����� �ܸ� ����� ���
	if (GetLeftSubTree(pNode) == NULL && GetRightSubTree(dNode) == NULL) 
	{
		if (GetLeftSubTree(pNode) == dNode)
		{
			RemoveLeftSubTree(pNode);
		}
		else 
		{
			RemoveRightSubTree(pNode);
		}
	}
	//�ι�° ��� : ���� ����� �ϳ��� �ڽ� ��带 ���� ���
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) 
	{
		BTreeNode* dcNode;	//���� ����� �ڽ� ��� ����Ŵ

		if (GetLeftSubTree(dNode) != NULL) 
		{
			dcNode = GetLeftSubTree(dNode);
		}
		else 
		{
			dcNode = GetRightSubTree(dNode);
		}

		if (GetLeftSubTree(pNode) == dNode) 
		{
			ChangeLeftSubTree(pNode, dcNode);
		}
		else 
		{
			ChangeRightSubTree(pNode, dcNode);
		}
	}
	//����° ��� : �� ���� �ڽ� ��带 ��� ���� ���
	else 
	{
		BTreeNode* mNode = GetRightSubTree(dNode);	//��ü ��� ����Ŵ
		BTreeNode* mpNode = dNode;					//��ü ����� �θ� ��� ����Ŵ
		int delData;

		//���� ����� ��ü ��带 ã�´�.
		while (GetLeftSubTree(mNode) != NULL) 
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		//��ü ����� ����� ���� ������ ��忡 �����Ѵ�.
		delData = GetData(dNode);		//���� �� ������ ���
		SetData(dNode, GetData(mNode));	//����

		//��ü ����� �θ� ���� �ڽ� ��带 �����Ѵ�.
		if (GetLeftSubTree(mpNode) == mNode) 
		{
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		}
		else
		{
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
		}

		dNode = mNode;
		SetData(dNode, delData);	//��� ������ ����
	}

	//������ ��尡 ��Ʈ ����� ��� ���� �߰����� ó��
	if (GetRightSubTree(pVRoot) != *pRoot) 
	{
		*pRoot = GetRightSubTree(pVRoot);	//��Ʈ ����� ������ �ݿ�
	}

	delete pVRoot;	//���� ��Ʈ ����� �Ҹ�
	return dNode;	//���� ����� ��ȯ
}

void ShowIntData(int data)
{
	cout << data << ' ';
}

void BSTShowAll(BTreeNode* bst)
{
	InorderTraverse(bst, ShowIntData);
}