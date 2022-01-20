#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 5e5 + 10;

int t;

char c[2] = {'L', 'R'}, ans[N * 2];

int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	
	scanf("%d", &t);
	while(t --)
	{		
		int n;
		scanf("%d", &n);
		
		LL a[n * 2], b[n * 2];
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		
		for(int j = 1; j <= 2*n; j ++)
			scanf("%d", &a[j]);
			
		bool m = true; 
		for(int i = 1; i <= n; i ++)
		{
			if(a[i] != a[2 * n + 1 - i])
			{
				m = false;
				break;
			}	
		}
		
		if(m)
		{
			for(int i = 1; i <= 2 * n; i ++)
				printf("L");
			puts("");
			continue;
		}
		
		else
		{
			bool k = true;
			if(a[1] == a[2 * n])
			{
				for(int i = 1; i <= 2 * n; i ++)
				{
					if(a[i] != a[2 * n + 1 - i])
					{
						//k = false;
						puts("-1");
						break;
					}	
				}
			}
			continue;
			
		}
		
		LL hh = 1, tt = 2 * n;
		bool k = true;
		int cnt = 0;
		
		for(int i = 1; i <= 2 * n; i ++)
		{
			for(int j = 0; j <= 1; j ++)
			{
				if(c[j] == 'L')
				{
					b[cnt ++] = a[hh ++];
				}
				else
				{
					b[cnt ++] = a[tt --];
				}
			}
		}
		
	}
	



	return 0;
}

