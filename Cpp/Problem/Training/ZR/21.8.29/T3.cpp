#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)

const int MB=1<<21;
struct FastIN
{
	char buf[MB+100],*p,*e;
	int getChar()
	{
		if(p==e) p=buf,e=buf+fread(buf,1,MB,stdin);
		return p==e?EOF:*p++;
	}
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;

#define F(x) Find(x)

const int MAXN = 1e5 + 10;

int Block;
struct Node {
	int l;
	int r;
	int pos;
	
	friend bool operator<(Node a, Node b) {
		return (a.l / Block) ^ (b.l / Block) ?  a.l < b.l : ((a.l/Block) & 1 ? a.r < b.r : a.r > b.r); }
}Q[MAXN];

int n, q, idx, ans, m;
int A[MAXN], C[MAXN], Ans[MAXN], Cnt[MAXN];

int Find(int x);

int main() { /**/
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif

    IN >> n; 
    IOR(i, 1, n+1) IN >> A[i], C[i] = A[i];
    IN >> m;
    Block = n / sqrt(m * 2 / 3);
    IOR(i, 1, m+1) {
        int l, r;
        IN >> l >> r;
        Q[i] = { l, r, i };
    }
    sort(Q+1, Q+1+m);
    sort(C+1, C+1+n);

    idx = unique(C+1, C+1+n) - C;

    int rp = 1, lp = 1, ans = 1;
    Cnt[F(A[1])]++;

    IOR(i, 1, m+1) {
        int l = Q[i].l, r = Q[i].r;

		while(lp < l) Cnt[F(A[lp++])]--, ans += (Cnt[F(A[lp-1])] % 2 ? 1 : -1); 
		while(lp > l) Cnt[F(A[--lp])]++, ans += (Cnt[F(A[lp])] % 2 ? 1 : -1);
		
		while(rp > r) Cnt[F(A[rp--])]--, ans += (Cnt[F(A[rp+1])] % 2 ? 1 : -1);
		while(rp < r) Cnt[F(A[++rp])]++, ans += (Cnt[F(A[rp])] % 2 ? 1 : -1);

        /*printf("\n---------------\n");
        printf("l = %d, r = %d, lp = %d, rp = %d\n", l, r, lp, rp);
        IOR(i, 1, idx) printf("%d ", Cnt[i]);
        printf("\nans = %d", ans);
        printf("\n---------------\n");*/

        Ans[Q[i].pos] = ans;
    }

    IOR(i, 1, m+1) 
        printf("%d\n", Ans[i]);

    return 0;
} /**/

int Find(int x) {
    return lower_bound(C+1, C+1+idx, x) - C;
}