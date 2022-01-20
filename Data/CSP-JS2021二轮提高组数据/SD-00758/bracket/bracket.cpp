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
int n, k, cnt;
char Ch;
int Q_Pow(int a, int b, int p)
{
	int Ans = 1;
	while (b)
	{
		if (b & 1) Ans = 1ll * Ans * a % p;
		a = 1ll * a * a % p;
		b >>= 1;
	}
	return Ans;
}
int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	IN >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		Ch = getchar();
		if (Ch == '?') cnt++;
	}
	printf("%d", Q_Pow(2, cnt, 1e9 + 7));
	fclose(stdin);
	fclose(stdout);
	return 0;
}



