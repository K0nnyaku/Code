#include<cstdio>
#include<algorithm>
#define IOR(x, y, z) for(int x = (y); (x) < (z); x++)
#define LOR(x, y, z) for(int x = (y); (x) > (z); x--)

#define MID ((l+r)>>1)
#define LC(x) (Tr[(x)].lc)
#define RC(x) (Tr[(x)].rc)
using namespace std;
const int MAXN = 1e6 + 10;

/*Seg_W*/
struct Seg_W { int lc, rc, val; } Tr[MAXN<<5];

int idx;
int Rt[MAXN]; 

void Ins(int &x, int l, int r, int v);
int Copy(int x) { Tr[++idx] = Tr[x]; return idx; }
int Query(int ft, int sd, int l, int r, int L, int R);
/*Seg_W*/

int n, m, ans;
int Mp[MAXN], A[MAXN];

int F(int x);

int main() { /**/

#ifdef LOCAL
    freopen("In.in", "r", stdin);
#endif

    scanf("%d", &n);
    IOR(i, 1, n+1) {
        int x; scanf("%d", &x);
        Mp[x] = i;
    }
    IOR(i, 1, n+1) {
        int x; scanf("%d", &x);
        A[i] = Mp[x];
    } 
    IOR(i, 1, n+1) {
        Rt[i] = Rt[i-1];
        Ins(Rt[i], 1, n, A[i]);
    }

    scanf("%d", &m);
    while(m--) {
        int a_, b_, x_, y_, a, b, x, y;
        scanf("%d%d%d%d", &a_, &b_, &x_, &y_);
        a = min(F(a_), F(b_)); b = max(F(a_), F(b_));
        x = min(F(x_), F(y_)); y = max(F(x_), F(y_));
        ans = Query(Rt[x-1], Rt[y], 1, n, a, b) + 1;
        printf("%d\n", ans-1);
    }

    return 0; 
} /**/

void Ins(int &x, int l, int r, int v) {
    x = Copy(x); Tr[x].val++;
    if(l == r) return ;
    if(v <= MID) Ins(LC(x), l, MID, v);
    else Ins(RC(x), MID+1, r, v);
}

int Query(int ft, int sd, int l, int r, int L, int R) {
    if(l >= L && r <= R) return Tr[sd].val - Tr[ft].val;

    int sum = 0;
    if(L <= MID) sum += Query(LC(ft), LC(sd), l, MID, L, R);
    if(R > MID) sum += Query(RC(ft), RC(sd), MID+1, r, L, R); 

    return sum;
}

int F(int x) {
    return (x-1+ans)%n+1;
}