#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define N 5
#define M 5
int t[N][M];

void zak(int q, int w, int ch)
{
	if (t[q][w] == 1) return;
	else
	{
		kra(q, w, ch);
		t[q][w] = ch;
	}
}

int kra(int q, int w, int ch)
{
	if (q > 0 && w > 0 && q < N && w < N)
	{
		if (t[q - 1][w] == 0)
		{
			t[q - 1][w] = ch;
			kra(q - 1, w, ch);
		}
		if (t[q][w - 1] == 0)
		{
			t[q][w - 1] = ch;
			kra(q, w - 1, ch);
		}
		if (t[q + 1][w] == 0)
		{
			t[q + 1][w] = ch;
			kra(q + 1, w, ch);
		}
		if (t[q][w + 1] == 0)
		{
			t[q][w + 1] = ch;
			kra(q, w + 1, ch);
		}
		return 0;
	}
}

void print()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", t[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	srand(1);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			t[i][j] = 1;
		}
	}

	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			//t[i][j] = rand() % 2 ? 0 : rand() % 2;
			t[i][j] = rand() % 2;
		}
	}
	print();
	int c = 0;
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			if (t[i][j] == 1)
			{
				c++;
			}
		}
	}
	printf("1 = %d\n", c);
	printf("0 = %d\n", ((N - 2)*(M - 2)) - c);
	t[3][3] = 1;
	zak(3, 1, 5);
	print();
	getchar();
	return 0;
}
