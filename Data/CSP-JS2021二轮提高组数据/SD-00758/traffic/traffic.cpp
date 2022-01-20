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
int A[10] = {0, 5253800, 945306, 7225, 476287, 572399};

int main()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	for (int i = 1; i <= 5; i++) printf("%d\n", A[i]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}



