//�ϳ���ž ������ ����Լ��� �̿�
#include <iostream>
using namespace std;

void HanoiTowerMove(int num, char from, char by, char to) {
	if (num == 1) {
		cout << "1 : "<<from <<"->"<< to << endl;
	}
	else {
		HanoiTowerMove(num - 1, from, to, by);
		//������ ������ to�� move
		cout << num <<" : "<< from << "->" << to << endl;
		HanoiTowerMove(num - 1, by, from, to);
	}
}

int main()
{
	int n;
	char from = '1', by = '2', to = '3';
	cin >> n;
	HanoiTowerMove(n, from, by, to);
}