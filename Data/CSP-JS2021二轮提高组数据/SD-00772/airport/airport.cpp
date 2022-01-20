#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
struct node
{
	int l, r;
} a[N], b[N];
int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	int n, m1, m2;
	scanf("%d%d%d", &n, &m1, &m2);
	if (n >= m1+m2)
	{
		printf("%d", m1+m2);
		return 0;
	}
	map <int, int> mp1, mp2;
	for (int i = 1; i <= m1; i++)
	{
		scanf("%d%d", &a[i].l, &a[i].r);
		mp1[a[i].l]++, mp1[a[i].r]--;
	}
	for (int i = 1; i <= m2; i++)
	{
		scanf("%d%d", &b[i].l, &b[i].r);
		mp2[b[i].l]++, mp2[b[i].r]--; 
	}
	map <int, int> :: iterator it = mp1.begin();
	it++;
	for ( ; it != mp1.end(); it++)
	{
		map <int, int> :: iterator is = it;
		--is;
		it->second += is->second;
	}
	it = mp2.begin();
	it++;
	for ( ; it != mp2.end(); it++)
	{
		map <int, int> :: iterator is = it;
		--is;
		it->second += is->second;
	}
	int x = 0, y = 0;
	for (map <int, int> :: iterator it = mp1.begin(); it != mp1.end(); it++)
	{
		x = max(x, it->second);
	}
	for (map <int, int> :: iterator it = mp2.begin(); it != mp2.end(); it++)
	{
		y = max(y, it->second);
	}
	int ret = 0;
	for (int num = 0; num <= n; num++)
	{
		int o1 = num, o2 = n-num;
		ret = max(ret, min(o1, x)+min(o2, y));
	}
	printf("%d", ret);
	return 0;
}
