#include<bits/stdc++.h>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);
#define T(x) E[x].to
#define V(x) E[x].val

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

#define MID ((l + r) >> 1)
#define LC(x) Tr[x].lc
#define RC(x) Tr[x].rc

const int MAXN = 2e5 + 10;

struct Seg { 
    int lc, rc, val, size;
    Seg() { lc = rc = val = size = 0; } 
} Tr[MAXN * 40];
int Rt[MAXN * 40], idx = MAXN;

void Init(int &x, int l, int r);
Seg* Cg(int &x, int l, int r, int pos);
Seg* Ask(int x, int l, int r, int pos);
int Copy(int x) { 
    Tr[++idx] = Tr[x]; return idx; }

int n, m, k, tot;

void Union(int x, int y, int ver);
int FindFa(int x, int ver);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    IN >> n >> m;
    Init(Rt[0], 1, n);
    
    IOR(i, 1, m+1) {
        int opt, a, b;
        IN >> opt;
        Rt[i] = Rt[i-1];
        switch(opt) {
            case 1: IN >> a >> b; Union(a, b, i); break;
            case 2: IN >> k; Rt[i] = Rt[k]; break;
            default : IN >> a >> b; printf("%d\n", FindFa(a, i) == FindFa(b, i));
        }
    }

	return 0;
} /**/

void Union(int x, int y, int ver) {
    int fy = FindFa(y, ver), fx = FindFa(x, ver);

    int sx = Ask(Rt[ver], 1, n, fx)->size, sy = Ask(Rt[ver], 1, n, fy)->size;
    if(sx > sy) swap(fx, fy), swap(sx, sy);

    Cg(Rt[ver], 1, n, fx)->val = fy;
    Cg(Rt[ver], 1, n, fy)->size += sx;
}

int FindFa(int x, int ver) {
    int fa = Ask(Rt[ver], 1, n, x)->val;
    if(fa != x) return FindFa(fa, ver);
    return fa;
}

void Init(int& x, int l, int r) {
    x = Copy(x);
    if(l == r) { Tr[x].val = l; Tr[x].size = 1; return ; }
    Init(LC(x), l, MID); Init(RC(x), MID+1, r);
}

Seg* Cg(int &x, int l, int r, int pos) {
    x = Copy(x); 
    if(l == r) { return &Tr[x]; }

    if(pos <= MID) return Cg(LC(x), l, MID, pos);
    else return Cg(RC(x), MID+1, r, pos);
}

Seg* Ask(int x, int l, int r, int pos) {
    if(l == r) return &Tr[x];

    if(pos <= MID) return LC(x) ? Ask(LC(x), l, MID, pos) : 0;
    else return RC(x) ? Ask(RC(x), MID+1, r, pos) : 0;
}