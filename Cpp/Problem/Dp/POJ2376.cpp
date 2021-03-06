#include<bits/stdc++.h>
//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<cstring>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

struct FastIN
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getchar())l=c;
		for(x=0;isdigit(c);c=getchar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;

const int _N = 2e5 + 2;
const int _V = 1e6 + 2;
const int INF = 0x3f3f3f3f;

struct Seg {
	int lc, rc, val;
	Seg(int _lc = 0, int _rc = 0, int _val = INF) {
		lc = _lc, rc = _rc, val = _val;
	}
} Tr[_V << 1];
int rt = 1, idx = 1;
int Ask(int L, int R, int l = 0, int r = _V, int x = rt);
void Cg(int pos, int k, int l = 0, int r = _V, int &x = rt);
int New();
void Up(int x);
#define MID ((l + r) >> 1)
#define L(x) Tr[x].lc
#define R(x) Tr[x].rc
#define V(x) Tr[x].val

struct Cow {
	int l, r, val;
	friend bool operator<(const Cow &x, const Cow &y) {
		return x.r < y.r;
	}
} C[_N];

int F[_V];
int n, ans = INF, st, ed;

int main() { /**/
#ifdef LOCAL
//	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Data\\1672\\8.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	Tr[0].val = INF;
	IN >> n >> st >> ed;
	st++, ed++;
	IOR(i, 0, n) 
		IN >> C[i].l >> C[i].r >> C[i].val, 
		C[i].l++, C[i].r++;

	sort(C, C+n);
	
	memset(F, 0x3f, sizeof F);
	F[st-1] = 0;
	Cg(st-1, 0);

	IOR(i, 0, n) {
		int tmp = Ask(C[i].l-1, C[i].r-1) + C[i].val;
		if(tmp < F[C[i].r]) {
			F[C[i].r] = tmp;
			Cg(C[i].r, tmp);
		}
	}

	IOR(i, ed, _V) 
		ans = min(ans, F[i]);

	cout << (ans != INF ? ans : -1);

	return 0;
} /**/

void Cg(int pos, int k, int l, int r, int &x) {
	if(!x) x = New();
	if(l == r) { V(x) = k; return ; }

	if(pos <= MID) Cg(pos, k, l, MID, L(x));
	else Cg(pos, k, MID+1, r, R(x));

	Up(x);
}

int Ask(int L, int R, int l, int r, int x) {
	if(!x) return INF;
	if(l >= L && R >= r) return V(x);
	
	int res = INF;
	if(L <= MID) res = min(res, Ask(L, R, l, MID, L(x)));
	if(R > MID) res = min(res, Ask(L, R, MID+1, r, R(x)));

	return res;
}

int New() {
	return ++idx;
}

void Up(int x) {
	V(x) = min(V(L(x)), V(R(x)));
}














