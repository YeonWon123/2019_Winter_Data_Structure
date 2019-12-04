// 프린터 큐
// 백준 1966
// 우선순위 큐를 구현하는 문제
// 원래의 큐는 선입선출이지만, 우선순위 큐는 먼저 들어온 순서가 아니라 특정한 우선순위에 의해 결정된다.
// ACM-ICPC : NWERC 2006 F번

#include <stdio.h>
#include <string.h>
typedef struct
{
	int First_location;
	int Importance;
}Data;
Data Queue[111 * 111];
Data Print;
int Importance_Num[11];
int Front = -1, Back = -1, Importance_Index = 9;
int main()
{
	int Test, N, Res;
	scanf("%d", &Test);
	while (Test--)
	{
		memset(Importance_Num, 0, sizeof(Importance_Num));
		scanf("%d %d", &N, &Print.First_location);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &Queue[i].Importance);
			Importance_Num[Queue[i].Importance]++;
			Queue[i].First_location = i;
			if (Print.First_location == i)
				Print.Importance = Queue[i].Importance;
		}
		Back = N - 1;
		Front = -1;
		Importance_Index = 9;
		Res = 0;
		while (1)
		{
			int a, b, c, d, e;
			a = Importance_Num[Importance_Index];
			if (a == 0)
			{
				Importance_Index--;
			}
			else if (a > 0)
			{
				Front++;

				if (Front >= 110 * 110)
					Front %= 110 * 110;
				if (Importance_Index == Queue[Front].Importance)
				{
					Res++;
					Importance_Num[Importance_Index]--;
					//printf("%d =======  \n", Queue[Front].Importance);

					d = Print.First_location;
					e = Queue[Front].First_location;
					if (d == e)
					{
						printf("%d\n", Res);
						break;
					}
				}
				else
				{
					++Back;
					if (Back >= 110 * 110)
						Back %= 110 * 110;
					Queue[Back] = Queue[Front];
				}
			}
		}
	}
	return 0;
}