#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
#define LOCAL

long long A[MAXN], B[MAXN];
int n, m, q;

int main() {
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif

    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; i++) 
        scanf("%lld", &A[i]);
    for(int i = 1; i <= m; i++)
        scanf("%lld", &B[i]);
    
    while(q--) {
        long long T[MAXN];
        long long id, x, iNdex = 0;
        scanf("%lld%lld", &id, &x);
        if(id == 1) {
            for(int i = 1; i <= n; i++) T[iNdex++] = A[i] + x;
            for(int i = 1; i <= m; i++) T[iNdex++] = B[i];
        }
        else {
            for(int i = 1; i <= m; i++) T[iNdex++] = B[i] + x;
            for(int i = 1; i <= n; i++) T[iNdex++] = A[i];
        }

        sort(T, T + iNdex);

        if(iNdex % 2) printf("%lld\n", T[iNdex/2]);
        else {
            if((T[iNdex/2-1] + T[iNdex/2]) % 2) 
                printf("%.1lf\n", (double)(T[iNdex/2-1] + T[iNdex/2])/2);
            else 
                printf("%.0lf\n", (double)(T[iNdex/2-1] + T[iNdex/2])/2);
        } 
            
    }

    return 0;
}