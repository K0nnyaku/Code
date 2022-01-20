#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);

const int MAXN = 1e5 + 10;
const double E = 1e-7;

long double A[MAXN<<1];
long double s;
int k;

int main() {
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif
    cin >> s >> k;
    IOR(i, 0, k) 
        cin >> A[i];
    sort(A, A+k);

    IOR(i, 0, k) {
        if(s * A[i] - (s + A[i]) > E) s *= A[i];
        else s += A[i];
    }

    printf("%Lf", s);

    return 0;
}
