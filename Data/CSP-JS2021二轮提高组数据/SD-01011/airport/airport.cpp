#include<bits/stdc++.h>
#define ll long long
#define fint int
const int maxn = 1e6 + 7;
using std::cin;
using std::cout;
using std::min;
using std::max;
using std::abs;
using std::sort;
using std::unique;
using std::set;
using std::map;
using std::vector;
int read(){
	int x = 0, fl = 1; char ch = getchar();
	while(ch > '9' || ch < '0'){if(ch == '-')fl = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0'){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
	return x * fl;
}
struct node{
	int l, r;
	bool operator<(const node&a)const{
		return a.l > l;
	}
}q[2][maxn];
set<node>s[3];
int n, md1, md2, ansmd1[maxn], ansmd2[maxn], sum;
signed main(){
	node a = (node){1, 3}, b = (node){2, 3};
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &md1, &md2);
	for(fint i = 1; i <= md1; i++){
		scanf("%d%d", &q[0][i].l, &q[0][i].r);
		s[0].insert(q[0][i]);
	}for(fint i = 1; i <= md2; i++){
		scanf("%d%d", &q[1][i].l, &q[1][i].r);
		s[1].insert(q[1][i]);
	}
	for(fint i = 1; i <= n; i++){
		ansmd1[i] = ansmd1[i - 1];
		if(!s[0].size()){continue;}
		node c = (*s[0].begin()), d; ++ansmd1[i];
		s[0].erase(c);
		while(s[0].size() > 0 && (*(--s[0].end())).l > c.r){
			d.l = c.r, d.r = c.l;
			c = *s[0].upper_bound(d);
			s[0].erase(c); ++ansmd1[i];
		}
	}
	for(fint i = 1; i <= n; i++){
		ansmd2[i] = ansmd2[i - 1];
		if(!s[1].size()){continue;}
		node c = (*s[1].begin()), d; ++ansmd2[i];
		s[1].erase(c);
		while(s[1].size() > 0 && (*(--s[1].end())).l > c.r){
			d.l = c.r, d.r = c.l;
			c = *s[1].upper_bound(d);
			s[1].erase(c); ++ansmd2[i];
		}
	}
	for(fint i = 0; i <= n; i++){
		sum = max(sum, ansmd1[i] + ansmd2[n - i]);
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
