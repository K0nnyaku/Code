#include <cstdio>
#include <algorithm>
#define ll long long

using namespace std;

const ll N = 1e7 + 9;
ll n, m1, m2;
struct air
{
	ll atim;
	ll ltim;
	ll wtim;
	ll ki;  // 0为国内， 1为国际
}bf[N], a[N], b[N];
ll max(ll x, ll y)
{
	if(x == y)
		return x;
	return x > y ? x : y;
}
ll ans1, ans2, ans3, ans;
bool cmp(air x, air y)
{
	if(x.atim == y.atim)
		return x.ltim < y.ltim;
	return x.atim < y.atim;
}

void dfs1(ll num, ll lim, ll pos, ll endd, ll endnum)
{
	if(pos > m1)
	{
		ans1 = max(ans1, num);
		return ;
	}
	if(a[pos].atim > endd + a[endnum].wtim)
	{
		dfs1(num, lim, pos + 1, endd, endnum);
		dfs1(num + 1, lim, pos + 1, a[pos].ltim, pos);
	}
	else
	{
		if(lim == 0)
			dfs1(num, lim, pos + 1, endd, endnum);
		else
			dfs1(num + 1, lim - 1, pos + 1, a[pos].ltim, pos);
	}
}

void dfs2(ll num, ll lim, ll pos, ll endd, ll endnum)
{
	if(pos > m2)
	{
		ans2 = max(ans2, num);
		return ;
	}
	if(b[pos].atim > endd + b[endnum].wtim)
	{
		dfs2(num, lim, pos + 1, endd, endnum);
		dfs2(num + 1, lim, pos + 1, b[pos].ltim, pos);
	}
	else
	{
		if(lim == 0)
			dfs2(num, lim, pos + 1, endd, endnum);
		else
			dfs2(num + 1, lim - 1, pos + 1, b[pos].ltim, pos);
	}
}

//void dfs3(ll num, ll lim0, ll lim1, ll pos, ll endd0, ll endd1, ll endnum0, ll endnum1))
//{
//	if(pos > m1 + m2)
//	{
//		ans3 = max(ans3, num);
//		return ;
//	}
//}
int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m1, &m2);
	for(ll i = 1; i <= m1; i++)
	{
		scanf("%lld%lld", &a[i].atim, &a[i].ltim);
		bf[i].atim = a[i].atim;
		bf[i].ltim = a[i].ltim;
		bf[i].ki = 0;
		a[i].wtim = a[i].ltim - a[i].atim;
		bf[i].wtim = a[i].wtim;
	}
	sort(a + 1, a + m1 + 1, cmp);
	dfs1(0, n, 1, 0, 0);
//	printf(" ** \n");
	for(ll i = 1; i <= m2; i++)
	{
	//	printf(" ** \n");
		scanf("%lld%lld", &b[i].atim, &b[i].ltim);
		bf[i + m1].atim = b[i].atim;
		bf[i + m1].ltim = b[i].ltim;
		bf[i + m1].ki = 1;
		b[i].wtim = b[i].ltim - b[i].atim + 1;
		bf[i + m1].wtim = b[i].wtim;
	}
	sort(b + 1, b + m2 + 1, cmp);
	dfs2(0, n, 1, 0, 0);
	sort(bf + 1, bf + m1 + m2 + 1, cmp);
	ans = max(ans1, ans2);
//	printf(" ** \n");
//	dfs3();
	ans = max(ans, ans3);
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

