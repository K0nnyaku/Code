#include<bits/stdc++.h>
using namespace std;
#define IOR(x, y, z) for(int x = y; x < z; x++)
#define LOR(x, y, z) for(int x = y; x > z; x--)

const int MB = 1 << 21;
struct FastIN {
    char Buf[MB+100], *p, *e;
    int Getchar() {
        if(p == e) p = Buf, e = Buf+fread(Buf, 1, MB, stdin);
        return p == e ? EOF : *p++;
    }
    template<typename T>
    FastIN& operator>>(T& x) {
        char c, l;
        for(c = 0; !isdigit(c); c = Getchar()) l = c;
        for(x = 0; isdigit(c); c = Getchar()) x = x * 10 + c - '0';
        if(l == '-') x = -x;
        return *this;
    }
} IN;

const int MAXN = 5e4 + 10;

long long Mu[MAXN], Q[MAXN];
int n, m, t;

void Pre();
long long Wk(int x, int y);

int main() { /**/
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif
    Pre();

    IN >> t;
    while(t--) {
        IN >> n >> m;
        printf("%lld\n", Wk(n, m));
    }

    return 0;
} /**/

long long Wk(int x, int y) {
    long long res = 0;
    if(x > y) swap(x, y);
    for(int l = 1, r; l <= x; l = r + 1) {
        r = min(x / (x / l), y / (y / l));
        res += (Mu[r] - Mu[l - 1]) * Q[x/l] * Q[y/l];
    }
    return res;
}

int Prime[MAXN], idx;
bool Vis[MAXN];
void Pre() {
    Mu[1] = 1;
    IOR(i, 2, MAXN) {
        if(!Vis[i]) 
            Prime[idx++] = i, Mu[i] = -1;
        IOR(v, 0, idx && Prime[v] * i < MAXN) {
            Vis[i*Prime[v]] = 1;

            if(!(i % Prime[v])) {
                Mu[i * Prime[v]] = 0;
                break;
            }

            Mu[i*Prime[v]] = -Mu[i];
        }
    }

    IOR(i, 1, MAXN) 
        Mu[i] += Mu[i-1];

    IOR(i, 1, MAXN)
        for(int l = 1, r; l <= i; l = r + 1) 
            r = i / (i / l), Q[i] += (long long)(r - l + 1) * (i / l);
}