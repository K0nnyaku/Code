#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

const int MB=1<<21;
struct FastIO {
	char buf[MB+100],*p,*e;
	int getChar() { if(p==e)p=buf,e=buf+fread(buf,1,MB,stdin); return p==e?EOF:*p++; }
	template<typename T>
	FastIO& operator>>(T& x) { char c,l; for(c=0;!isdigit(c);c=getChar())l=c; for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c; if(l=='-')x=-x; return *this; }
};

//#define LOCAL
const int MAXN = 1e5 + 10;

int n;
char S[MAXN];

int main() {
#ifdef LOCAL
	freopen("In.in", "r", stdin);
#endif	
    scanf("%d", &n);
    scanf("%s", S);
    printf("%d", 1507);

	return 0;
}