#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 

using namespace std;
const int N = 1e5 + 9 ;
int n, m1, m2;
struct air
{
	int a, b;
}g[N], g2[N], last[N];


inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;        
} 

bool cmp(air x, air y)
{
	return x.a < y.a ;
}

int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = read(), m1 = read(), m2 = read();
	for(int i = 1; i <= m1; i ++)
	{
		g[i].a = read();
		g[i].b = read();	
	} 
	for(int i = 1; i <= m2; i ++)
	{
		g2[i].a = read();
		g2[i].b = read();
	}
	if(n >= m1 + m2)
	{
		cout << m1 + m2 ;
		return 0;
	}
	int ANS = 0;
	sort(g + 1, g + m1 + 1, cmp);
	
	sort(g2 + 1, g2 + m2 + 1, cmp);
	
	int num = min(min(m1, m2), n);
	for(int k = 0; k <= num; k ++)
	{
		int ans = k;
		if(k != 0)
		{
			for(int z = 1; z <= k; z ++)
			{
				last[z].b = g[z].b;
				last[z].a = g[z].a ;
			}
			for(int i = k + 1 ; i <= m1; i ++)
			{
				for(int j = 1; j <= k; j ++)
				{
					if(g[i].a > last[j].b )
					{
						ans ++;
						last[j].a = g[i].a ;
						last[j].b = g[i].b ;
						break;
					}
				}
			}
		}
		if(k != num)
		{
			ans += n - k;
			for(int i = 1; i <= n - k; i ++)
			{
				last[i].b = g2[i].b;
				last[i].a = g2[i].a ;
			}
			for(int i = num - k + 1; i <= m2; i ++)
			{
				for(int j = 1; j <= (n - k); j ++)
				{
					if(g2[i].a > last[j].b )
					{
						ans ++;
						last[j].a = g2[i].a ;
						last[j].b = g2[i].b ;
						break;
					}
				}
			}		
		}
		ANS = max(ANS, ans);
	}
	cout << ANS ;
	
	fclose(stdin);
	fclose (stdout);

	return 0 ;	
} 
