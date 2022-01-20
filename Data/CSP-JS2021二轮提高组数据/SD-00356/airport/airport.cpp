#include <bits/stdc++.h>
#include <cstdio>

const int maxn = 1e5 + 5;

#define DEBUG printf("YES")

struct edge
{
	int a, b;
} nain[maxn], naout[maxn];

int n, m1, m2, ans;

bool cmp(edge aa, edge bb)
{
	return aa.a < bb.a;
}

int find(int x)
{
	int y = n - x, num = n;
	std::priority_queue <int> hp;
	if(x)
	{
		for(int i = 1; i <= x; ++i)
		{
			hp.push(-nain[i].b);
		}
		int pt = x;
		int u = -hp.top();
		while(pt < m1)
		{
			pt++;
			if(nain[pt].a < u) continue;
			hp.pop();
			num++;
			hp.push(-nain[pt].b);
			u = -hp.top();
		}
	}
	while(!hp.empty()) hp.pop();
	if(y)
	{
		for(int i = 1; i <= y; ++i)
		{
			hp.push(-naout[i].b);
		}
		int pt = y;
		int u = -hp.top();
		while(pt < m2)
		{
			pt++;
			if(naout[pt].a < u) continue;
			hp.pop();
			num++;
			hp.push(-naout[pt].b);
			u = -hp.top();
		}
	}
	return num;
}

int main()
{
	freopen("airport.in", "r", stdin); 
	freopen("airport.out", "w", stdout); 
	scanf("%d%d%d", &n, &m1, &m2);
	for(int i = 1; i <= m1; ++i)
	{
		scanf("%d%d", &nain[i].a, &nain[i].b);
	}
	for(int i = 1; i <= m2; ++i)
	{
		scanf("%d%d", &naout[i].a, &naout[i].b);
	}
	std::sort(nain + 1, nain + m1 + 1, cmp);
	std::sort(naout + 1, naout + m2 + 1, cmp);
	ans = std::min(n, m);
	for(int i = 0; i <= std::min(n, m1); ++i)
	{
		if(n - i > m2) continue;
		ans = std::max(ans, find(i));
	}
	printf("%d", ans);
	return 0;
}
