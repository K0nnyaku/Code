#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);

#define T(x) E[x].to

const int MAXN = 5e5 + 10;

struct { int to, next; } E[MAXN<<1];
int Head[MAXN], idx;
void Add(int pre, int _to) {
    E[++idx] = { _to, Head[pre] }; Head[pre] = idx; }

int F[MAXN][3][2];
int len, pos;
char S[MAXN];

void Pre(int x, char* ch);
void Wk(int x);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    scanf("%s", S); len = strlen(S);

    Pre(0, S);
    Wk(0);

    printf("%d %d", max( F[0][0][0], max(F[0][1][0], F[0][2][0]) ), 
        min( F[0][0][1], min(F[0][1][1], F[0][2][1]) ) ); 

	return 0;
} /**/

void Wk(int x) {
    EOR(i, x) 
        Wk(T(i));
    
    F[x][0][0] = F[x][0][1] = 1;
    if(!T(x)) return ;

    int lc = E[Head[x]].to ? E[Head[x]].to : idx+1, rc = E[E[Head[x]].next].to ? E[E[Head[x]].next].to : idx+1;
    printf("%d %d %d\n", x, lc, rc);
    F[x][0][0] += max(F[lc][1][0] + F[rc][2][0], F[lc][2][0] + F[rc][1][0]);
    F[x][1][0] += max(F[lc][0][0] + F[rc][2][0], F[lc][2][0] + F[rc][0][0]);
    F[x][2][0] += max(F[lc][0][0] + F[rc][1][0], F[lc][1][0] + F[rc][0][0]);

    F[x][0][1] += min(F[lc][1][1] + F[rc][2][1], F[lc][2][1] + F[rc][1][1]);
    F[x][1][1] += min(F[lc][0][1] + F[rc][2][1], F[lc][2][1] + F[rc][0][1]);
    F[x][2][1] += min(F[lc][0][1] + F[rc][1][1], F[lc][1][1] + F[rc][0][1]);
}

void Pre(char* ch) {
     
}