#include<bits/stdc++.h>
using namespace std;

#define IOR(x, y, z) for(int x = y; x < z; x++)
#define LOR(x, y, z) for(int x = y; x > z; x--)

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
#define V(x) (Turn(A[x]))

const int INF = 0x3f3f3f3f;
const int MAXN = 4e4 + 10;
const int MAXK = 4e3 + 10;

long long A[MAXN], B[MAXN];
long long x;
int Cnt[MAXK][MAXN], L[MAXN], R[MAXN], Pos[MAXN], Qcnt[MAXK][MAXN];
int idx, n, m, len, num;

void Pre();
long long Turn(int x);
long long Ask(int l, int r);

int main() { /**/
#ifdef LOCAL 
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif
    IN >> n >> m; len = pow(n, 1.0 / 3.0);
    IOR(i, 1, n+1) IN >> A[i], B[i] = A[i];

    sort(B+1, B+n+1);
    idx = unique(B+1, B+n+1) - B - 1;

    Pre();

    while(m--) {
        int l, r; IN >> l >> r;
        l = (l + x - 1) % n + 1, r = (r + x - 1) % n + 1;
        if(l > r) swap(l, r);
        printf("%lld\n", x = Ask(l, r));
    }

    return 0;
} /**/

int Turn(long long x) {
    return lower_bound(B+1, B+idx+1, x) - B; } 

void Pre() {
    num = n / len;
    IOR(i, 1, num+1) 
        L[i] = (i-1) * len + 1,
        R[i] = i * len;
    if(R[n/len] < n) L[++num] = R[n/len]+1, R[num] = n;

    IOR(i, 1, num+1) IOR(v, L[i], R[i] + 1) 
        Pos[v] = i, Cnt[i][V(v)]++;
    
    IOR(i, 1, num+1) IOR(v, 1, idx+1) 
        Qcnt[i][v] = Qcnt[i-1][v] + Cnt[i][v];
}

long long Ask(int l, int r) {
    int Tcnt[MAXN]; memset(Tcnt, 0, (idx+1) * sizeof(int));
    int p = Pos[l], q = Pos[r];

    if(p == q) 
        IOR(i, l, r+1) Tcnt[V(i)]++;
    else {
//        IOR(i, p+1, q) IOR(v, 1, idx+1) 
//            Tcnt[v] += Cnt[i][v];
        IOR(v, 1, idx+1)
            Tcnt[v] = Qcnt[q-1][v] - Qcnt[p][v], 
            Tcnt[v] = Tcnt[v] >= 0 ? Tcnt[v] : 0;
        IOR(i, l, R[p]+1) Tcnt[V(i)]++;
        IOR(i, L[q], r+1) Tcnt[V(i)]++;
    }

    long long mx = 0, res = INF;
    IOR(i, 1, idx+1) {
        if(Tcnt[i] > mx) mx = Tcnt[i], res = B[i];                                                                                                       
        else
        if(Tcnt[i] == mx) res = min(res, B[i]);
    }

    return res;
}