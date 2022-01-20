#include <cstdio>

FILE *fpi = fopen("palin.in" , "rb");
FILE *fpo = fopen("palin.out", "wb");

int n, pos[500001][2], n_num[500001];
int arr1[250000], arr2[250000], arr[500000];

int main()
{
	int T; fscanf(fpi, "%d", &T);

	while (T-- > 0)
	{
		scanf("%d", &n);

		for (int i = 0; i < n; ++i)
		{
			int a; scanf("%d", &a); arr[i] = a;
			pos[a][0]? pos[a][1] : pos[a][0] = i + 1;
		}

		n <<= 1;

		for (int i = 1; i <= n; ++i)
		{
			n_num = 0;

			for (int a = 1; a <= n; ++a)
			{
				bool x = pos[i][0] < pos[a][0] && pos[a][0] < pos[i][1];
				bool y = pos[i][0] < pos[a][1] && pos[a][1] < pos[i][1];
				n_num[i] += (x xor y);
			}

			if (n_num == (n >> 1) - 1)
			{
				int k;

				for (k = 0; k < pos[i][0] - 1; ++k)
				{
					arr1[k] = arr[k];
				}

				for ( ; k < pos[i][1] - 1; ++i)
				{
					arr2[k] = arr[k];
				}

				for ( ; k < n; ++i)
				{
					arr1[k - pos[i][1] + pos[i][0]] = arr[k];
				}
			}
		}
	}

	return (fclose(fpi), fclose(fpo), 0);
}

