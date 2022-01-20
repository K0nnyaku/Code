#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1000010;
int n, now, m1, m2, ans;
struct ap{
	int a, b;
};
ap hm[N], ad[N];
bool vis[N];

int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
	return x * f;
}

bool cmp(ap x, ap y){
	return x.a < x.a;
}

int find(ap pl[], int m, int maxn){
	int now[maxn + 5];
	memset(now, 0, sizeof(now));
	memset(vis, false, sizeof(vis));
	int cnt = 0, num = 0;
	if(maxn == 0) return cnt;
	
	now[++num] = pl[1].b;
	vis[1] = true;
	cnt = 1;
	
	for(int i = 2; i <= m; i++){
		for(int j = 1; j <= maxn; j++){
			if(pl[i].a > now[j] && !vis[i]){
				now[j] = pl[i].b;
				vis[i] = true;
				cnt++; 
				break;
			}
		}	
	}
	return cnt;
} 

int main(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);

	n = read(); m1 = read(); m2 = read();
	for(int i = 1; i <= m1; i++) hm[i].a = read(), hm[i].b = read();
	for(int i = 1; i <= m2; i++) ad[i].a = read(), ad[i].b = read();
	
	sort(hm + 1, hm + 1 + m1, cmp);
	sort(ad + 1, ad + 1 + m2, cmp);
	
	for(int i = 0; i <= n; i++)
		ans = max(ans, find(hm, m1, i) + find(ad, m2, n - i));
	
	printf("%d", ans);
	return 0;
}
