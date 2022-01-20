#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

const int MAXN = 1e5 + 10;

long long n, m, len;
long long A[MAXN];

bool Check(long long x);

int main() {
    scanf("%lld%lld%lld", &n, &m, &len);
    IOR(i, 1, n+1) { scanf("%lld", &A[i]); }

    sort(A+1, A+1+n);

    long long l = 1, r = len;
    while(l < r) {
        long long mid = (l + r) >> 1;
        if(Check(mid)) r = mid;
        else l = mid+1;
    }
    
    printf("%lld", l);

    return 0;
}

bool Check(long long x) {
    long long sum = 0;
    sum += min(A[1] - 1, x);
    IOR(i, 1, n) {
        long long tlen = A[i+1] - A[i] - 1;
        if(tlen >= x * 2)  sum += x * 2;
        else sum += tlen;
    }
    sum += min(len - A[n], x);
//    printf("x = %lld, sum = %lld\n", x, sum);
    return sum >= m;
}