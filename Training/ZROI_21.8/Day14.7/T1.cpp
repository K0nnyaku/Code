#include<bits/stdc++.h>

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

long long t;

int main() {
    scanf("%lld", &t);
    while(t--) {
        long long x, ans = 0;
        scanf("%lld", &x);

        if(x <= 10) ans += x / 10 * 25, x %= 10;
        if(x && x <= 8) ans += x / 8 * 20, x %= 8;
        if(x && x <= 6) ans += 15;
        
        printf("%lld\n", ans);
    }

    return 0;
}