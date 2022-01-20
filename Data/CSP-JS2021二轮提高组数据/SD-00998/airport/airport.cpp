#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define Maxn 100010

int n, m1, m2, cnt1, cnt2, ans = -1;
priority_queue <int> q_1, q_2;

struct node
{
	int l, r;
}Air1[Maxn], Air2[Maxn];

bool cmp(node a, node b)
{
	return a.l < b.l;
}

int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &m1, &m2);
	for (int i = 1; i <= m1; i ++)
		scanf("%d%d", &Air1[i].l, &Air1[i].r);
	for (int i = 1; i <= m2; i ++)
		scanf("%d%d", &Air2[i].l, &Air2[i].r);
	sort(Air1 + 1, Air1 + m1 + 1, cmp);
	sort(Air2 + 1, Air2 + m2 + 1, cmp);
	for (int i = 0; i <= n; i ++)
	{
		int j = n - i, d_1 = 0, d_2 = 0;
		int p_1 = 1, p_2 = 1;
		q_1.push(-Air1[1].r);
		q_2.push(-Air2[1].r);
		if (i == 0)	p_1 = 0;
		else
		{
			d_1 = 1;
			for (int k = 2; k <= m1; k ++)
			{
				int x = -1 * q_1.top();
				if (x < Air1[k].l)
				{//用已经有的廊桥 
					q_1.push(-Air1[k].r);
					q_1.pop();
					p_1++;
				}
				else if (x > Air1[k].l && d_1 + 1 <= i) 
				{//新开一个廊桥的情况 
					d_1++; p_1++;
					q_1.push(-Air1[k].r);
				}
			}
		}
			
		if (j == 0) p_2 = 0;
		else
		{
			d_2 = 1;
			for (int k = 2; k <= m2; k ++)
			{
				int y = -1 * q_2.top();
				if (y < Air2[k].l)
				{
					q_2.push(-Air2[k].r);
					q_2.pop();
					p_2++;
				}
				else if (y > Air2[k].l && d_2 + 1 <= j)
				{
					d_2++; p_2++;
					q_2.push(-Air2[k].r);
				} 
			}
		}	
		ans = max(ans, p_1 + p_2);
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
