#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int re() {
	int p = 0, f = 1; char i = getchar();
	while(i < '0' || i > '9') {if(i == '-') f = -1;i = getchar();}
	while(i >= '0' && i <= '9') p = p * 10 + i - '0', i = getchar();
	return f * p;
}

const int N = 1e5 + 10;

int n, m1, m2, ans, mt1, mt2;
int a[N], b[N];
struct zy {
	int l, r;
};
zy e1[N], e2[N];

int v[N];

bool cmp(zy x, zy y) {
	return x.l < y.l;
}

int Judge(int x, int y)
{
	int tot = 0;
	for(int t = 1; t <= mt1; t++)
	{
		for(int i = 1; i <= m1; i++)
		{
			for(int j = 1; j <= x; j++)
				if(t == e1[v[j]].r) v[j] = 0;
			if(t == e1[i].l)
			{
				for(int j = 1; j <= x; j++)
				{
					if(v[j]) continue;
					v[j] = i;
					tot++;
					break;
				}
			}
		}
	}
	memset(v, 0, sizeof(v));
	for(int t = 1; t <= mt2; t++)
	{
		for(int i = 1; i <= m2; i++)
		{
			for(int j = 1; j <= y; j++) 
			if(t == e2[v[j]].r)	v[j] = 0;
			if(t == e2[i].l)
			{
				for(int j = 1; j <= y; j++)
				{
					if(v[j]) continue;
					v[j] = i;
					tot++;
					break;
				}
			}
		}
	}
	return tot;
}

int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = re(); m1 = re(); m2 = re();
	for(int i = 1; i <= m1; ++i)  {
		e1[i].l = re(), e1[i].r = re();
		mt1 = max(e1[i].r, mt1);
	}
	for(int i = 1; i <= m2; ++i)
	{
		e2[i].l = re(), e2[i].r = re();
		mt2 = max(e2[i].r, mt2);
	}
	sort(e1 + 1, e1 + m1 + 1, cmp);
	sort(e2 + 1, e2 + m2 + 1, cmp);
	for(int i = 0; i <= n; ++i)
	{
		int a = n - i, b = i;
		ans = max(ans, Judge(a, b));
		if(b > 10000) break;
	}
	cout << ans << endl;
		
}
/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10

*/

/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
  
