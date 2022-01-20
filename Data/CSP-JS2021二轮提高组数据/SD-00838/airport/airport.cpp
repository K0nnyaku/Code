#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
	char c = getchar(), last = ' ';
	ll ans = 0;
	while(c < '0' || c > '9') last = c, c = getchar();
	while(c >= '0' && c <= '9') ans = ans * 10 + c - '0', c = getchar();
	while(last == '-') ans = -ans;
	return ans;
}
const int N = 100005;
int n, m1, m2;
struct node
{
	int l, r;
}a[N], b[N];
bool cmp(node x, node y)
{
	return x.l < y.l;
}
priority_queue<int> q1, q2;
int cnt1, cnt2, ans1, ans2, ans;
int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = read(), m1 = read(), m2 = read();
	for(int i = 1; i <= m1; i ++)
		a[i].l = read(), a[i].r = read();
	for(int i = 1; i <= m2; i ++)
		b[i].l = read(), b[i].r = read();
	if(n <= 5000 && m1 + m2 <= 5000)
	{
		sort(a + 1, a + 1 + m1, cmp);
		sort(b + 1, b + 1 + m2, cmp);
		for(int i = 1; i <= n; i ++)
		{
			while(!q1.empty()) q1.pop();
			while(!q2.empty()) q2.pop();
			ans1 = 0, ans2 = 0, cnt1 = 0, cnt2 = 0;
			int n1 = i, n2 = n - i;
			for(int j = 1; j <= m1; j ++)
			{
				if(cnt1 < n1) q1.push(-a[j].r), cnt1 ++, ans1 ++;
				else if(a[j].l >= -q1.top())
				{
					q1.pop();
					q1.push(-a[j].r);
					ans1 ++;
				}
			}
			for(int j = 1; j <= m2; j ++)
			{
				if(cnt2 < n2) q2.push(-b[j].r), cnt2 ++, ans2 ++;
				else if(b[j].l >= -q2.top())
				{
					q2.pop();
					q2.push(-b[j].r);
					ans2 ++;
				}
			}
			ans = max(ans1 + ans2, ans);
		}
		printf("%d", ans);
	}
	return 0;
}
//return 0;
