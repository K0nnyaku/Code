#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

void get_res(int a[],int b[],int n,int m,int res[])
{
	set<pii> ta;
	for(int i=1; i<=m; ++i) ta.insert(make_pair(a[i], i));
	res[0] = 0;
	for(int i=1; i<=n; ++i)
	{
		res[i] = res[i-1];
		if(!ta.size()) continue;
		auto it = ta.begin();
		while(it != ta.end())
		{
			int id = it -> second;
			ta.erase(it);
			++res[i];
			it = ta.upper_bound(make_pair(b[id], 0));
		}
	}
}

int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

int main(void)
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1; i<=m1; ++i) scanf("%d%d",&a[i],&b[i]);
	for(int i=1; i<=m2; ++i) scanf("%d%d",&c[i],&d[i]);
	
	static int f[MAXN], g[MAXN];
	get_res(a, b, n, m1, f);
	get_res(c, d, n, m2, g);
	
	int ans = 0;
	for(int i=0; i<=n; ++i)
		ans = max(ans, f[i] + g[n-i]);
	printf("%d",ans);
	return 0;
}
