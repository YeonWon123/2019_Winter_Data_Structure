
#include <iostream>
#include <string>

using namespace std;

typedef int Matrix[100][100] ;

int N;
Matrix m;
Matrix m_prev;
Matrix m_now;

void MatMul(const Matrix& m1, const Matrix& m2, Matrix& m_result)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a = 0;
			for (int k = 0; k < N; k++)
			{
				a += m1[i][k] * m2[k][j];
				if (a > 0)
					break;
			}
			if (a > 0)
				m_result[i][j] = 1;
			else
				m_result[i][j] = 0;
		}
	}
}

void MatSum(const Matrix& m1, const Matrix& m2, Matrix& m_result)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			m_result[i][j] = (m1[i][j] + m2[i][j] > 0 ? 1 : 0 );
		}
	}
}

void MatSumIden(Matrix& m_result)
{
	for (int i = 0; i < N; i++)
	{
		m_result[i][i] = 1;
	}
}

void PrintMat(const Matrix& m)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
          	cout << m[i][j];	
          	if (j != N-1)
				cout << ' ';
		}
		cout << '\n';
	}
}

void SetMat(Matrix& m)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> m[i][j];
		}
	}
}

void CopyMat(Matrix& from, Matrix& to)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			to[i][j] = from[i][j];
		}
	}
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	SetMat(m); // 계수

	for (int i = 0; i < N; i++)
	{
		MatSumIden(m_prev);
		MatMul(m, m_prev, m_now);
		CopyMat(m_now, m_prev);
	}

	PrintMat(m_now);
	return 0;
}