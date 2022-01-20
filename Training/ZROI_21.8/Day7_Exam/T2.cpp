#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e3 + 10;
#define LOCAL

struct Frac {
    long long up;
    long long down;
    
    Frac(long long _up = 0, long long _down = 0) { up = _up; down = _down; }

    void Simple();
    void Output();
};

long long Mp[MAXN][MAXN], Q[MAXN];
long long n, s, mxx;

long long Gcd(long long a, long long b);

int main() {
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif 

    scanf("%lld%lld", &n, &s);  

    for(int i = 1; i < MAXN; i++)
        for(int j = 1; j < MAXN; j++)  
            Mp[i][j] = 1;
        
    for(int i = 1; i <= n; i++) {
        long long x;
        scanf("%lld", &x);
        for(int j = 1; j <= x; j++) 
            Mp[i][j] = 0;
        mxx = max(mxx, x);
    }

    for(int i = 1; i <= mxx; i++) 
        for(int j = 1; j <= n; j++) 
            Q[i] += Mp[j][i];
    
    for(int i = 1; i <= mxx; i++)
        Q[i] += Q[i-1];

    if(s > Q[mxx]) {
        printf("%lld", mxx + (s - Q[mxx]) / n);
        Frac T = Frac((s - Q[mxx]) % n, n);
        T.Output();
        return 0;
    }

    long long l = 1, r = mxx;
    while(l < r) {
        long long mid = (l + r + 1) >> 1;
        if(Q[mid] <= s) l = mid;
        else r = mid - 1;
    }

    printf("%lld", l);
    if(s - Q[l]) {
        Frac T = Frac(s-Q[l], Q[l+1] - Q[l]);
        T.Output();
    }

    return 0;
}

long long Gcd(long long a, long long b) {
    return b ? Gcd(b, a % b) : a;
}

void Frac::Simple() {
    if(!up || !down) return;

    long long gcd = Gcd(up, down);
    up /= gcd; down /= gcd;
}

void Frac::Output() {
    Simple();
    if(!up || !down) return;

    printf("+%d/%d", up, down);
}