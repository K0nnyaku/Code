#include<bits/stdc++.h> 
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);
#define T(x) E[x].to
#define V(x) E[x].val

const int MAXN = 1e5 + 10;

long long A[MAXN], Q[MAXN], Add[MAXN];
int L[MAXN], R[MAXN], Pos[MAXN];
int n, k, q;

void Pre();
void Change(int l, int r, long long x);
long long Ask(int l, int r);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    scanf("%d%d", &n, &q); k = sqrt(n);
    IOR(i, 1, n+1) scanf("%lld", &A[i]);

    Pre();
    while(q--) {
        getchar();
        char opt = getchar();
        int l, r;
        long long x;
        if(opt == 'C') 
            scanf("%d%d%lld", &l, &r, &x),
            Change(l, r, x);
        else
            scanf("%d%d", &l, &r),
            printf("%lld\n", Ask(l, r));
    }

	return 0;
} /**/

void Pre() {
    IOR(i, 1, k+1) 
        L[i] = (i - 1) * k + 1,
        R[i] = i * k;
    if(R[k] < n) k++, L[k] = R[k-1] + 1, R[k] = n;

    IOR(i, 1, k+1) 
        IOR(v, L[i], R[i] + 1) Q[i] += A[v], Pos[v] = i; 
}

void Change(int l, int r, long long x) {
    int p = Pos[l], q = Pos[r];
    if(p == q) {
        IOR(i, l, r+1) A[i] += x;
        Q[p] += (r - l + 1) * x;
        return ;
    }

    IOR(i, p+1, q) Add[i] += x;

    IOR(i, l, R[p]+1) A[i] += x;
    Q[p] += (R[p] - l + 1) * x;

    IOR(i, L[q], r+1) A[i] += x;
    Q[q] += (r - L[q] + 1) * x;
}

long long Ask(int l, int r) {
    long long res = 0;
    int p = Pos[l], q = Pos[r];
    if(p == q) {
        IOR(i, l, r+1) res += A[i];
        res += (r - l + 1) * Add[p];
        return res;
    }

    IOR(i, p+1, q) res += Q[i] + (R[i] - L[i] + 1) * Add[i];

    IOR(i, l, R[p]+1) res += A[i];
    res += Add[p] * (R[p] - l + 1);

    IOR(i, L[q], r+1) res += A[i];
    res += Add[q] * (r - L[q] + 1);

    return res;
}