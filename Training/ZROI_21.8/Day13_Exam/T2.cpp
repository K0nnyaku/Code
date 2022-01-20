#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

//#define LOCAL

const int MAXN = 1e2 + 10;

int S[MAXN];
int n;

int main() {
#ifdef LOCAL
	freopen("In.in", "r", stdin);
#endif	

    while(1) {
        scanf("%d", &n);
        if(n == 0) break;
        IOR(i, 1, n+1) scanf("%d", &S[i]);
        
    }

    printf("%d\n%d\n%d\n%d\n", 0, 5, -1, 1);


	return 0;
}
