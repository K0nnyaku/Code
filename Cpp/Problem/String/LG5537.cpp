#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);

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

const int MAXN = 5e5 + 10;
const int P = 131;
typedef unsigned long long ULL;

struct Seg {
    unsigned long long val;
    int lc, rc, l, r;
    static int idx;

    void Modify(int pos, int x);
    void Up();
    void Init(int L, int R);
    int New(int _val = 0);
    unsigned long long Ask(int L, int R);
}Sg[MAXN];

vector<int> Tr[MAXN];

struct Node{ 
    ULL val; 
    int pos; 

    friend bool operator<(Node x, Node y) {
        return x.val < y.val;
    }
}H[MAXN];

unsigned long long E[MAXN] = {1}, Fh[MAXN], Ah[MAXN];
long long A[MAXN];
int Dep[MAXN];
int n, m, q, ans, rt;

void Pre(int now, int e, unsigned long long x);
void Depth(int now, int last);
int Check(int l, int k, int x);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    IN >> n >> m >> q;
    IOR(i, 1, n+1) {
        int x;
        IN >> x, Tr[x].push_back(i);
        if(x == 0) rt = i;
    }
    Seg::idx = 1;
    Sg[0].Init(1, n);

    IOR(i, 1, n+1) 
        sort(&Tr[i], &Tr[i] + Tr[i].size());
    Pre(rt, 0, 0);
    Depth(rt, -1);

    IOR(i, 0, m) IN >> A[i];
    IOR(i, 0, MAXN) E[i] = E[i-1] * P;
    IOR(i, 0, m) 
        Ah[i] = Ah[i-1] + A[i] * E[i];

    sort(H, H+m);

    while(q--) {
        int opt, x, l, r, t, k;
        ans = 0;
        IN >> opt;
        
        if(opt == 1) {
            IN >> l >> r >> x;
            int L = 1, R = r - l + 1, k = 0;
            for(int p = 1; p <= l - r + 1; ) {
                ans = Check(l, k, x);
                if(ans) k += p, p *= 2;
                else p /= 2;
            }
            printf("%d\n", ans);
        }
        else
            IN >> t >> k, Sg[0].Modify(t, k);
    }

	return 0;
} /**/

int Check(int l, int k, int x) {
    int L = 1, R = MAXN;
    while(L < R) {
        int mid = (L + R) >> 1;
        if(Fh[x] + H[mid].val * E[Dep[H[mid].pos] - Dep[x]] < Sg[0].Ask(l, l+k)) L = mid + 1;
        else 
        if(Fh[x] + H[mid].val * E[Dep[H[mid].pos] - Dep[x]] > Sg[0].Ask(l, l+k)) R = mid - 1;
        else
        return H[mid].pos;
    }
    return 0;
}

int Seg::New(int _val) {
    Sg[++idx].val = _val; return idx;
}
unsigned long long Seg::Ask(int L, int R) {
    if(L >= l && R <= r) return val;

    unsigned long long res = 0;
    if(Sg[lc].r >= L) res += Sg[lc].Ask(L, R); 
    if(Sg[rc].l <= R) res += Sg[rc].Ask(L, R);
    return res;
}
void Seg::Modify(int pos, int x) {
    if(l == r) { val = x; return ; }

    int mid = (l + r) >> 1;
    if(pos <= mid) Sg[lc].Modify(pos, x);
    else Sg[rc].Modify(pos, x);
}
void Seg::Init(int L, int R) {
    l = L, r = R;
    if(L == R) { val = A[L]; return ; }
    
    int mid = (L + R) >> 1;
    lc = New(); Sg[lc].Init(L, mid);
    rc = New(); Sg[rc].Init(mid+1, R);
    Up();
}
void Seg::Up() {
    val = Sg[lc].val + Sg[rc].val; }


void Pre(int now, int e, unsigned long long x) {
    H[now].val = x + now * E[e]; 
    H[now].pos = now; Fh[now] = H[now].val;
    IOR(i, 0, Tr[now].size()) 
        Pre(Tr[now][i], e+1, H[now].val);
}

void Depth(int now, int last) {
    IOR(i, 0, Tr[now].size()) if(Tr[now][i] != last) 
        Dep[Tr[now][i]] = Dep[now] + 1, Depth(Tr[now][i], now);
}