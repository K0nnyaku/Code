#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <ctime>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)

template <typename T>
T read(T &a)
{
	T res = 0, sign = 1;
	char c;
	while((c = getchar()) < '0' || c > '9') if(c == '-') sign = -1;
	while(c <= '9' && c >= '0') res = res * 10 + c - '0', c = getchar();
	a = res * sign;
	return a;
}

const int N = 100010;

int n, m1, m2, l, r, b[N << 2], f1[N << 2], f2[N << 2], tot = 0;
pair<int, int> gn[N], gw[N];
int ans = 0;

int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	read(n), read(m1), read(m2);
	rep(i,1,m1) read(l), read(r), gn[i] = make_pair(l, r), b[++tot] = l, b[++tot] = r;
	rep(i,1,m2) read(l), read(r), gw[i] = make_pair(l, r), b[++tot] = l, b[++tot] = r;
	sort(b+1, b+1+tot);
	rep(i,1,m1) gn[i].first = lower_bound(b+1, b+1+tot, gn[i].first) - b;
	rep(i,1,m1) gn[i].second = lower_bound(b+1, b+1+tot, gn[i].second) - b;
	rep(i,1,m2) gw[i].first = lower_bound(b+1, b+1+tot, gw[i].first) - b;
	rep(i,1,m2) gw[i].second = lower_bound(b+1, b+1+tot, gw[i].second) - b;
	sort(gn+1, gn+1+m1);
	sort(gw+1, gw+1+m2);
	rep(hi,0,n)
	{
		int nb = hi, wb = n - hi;
		int sum1 = 0, sum2 = 0;
		int jz = 0;
		int now1 = 1, now2 = 1;
		rep(i,1,tot)
		{
			if(f1[i]) sum1--, f1[i] = 0;
			if(f2[i]) sum2--, f2[i] = 0;
			while(gn[now1].first < i && now1 < m1) now1++;
			if(gn[now1].first == i && sum1 < nb) jz++, sum1++, f1[gn[now1].second] = 1;
			while(gw[now2].first < i && now2 < m2) now2++;
			if(gw[now2].first == i && sum2 < wb) jz++, sum2++, f2[gw[now2].second] = 1;
		}
		ans = max(ans, jz);
	}
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

