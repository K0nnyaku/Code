#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define ll long long

using namespace std;

int read() {
	int x = 0, f = 1; char ch;
	ch = getchar();
	while(ch > '9' || ch < '0') {if(ch == '-') f = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

struct fj {
	int s, e;
}a[100005], b[100005];

//struct node {
//	int k, tim;
//	bool operator < (const node &x) const {return x.tim < tim;}
//};

//priority_queue<node> que;

int n, m1, m2, cnta, cntb;

int f1[100005], f2[100005], visa[100005], visb[100005], na[100005], nb[100005], la[100005], lb[100005];

void read_it() {
	n = read(); m1 = read(); m2 = read();
	for(int i = 1; i <= m1; i++) {a[i].s = read(); a[i].e = read();}
	for(int i = 1; i <= m2; i++) {b[i].s = read(); b[i].e = read();}
}

int sea(int u) {
	if(!visa[u]) return u;
	na[u] = sea(na[u]);
	return na[u];
}

int finda(int u) {
	int l = u + 1, r = m1, mid, k = a[u].e;
//	mid = (l + r) >> 1;
//	while(visa[mid] == 1) {
//		l = mid + 1;
//		mid = (l + r) >> 1;
//	}
	while(l < r) {
		mid = (l + r) >> 1;
		if(a[mid].s < k) l = mid + 1;
		else r = mid;
	}
	if(visa[l]) l = sea(l);
	return l;
}

bool mysort(fj p, fj q) {
	return p.s < q.s;
}

void dfsa(int u) {
	int nex = finda(u);
//	printf("find : %d -> %d\n", u, nex);
	if(a[nex].s <= a[u].e) return;
	f1[cnta]++;
	visa[nex] = 1;
	la[na[nex]] = la[nex];
	na[la[nex]] = na[nex];
	dfsa(nex);
}

int seb(int u) {
	if(!visb[u]) return u;
	nb[u] = seb(nb[u]);
	return nb[u];
}

int findb(int u) {
	int l = u + 1, r = m2, mid, k = b[u].e;
//	mid = (l + r) >> 1;
//	while(visb[mid] == 1) {
//		l = mid + 1;
//		mid = (l + r) >> 1;
//	}
	while(l < r) {
		mid = (l + r) >> 1;
		if(b[mid].s < k) l = mid + 1;
		else r = mid;
	}
	if(visb[l]) l = seb(l);
	return l;
}

void dfsb(int u) {
	int nex = findb(u);
//	printf("find : %d -> %d\n", u, nex);
	if(b[nex].s <= b[u].e) return;
	f2[cntb]++; visb[nex] = 1; dfsb(nex);
}

void solve() {
	sort(a + 1, a + m1 + 1, mysort);
	for(int i = 1; i <= m1; i++) {na[i] = i + 1; la[i] = i - 1;}
	for(int i = 1; i <= m1; i++) {
		if(visa[i]) continue;
		f1[++cnta] = 1;
		if(cnta > n) break;
		dfsa(i);
	}
	for(int i = 1; i <= n; i++) f1[i] = f1[i] + f1[i - 1];
	
	sort(b + 1, b + m2 + 1, mysort);
	for(int i = 1; i <= m2; i++) {nb[i] = i + 1; la[i] = i - 1;}
	for(int i = 1; i <= m2; i++) {
		if(visb[i]) continue;
		f2[++cntb] = 1;
		if(cntb > n) break;
		dfsb(i);
	}
	for(int i = 1; i <= n; i++) f2[i] = f2[i] + f2[i - 1];
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	read_it();
	solve();
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		if(i > m1) continue;
		if(n - i > m2) continue; 
		ans = max(ans, f1[i] + f2[n - i]);
	}
	printf("%d\n", ans);
//	for(int i = 1; i <= n; i++) printf("%d ", f1[i]); printf("\n");
	fclose(stdin); fclose(stdout);
	return 0;
}

