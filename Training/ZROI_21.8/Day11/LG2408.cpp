#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1e5 + 10;
#define IOR(i, st, ed) for(int i = st; i < ed; i++)

long long Hg[MAXN], Rk[MAXN], Sa[MAXN], Kr[MAXN];
int len, e;
char S[MAXN];

int main() {
    scanf("%d", &len);
    scanf("%s", S+1);
    IOR(i, 1, len+1) 
        Sa[i] = i, Rk[i] = S[i];

    for(e = 1; e < len; e <<= 1) {
        sort(Sa+1, Sa+1+len, [](int x, int y) { 
            return Rk[x] == Rk[y] ? Rk[x+e] < Rk[y+e] : Rk[x] < Rk[y]; });

        memcpy(Kr, Rk, sizeof Rk);

        int p = 0;
        IOR(i, 1, len+1) {
            if(Kr[Sa[i]] == Kr[Sa[i-1]] && Kr[Sa[i-1] + e] == Kr[Sa[i] + e])
                Kr[Sa[i]] = p;
            else Kr[Sa[i]] = ++p;
        }
    }

    int k = 0;
    IOR(i, 1, len+1) {
        if(k) k--;
        while(S[i + k] == S[Sa[Rk[i] - 1] + k]) k++;
        Hg[Rk[i]] = k;
    }

    long long ans = (long long)len * (len+1) / 2;
    IOR(i, 2, len+1) ans -= Hg[i];
    
    for(int i = 1; i <= len; i++) 
        printf("i = %d, Hg = %d\n", i, Hg[i]);
    printf("%lld", ans);

    return 0;
}