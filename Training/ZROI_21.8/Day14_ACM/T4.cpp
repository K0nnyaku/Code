#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

const int MB=1<<21;
struct FastIO {
	char buf[MB+100],*p,*e;
	int getChar() { if(p==e)p=buf,e=buf+fread(buf,1,MB,stdin); return p==e?EOF:*p++; }
	template<typename T>
	FastIO& operator>>(T& x) { char c,l; for(c=0;!isdigit(c);c=getChar())l=c; for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c; if(l=='-')x=-x; return *this; }
}IO;

queue<int> Ans;
long long N, M, Sum;

int main() {
    scanf("%lld%lld", &N, &M);

    if(N == 0) {
        if(M == 1) printf("0");
        else printf("-1");
        return 0;
    }

    IOR(i, 1, M+1) {
        LOR(j, 9, -1) {
            if(N >= j) { N -= j; Ans.push(j); break; }
        }
    }

    if(N != 0) {
        printf("-1");
        return 0;
    }

    while(!Ans.empty()) {
        printf("%d", Ans.front());
        Ans.pop();
    }

    return 0;
}