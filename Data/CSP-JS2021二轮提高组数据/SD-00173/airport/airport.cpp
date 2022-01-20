#include <bits/stdc++.h>
#define ll long long
#define re register
#define maxn 100005
using namespace std;
inline ll read(){
	ll s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')w = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){s = (s << 1) + (s << 3) + (ch ^ 48); ch = getchar();}
	return s * w;
}
ll n, m1, m2, res, ans1[maxn], ans2[maxn];
bool vis[maxn];
struct node{
	ll l, r;
}a1[maxn], a2[maxn];
bool cmp(node a, node b){
	return a.l < b.l;
}
int main(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);

	n = read(), m1 = read(), m2 = read();
	for(re ll i = 1; i <= m1; i++) a1[i].l = read(), a1[i].r = read();	
	for(re ll i = 1; i <= m2; i++) a2[i].l = read(), a2[i].r = read();	
	sort(a1 + 1, a1 + m1 + 1, cmp);
	sort(a2 + 1, a2 + m2 + 1, cmp);
	ll ans = 0, cnt = 0, maxx;
	while(ans < m1){
		cnt++;
		maxx = 0;
		for(re ll i = 1; i <= m1 && ans <= m1; i++)
				if(!vis[i] && a1[i].l > maxx){
					vis[i] = 1;
					maxx = a1[i].r;
					ans1[cnt]++;
					ans++;
				}
		ans1[cnt] += ans1[cnt - 1];
	}
	ans = 0, cnt = 0;
	memset(vis, 0, sizeof(vis));
	while(ans < m2){
		cnt++;
		maxx = 0;
		for(re ll i = 1; i <= m2 && ans <= m2; i++)
				if(!vis[i] && a2[i].l > maxx){
					vis[i] = 1;
					maxx = a2[i].r;
					ans2[cnt]++; 
					ans++;
				}
		ans2[cnt] += ans2[cnt - 1];
	}
	for(re ll i = 0; i <= n; i++)	res = max(res, ans1[i] + ans2[n - i]);
	printf("%lld", res);
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

