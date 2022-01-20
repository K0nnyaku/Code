#include<bits/stdc++.h>
using namespace std;
struct FastIN
{
	template <typename T>
	FastIN& operator >> (T &x)
	{
		x = 0;
		int f = 1, CH = getchar();
		while (CH < '0' or CH > '9')
		{
			if (CH == '-') f = -1;
			CH = getchar();
		}
		while (CH >= '0' and CH <='9')
		{
			x = x * 10 +(CH - '0');
			CH = getchar();
		}
		if (f == -1) x = -x;
		return *this;
	}
} IN;
const int N = 2e6 + 26;
int T, n, A[N], Flag, S[N];
char Cao[N];
unordered_map <int, int> Mp;
bool Check()
{
	for (int i = 1; i <= n; i++)
		if (S[i] != S[2 * n - i + 1])
			return 0;
	return 1;
}
void DFS(int x, int L, int R)
{
	if (Flag) return ;
	else if (x == n * 2 + 1)
	{
		if (Check()) Flag = 1;
		return ;
	}
	if (!Mp[A[L]])
	{
		Mp[A[L]] = x;
		Cao[x] = 'L', S[x] = A[L];
		DFS(x + 1, L + 1, R);
		Mp[A[L]] = 0;
	}
	else if (Mp[A[L]] + x == 2 * n + 1)
	{
		Cao[x] = 'L', S[x] = A[L];
		DFS(x + 1, L + 1, R);
	}
	if (Flag) return ;
	if (!Mp[A[R]])
	{
		Mp[A[R]] = x;
		Cao[x] = 'R', S[x] = A[R];
		DFS(x + 1, L, R - 1);
		Mp[A[R]] = 0;
	}
	else if (Mp[A[R]] + x == 2 * n + 1)
	{
		Cao[x] = 'R', S[x] = A[R];
		DFS(x + 1, L, R - 1);
	}
}
int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		Flag = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n * 2; i++) scanf("%d", &A[i]);
		DFS(1, 1, n * 2);
		if (Flag)
		{
			for (int i = 1; i <= n * 2; i++) printf("%c", Cao[i]);
			printf("\n");
		}
		else printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}



