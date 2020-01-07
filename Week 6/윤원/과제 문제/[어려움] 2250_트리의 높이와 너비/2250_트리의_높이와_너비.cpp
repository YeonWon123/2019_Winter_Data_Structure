#include <iostream>
#include <vector>
using namespace std;

// #define DEBUG

// Ʈ���� ��带 ��Ÿ��
typedef struct nodes{
	int number; // ����
	int height; // ��� ����
	struct nodes *prev; // �θ� ���
	struct nodes *next1; // �ڽ� ���1
	struct nodes *next2; // �ڽ� ���2
	nodes()
	{
		prev = NULL;
		next1 = NULL;
		next2 = NULL;
	}
} node;

// ���� ����� Ʋ �ȿ� �� ������ �����ϴ� ����ü
// �� ����� �ּҸ� ����
typedef struct lattices {
	node *node_pointer;
} lattice;

// �� Ʈ���� ������ �� �ʺ� �����ϴ� ����ü
typedef struct level_widths{
	int level;
	int start_node;
	int end_node;
	int width;
} level_width;


// �Լ� ���� ����
// ���� ��ȸ �Լ� (��� ȣ�� �̿�)
void preorder(node *tree, int parent_num, int height);
// ���� ��ȸ �Լ� (��� ȣ�� �̿�)
void inorder(node *tree, lattice *lattice, int parent_num, int &width_num);


int main()
{
	int N; // ����� ����
	cin >> N;

	// 1. �θ� ���� �ڽ� ��� ���� ���踦 �����Ͽ� Ʈ���� �����.

	// tree[0]�� ���� �ʰ�, tree[1]���� tree[N]���� ����� ����
	node *tree = new node[N+1];
	for (int i = 1; i <= N; i++)
	{
		tree[i].number = i;
	}
	
	// ����� ������ŭ �ݺ�
	for (int i = 1; i <= N; i++)
	{
		// �θ� ���, �ڽ� ���1, �ڽ� ���2
		int parent, child1, child2;
		cin >> parent >> child1 >> child2;

		// �ڽ� ���1�� -1�� �ƴ� ���, �θ� ���� �ڽ� ���1�� ����
		if (child1 != -1)
		{
			tree[parent].next1 = &tree[child1];
			tree[child1].prev = &tree[parent];
		}

		// �ڽ� ���2�� -1�� �ƴ� ���, �θ� ���� �ڽ� ���2�� ����
		if (child2 != -1)
		{
			tree[parent].next2 = &tree[child2];
			tree[child2].prev = &tree[parent];
		}
	}

	// debug
#ifdef DEBUG
	for (int i = 1; i <= N; i++)
	{
		cout << tree[i].number << " ";
		if (tree[i].next1 == NULL)
			cout << -1 << " ";
		else cout << tree[i].next1->number << " ";

		if (tree[i].next2 == NULL)
			cout << -1 << " ";
		else cout << tree[i].next2->number << " ";

		if (tree[i].prev == NULL)
			cout << -1 << endl;
		else cout << tree[i].prev->number << endl;
	}
#endif

	// 2. ������� ���� Ʈ���� ��Ģ�� ���� ���ʿ��� ���������� ���ڸ� ������ ����

	// ���� ���� ��ȸ���� ���� ���� Ž���Ǵ� ��Ʈ ��带 ã�´�.
	// ��Ʈ ���� � ��忡�� ����ص� ã�� �� �ִ�.
	// �ֳ��ϸ�, ��Ʈ ��常�� �θ� ��尡 NULL�̱� �����̴�.
	int root_num = 1;
	while (1)
	{
		if (tree[root_num].prev == NULL)
			break;

		root_num = tree[root_num].prev->number;
	}
	
	// ���� ����� Ʋ �ȿ� �� ������ �����ϴ� ����ü
	// ���� ��翡�� �� ��ȣ�� lattice[i]���� i�� �� ���̴�.
	// ���� ��翡�� �� ��ȣ�� tree[i].height�� �� ���̴�.
	lattice *latticeboard = new lattice[N+1];


	// ���� ��ȸ�� ���ؼ� ���� Ʈ���� �� ��忡 ���̸� �ο��Ѵ�.
	preorder(tree, root_num, 1);
	
	// ���� ��ȸ�� ���ؼ� ���� Ʈ���� ���ʿ��� ���������� �����Ѵ�.
	int width_num = 1;
	inorder(tree, latticeboard, root_num, width_num);
	
#ifdef DEBUG
	// debug
	for (int i = 1; i <= N; i++)
	{
		cout << latticeboard[i].node_pointer->number << " ";
	}
	cout << endl;
	for (int i = 1; i <= N; i++)
	{
		cout << latticeboard[i].node_pointer->height << " ";
	}
	cout << endl;
#endif

	// 3. ���� �ǿ� ��带 ä�� �־����� ���� �ʺ� ����� ����.
	vector<level_width> data;

	for (int i = 1; i <= N; i++)
	{
		int sw = 0;
		for (unsigned int j = 0; j < data.size(); j++)
		{
			// ���� ������ data[j].level �ȿ� �� ����(����)�� �ִٸ�
			// �̹� �� �� �Է¹��� ���� �ִٴ� �̾߱��̴�.
			// �׷��ٸ� end_node�� �� ��ȣ�� i�� �Ҵ��Ѵ�.
			if (data[j].level == latticeboard[i].node_pointer->height )
			{
				data[j].end_node = i;
				sw = 1;
				break;
			}
		}

		// sw�� 0�̸� �� ����(����)�� data �ȿ� ���ٴ� ���̴�
		// �� ����(����)�� ���� ���� push�� �� �ش�.
		// ���̴� level�� latticeboard[i].node_pointer->height�� �Ҵ��Ѵ�.
		// start_node���� �� ��ȣ�� i���� �Ҵ��ϰ� end_node�� 0���� �Ѵ�.
		// �ʺ�� �� for���� ����������, �������� ����Ѵ�. (�ϴ��� 1���� ��)
		if (sw == 0)
		{
			data.push_back({ latticeboard[i].node_pointer->height,
			i, 0, 1 });
		}
	}

#ifdef DEBUG
	// debug
	cout << endl << "3�� ����" << endl;
	for (unsigned int i = 0; i < data.size(); i++)
	{
		cout << data[i].level << " " << data[i].start_node << " " 
			<< data[i].end_node << endl;
	}
#endif

	// �� ����(�ʺ�)�� ���� �ʺ� ����Ѵ�. 
	for (unsigned int i = 0; i < data.size(); i++)
	{
		data[i].width = data[i].end_node - data[i].start_node + 1;
		if (data[i].width <= 0) data[i].width = 1;
#ifdef DEBUG
		cout << data[i].level << " " << data[i].width << endl;
#endif
	}

	// ���� �ʺ� ���� ���� ������ �����ϴ� �������� �ΰ�,
	// �� ������ ������ ���� ���� ����Ѵ�.
	int wide_level = 10001; // �ʺ� ���� ���� ���� (��û ū ���� �α�)
	int wide = 1;			 // �� ������ �ʺ�		(���� ���� �ڿ����� �α�)

	for (unsigned int i = 0; i < data.size(); i++)
	{
		// ���� ���� ����� �ʺ� �� ������ �ٲٰ�,
		if (wide < data[i].width)
		{
			wide_level = data[i].level;
			wide = data[i].width;
		}
		else if (wide == data[i].width) // ������
		{
			// ���̰� �� ������ Ȯ��
			if (wide_level > data[i].level)
			{
				// ������ ����
				wide_level = data[i].level;
				wide = data[i].width;
			}
		}
	}
	cout << wide_level << " " << wide;
	
	return 0;
}

// ���� ��ȸ �Լ� (��� ȣ�� �̿�)
void preorder(node *tree, int parent_num, int height)
{
	tree[parent_num].height = height;

	if (tree[parent_num].next1 != NULL)
	{
		preorder(tree, tree[parent_num].next1->number, height + 1);
	}

	if (tree[parent_num].next2 != NULL)
	{
		preorder(tree, tree[parent_num].next2->number, height + 1);
	}
}

// ���� ��ȸ �Լ� (��� ȣ�� �̿�)
void inorder(node *tree, lattice *latticeboard, int parent_num, int &width_num)
{
	if (tree[parent_num].next1 != NULL)
	{
		inorder(tree, latticeboard, tree[parent_num].next1->number, width_num);
	}

	latticeboard[width_num].node_pointer = &tree[parent_num];
	width_num++;
	
	if (tree[parent_num].next2 != NULL)
	{
		inorder(tree, latticeboard, tree[parent_num].next2->number, width_num);
	}

}