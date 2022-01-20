#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 2e6 + 10;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

int Adj[MAXN][27], F[MAXN], Len[MAXN], Size[MAXN], las = 1, sc = 1;
void Extend(char x);

int Cnt[MAXN], Id[MAXN];
int n;
char S[MAXN];

int main() { /**/
    scanf("%s", S+1); n = strlen(S+1);
    IOR(i, 1, n+1) Extend(S[i]);

    IOR(i, 1, sc+1) ++Cnt[Len[i]];
    IOR(i, 1, n+1) Cnt[i] += Cnt[i-1];
    LOR(i, sc, 0) Id[Cnt[Len[i]]--] = i;
    LOR(i, sc, 0) Size[F[Id[i]]] +=  Size[Id[i]]; 

    int ans = 0;
    IOR(i, 1, sc+1) 
        if(Size[i] > 1) ans = max(ans, Size[i] * Len[i]);
    printf("%d", ans);

    return 0;
} /**/

void Extend(char c) {
    int k = c - 'a', x = ++sc, y = las;
    las = x, Len[x] = Len[y] + 1, Size[x] = 1;
    while(y && !Adj[y][k]) Adj[y][k] = x, y = F[y];
    if(!y) F[x] = 1;
    else {
        int z = Adj[y][k];
        if(Len[z] == Len[y]+1) F[x] = z;
        else {
            int w = ++sc;
            memcpy(Adj[w], Adj[z], sizeof Adj[z]);
            F[w] = F[z], Len[w] = Len[y] + 1, F[x] = F[z] = w;
            while(Adj[y][k] == z) Adj[y][k] = w, y = F[y];
        }
    }
}