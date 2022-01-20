#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
//typedef pair<int, int> pii;
const int maxn = 200010, inf = 1e9;
struct node
{
	node() {}
	node(int _x, int _id, int _tim)
	{
		x = _x;
		id = _id;
		tim = _tim;
	}
	int x, id, tim;
} ques1[maxn], ques2[maxn];
bool cmp(node a, node b)
{
	return a.tim < b.tim;
}
int n, nei, wai, a1[maxn], b1[maxn], a2[maxn], b2[maxn];
int cnt1, cnt2, lft1, lft2;
bool in_sta1[maxn], in_sta2[maxn];
int get_ans(int k)
{
	int ans = 0;
	lft1 = k, lft2 = n - k;
	for (int i = 1; i <= cnt1; ++i)
	{
		if (ques1[i].x == 1)
		{
			if (lft1 > 0)
			{
				lft1--;
				ans++;
				in_sta1[ques1[i].id] = true;
			}
		}
		else
		{
			if (in_sta1[ques1[i].id])
				in_sta1[ques1[i].id] = false, lft1++;
		}
	}
	for (int i = 1; i <= cnt2; ++i)
	{
		if (ques2[i].x == 1)
		{
			if (lft2 > 0)
			{
				lft2--;
				ans++;
				in_sta2[ques2[i].id] = true;
			}
		}
		else
		{
			if (in_sta2[ques2[i].id])
				in_sta2[ques2[i].id] = false, lft2++;
		}
	}
	return ans;
}
int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &nei, &wai);
	for (int i = 1; i <= nei; ++i)
	{
		scanf("%d%d", &a1[i], &b1[i]);
		ques1[++cnt1] = node(1, i, a1[i]);
		ques1[++cnt1] = node(-1, i, b1[i]);
	}
	for (int i = 1; i <= wai; ++i)
	{
		scanf("%d%d", &a2[i], &b2[i]);
		ques2[++cnt2] = node(1, i, a2[i]);
		ques2[++cnt2] = node(-1, i, b2[i]);
	}
	sort(ques1 + 1, ques1 + cnt1 + 1, cmp);
	sort(ques2 + 1, ques2 + cnt2 + 1, cmp);
	int l = 0, r = n, ans = -inf;
	while (l <= r)
	{
		for (int i = 1; i <= n; ++i)
			in_sta1[i] = in_sta2[i] = false;
		int mid = (l + r ) / 2;
		int ml = (l + mid) / 2, mr = (mid + r) / 2;
		int ans1 = get_ans(ml), ans2 = get_ans(mr);
		if (ans1 > ans2)
			ans = max(ans, ans1), r = mid - 1;
		else
			ans = max(ans, ans2), l = mid + 1;
	}
	printf("%d", ans);
	return 0;
}
