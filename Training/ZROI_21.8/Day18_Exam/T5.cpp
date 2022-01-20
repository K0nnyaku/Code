#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define ZERO(x) memset(x, 0, sizeof x);

const int MAXN = 4 + 10;

long long n, m, ans;

int Turn(int x, int y);

bool Check(int x);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    scanf("%lld%lld", &n, &m);

    for(int i = 0; i < (1 << (n*m)); i++) {
        if(Check(i)) ans++;
    }

    printf("%lld", ans);

	return 0;
} /**/

bool Check(int z) {
    IOR(x, 0, n) {
        int temp = 0;
        IOR(y, 0, m) 
            if(z >> (Turn(x, y)) & 1) temp++;
        if(temp > 3) return false;
    }

    IOR(y, 0, m) {
        int temp = 0;
        IOR(x, 0, n) 
            if((z >> Turn(x, y)) & 1) temp++;
        if(temp > 3) return false;
    }
    return true;
}

int Turn(int x, int y) {
    return y * n + x;
}
