#include<bits/stdc++.h>

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

const int MB=1<<21;
struct FastIO {
	char buf[MB+100],*p,*e;
	int getChar() { if(p==e)p=buf,e=buf+fread(buf,1,MB,stdin); return p==e?EOF:*p++; }
	template<typename T>
	FastIO& operator>>(T& x) { char c,l; for(c=0;!isdigit(c);c=getChar())l=c; for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c; if(l=='-')x=-x; return *this; }
}IO;

const int MAXN = 1e5 + 10;
long long A[MAXN];
long long n, ans;

int main() {
//    freopen("In.in", "r", stdin);
    IO>>n;
    IOR(i, 1, n+1) IO>>A[i];

    IOR(i, 1, n+1) {
        if(A[i-1] <= A[i]) ans += A[i] - A[i-1];
        if(A[i+1] <= A[i]) ans += A[i] - A[i+1];
    }
    ans += n;

    printf("%lld", ans);

    return 0;
}