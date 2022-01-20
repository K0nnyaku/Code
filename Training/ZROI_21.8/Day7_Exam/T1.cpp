#include<cstdio>
#include<algorithm>
using namespace std;
#define LOCAL
const int MAXN = 1e5 + 10;

long long Pt[MAXN];
long long k, n;

int main() {
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif 

    scanf("%lld%lld", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%lld", &Pt[i]);

    sort(Pt + 1, Pt + n + 1);

    int ans = 0, l = 1;
    while(l <= n) {
        long long ck = Pt[l] + k;
        int r = n;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(Pt[mid] <= ck) l = mid;
            else r = mid - 1;
        }
    
       // printf("ck = %d, l = %d\n",ck, l);
        l++;
        ans++;
    }

    printf("%d", ans);

    return 0;
}