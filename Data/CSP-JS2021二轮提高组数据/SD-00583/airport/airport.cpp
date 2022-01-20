#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map> 

#define N 100010
using namespace std;


struct bala {
	int ls, rs, minn, maxx;
	int zdd, ydd;
}tree[N *4];

int a[N], lazy[N];

int ans1[N], ans2[N], ans;
int ly, ll[N], rr[N], l, r;

map<int, int> p;
int n, m, mm;
int lsh[N * 2], tot;
int bs[N * 2];

void init() {
	for(int i = 1;i <= n; i++) {
		a[i] = i;
	}
	sort(lsh + 1, lsh + tot + 1);
	for(int i = 1;i <= tot; i++)
		p[lsh[i]] = i;
}
void build(int u, int zs, int ys)
{
	tree[u].ls = zs; tree[u].rs = ys;
	if(zs == ys){
		tree[u].minn = a[zs];
		tree[u].maxx = a[zs];
		tree[u].zdd = zs;
		tree[u].ydd = ys;
		return;
	} 
	int mid = (zs + ys) / 2;
	build(u * 2, zs, mid);
	build(u * 2 + 1, mid + 1, ys);
	tree[u].minn = tree[u * 2].minn;
	tree[u].maxx = tree[u * 2 + 1].maxx;
	tree[u].zdd = zs;
	tree[u].ydd = ys;
}

void push_down(int u)
{
	lazy[u * 2] += lazy[u];
	lazy[u * 2 + 1] += lazy[u];
	lazy[u] = 0;
}
 
void Update(int u)
{
	if(tree[u].maxx + lazy[u] <= 0) return;
	if(tree[u].minn + lazy[u] > 0) {
		lazy[u]--; 
		ly = min(ly, tree[u].zdd); 
		return;
	}
	if(tree[u].ls == tree[u].rs) return;
	push_down(u);
	if(tree[u * 2].maxx + lazy[u * 2] > 0) Update(u * 2);
	if(tree[u * 2 + 1].maxx + lazy[u * 2 + 1] > 0) Update(u * 2 + 1);
	tree[u].minn = min(tree[u * 2].minn + lazy[u * 2], tree[u * 2 + 1].minn + lazy[u * 2 + 1]);
	tree[u].maxx = max(tree[u * 2].maxx + lazy[u * 2], tree[u * 2 + 1].maxx + lazy[u * 2 + 1]);
}

void Update_2(int u)
{
	if(tree[u].ls >= l && tree[u].rs <= r) {
		lazy[u]++; 
		tree[u].minn;
		tree[u].maxx;
		return;
	}
	push_down(u);
	int mid = (tree[u].ls + tree[u].rs) / 2;
	if(mid >= l) Update_2(u * 2);
	if(mid < r) Update_2(u * 2 + 1);
	tree[u].minn = min(tree[u * 2].minn + lazy[u * 2], tree[u * 2 + 1].minn + lazy[u * 2 + 1]);
	tree[u].maxx = max(tree[u * 2].maxx + lazy[u * 2], tree[u * 2 + 1].maxx + lazy[u * 2 + 1]);
}

int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &mm);

	for(int i = 1;i <= m; i++) {
		scanf("%d%d", &ll[i], &rr[i]);
		lsh[++tot] = ll[i]; lsh[++tot] = rr[i];
	}
	init();
	for(int i = 1;i <= m; i++) {
		bs[ p[ll[i]] ] = i; 
		bs[ p[rr[i]] ] = 0 - i;
	}
	build(1, 1, n);
	for(int i = 1;i <= tot; i++) {
		if(bs[i] > 0) {
			ly = 2147483;
			Update(1);
			ll[bs[i]] = ly; 
			if(ly != 2147483 )ans1[ly]++;
		}
		if(bs[i] < 0) {
			l = ll[0 - bs[i]]; r = n;
			Update_2(1);
		}
	}
	for(int i = 1;i <= n; i++) {
		ans1[i] += ans2[i - 1];		
		ans2[i] = ans1[i], ans1[i] = 0;
	}
	tot = 0;
	
	memset(lazy, 0, sizeof(lazy));
	memset(bs, 0, sizeof(bs));
	memset(ll, 0, sizeof(ll));
	memset(rr, 0, sizeof(rr));
	memset(ans1, 0, sizeof(ans1));
	memset(lsh, 0, sizeof(lsh));
	memset(tree, 0, sizeof(tree));
	for(int i = 1;i <= mm; i++) {
		scanf("%d%d", &ll[i], &rr[i]);
		lsh[++tot] = ll[i]; lsh[++tot] = rr[i];
	}
	init();
	for(int i = 1;i <= mm; i++) {
		bs[ p[ll[i]] ] = i; 
		bs[ p[rr[i]] ] = 0 - i;
	}
	build(1, 1, n);
	for(int i = 1;i <= tot; i++) {
		if(bs[i] > 0) {
			ly = 2147483;
			Update(1);
			ll[bs[i]] = ly; 
			if(ly != 2147483 )ans1[ly]++;
		}
		if(bs[i] < 0) {
			l = ll[0 - bs[i]]; r = n;
			Update_2(1);
		}
	}
	for(int i = 1;i <= n; i++) {
		ans1[i] += ans1[i - 1]; 
	}
	for(int i = 0; i <= n; i++)
		ans = max(ans1[i] + ans2[n - i], ans);
	cout<<ans<<endl;
	return 0;	
}
