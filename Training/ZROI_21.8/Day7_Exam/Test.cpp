#include<cstdio>
#include<algorithm>
using namespace std;

long long Gcd(long long a, long long b);

int main() {
    printf("%lld", Gcd(5, 2));

    return 0;
}

long long Gcd(long long a, long long b) {
    return b ? Gcd(b, a % b) : a;
}