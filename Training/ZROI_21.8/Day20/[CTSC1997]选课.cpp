#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define T(x) E[x].to

const int MAXN = 300 + 10;
const int MAXM = 300 + 10;

struct { int to, next; } E[MAXM<<2];
int Head[MAXN], idx;
void Add(int pre, int _to) { 
    E[++idx] = { _to, Head[pre] }; Head[pre] = idx; }

int Pt[MAXN], F[MAXN][MAXN];
int n, m;

void Wk(int x);

int main() { /**/

    scanf("%d%d", &n, &m);
    IOR(i, 1, n+1) {
        int k; scanf("%d%d", &k, &Pt[i]);
        Add(k, i); 
    }

    Wk(0);

    printf("%d", F[0][m]);

    return 0;
} /**/

void Wk(int x) {
    EOR(i, x) {
        Wk(T(i));        

        LOR(k, m, -1) IOR(v, 0, k+1) 
            F[x][k] = max(F[x][k], F[T(i)][v] + F[x][k-v]);
    } 

    if(x) LOR(i, m, 0) F[x][i] = F[x][i-1] + Pt[x];
}