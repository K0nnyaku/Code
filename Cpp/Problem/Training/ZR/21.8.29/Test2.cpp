#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std ;
typedef unsigned long long ll ;
const int maxn = 2e5+10 ;
const int INF = 0x3f3f3f3f ;

ll ksm(ll x,ll n,ll mod){
    ll ans = 1LL ;
    while (n){
        if (n&1) ans = ans*x%mod ;
        n>>=1 ;
        x = x*x%mod ;
    }
    return ans ;
}

int main()
{

    cout << ksm(10, 11612903040, 17999999991);
    return 0 ;

}