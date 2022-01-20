#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 4e3 + 10;

int Kind[MAXN];
int n, m, x;

bool Check();

int main() 
{
	freopen("In.in", "r", stdin);

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= 3 * m + 1; i++) scanf("%d", &x), Kind[x]++;

	for(int i = 1; i <= n; i++) 
	{
		Kind[i]++;
		if(Check()) printf("%d ", i);
		Kind[i]--;
	}

	return 0;
}

bool Check() 
{
	int T[MAXN];
	for(int i = 1; i <= n; i++) T[i] = Kind[i];

	for(int i = 1; i <= n; i++) 
	{
		if(T[i] >= 2) 
		{
			int k = 0;
			T[i] -= 2;
			for(int j = 1; j <= n; j++)
			{
				k += T[j] / 3;
				T[j] %= 3;
				int mn = min(T[j], min(T[j+1], T[j+2]));
				k += mn; T[j] -= mn; T[j+1] -= mn; T[j+2] -= mn;
				if(k >= m) return true;
			}
			printf("%d\n", k);
			T[i] += 2;
		}
	}

	return false;
}


















