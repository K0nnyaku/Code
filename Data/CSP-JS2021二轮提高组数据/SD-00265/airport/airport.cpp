#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;
int res = -0x3f3f3f3f;
struct plane
{
	int st, ed;
}a[N], b[N];

bool vis1[N], vis2[N];

int n, m1, m2;

bool cmp(plane a, plane b)
{
	return a.st < b.st;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	scanf("%d%d%d", &n, &m1, &m2);
	
	for (int i = 1; i <= m1; i ++ ) scanf("%d%d", &a[i].st, &a[i].ed);
	for (int i = 1; i <= m2; i ++ ) scanf("%d%d", &b[i].st, &b[i].ed);
	
	sort(a + 1, a + m1 + 1, cmp);
	sort(b + 1, b + m2 + 1, cmp);
	
	for (int i = 0; i <= n; i ++ )
	{
		int x = i, y = n - i, cnt = 0;
		memset(vis1, false, sizeof vis1);
		memset(vis2, false, sizeof vis2);
		
		if (x == 0 && y != 0)
		{
			for (int j = 1; j <= m2; j ++ )
			{
				if (j == 1)
				{
					cnt ++ , y -- ;
					continue;
				}
				else
				{
					for (int k = 1; k < j; k ++ )
						if (!vis2[k] && b[k].ed < b[j].st && y < n - i) y ++ , vis2[k] = true;
					if (y) cnt ++ , y -- ; 
				}
			}
		}
		else if (y == 0 && x != 0)
		{
			for (int j = 1; j <= m1; j ++ )
			{
				if (j == 1)
				{
					cnt ++ , x -- ;
					continue;
				}
				else
				{
					for (int k = 1; k < j; k ++ )
						if (!vis1[k] && a[k].ed < a[j].st && x < i) x ++ , vis1[k] = true;
					if (x) cnt ++ , x -- ; 
				}
			}
		}
		else
		{
			for (int j = 1; j <= m1; j ++ )
			{
				if (j == 1)
				{
					cnt ++ , x -- ;
					continue;
				}
				else
				{
					for (int k = 1; k < j; k ++ )
						if (!vis1[k] && a[k].ed < a[j].st && x < i) x ++ , vis1[k] = true;
					if (x) cnt ++ , x -- ;
				}
			}
			for (int j = 1; j <= m2; j ++ )
			{
				if (j == 1)
				{
					cnt ++ , y -- ;
					continue;
				}
				else
				{
					for (int k = 1; k < j; k ++ )
						if (!vis2[k] && b[k].ed < b[j].st && y < n - i) y ++ , vis2[k] = true;
					if (y) cnt ++ , y -- ; 
				}
			}
		}

		res = max(res, cnt);
	}
	
	cout << res << endl;
	
	return 0;
}


