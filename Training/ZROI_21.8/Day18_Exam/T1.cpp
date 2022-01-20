#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define ZERO(x) memset(x, 0, sizeof x);

const int MB=1<<21;
struct FastIO
{
	char buf[MB+100],*p,*e;
	int getChar()
	{
		if(p==e) p=buf,e=buf+fread(buf,1,MB,stdin);
		return p==e?EOF:*p++;
	}
	template<typename T>
	FastIO& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IO;

const int MAXN = 1e6 + 10;

long long W[MAXN<<1], A[MAXN], B[MAXN];
int n, idx = 1;

bool Check(int mid);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    IO >> n;
    IOR(i, 1, n+1) { IO >> A[i]; W[idx++] = A[i]; }
    IOR(i, 1, n+1) { IO >> B[i]; W[idx++] = B[i]; } 

    W[0] = 0;
    sort(W, W+idx);
    idx = unique(W, W+idx) - W; 

//    IOR(i, 0, idx) printf("%d ", W[i]);

    int l = 0, r = idx;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(Check(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%lld", W[l]);

	return 0;
} /**/

bool Check(int mid) {
    long long x = W[mid], t = 0;
    IOR(i, 1, n+1) {
        if(A[i] > x) {
            if(t == 0) t = A[i];
            else if(t == A[i]) t = 0;
            else return false;
        }
    }
    if(t != 0) return false;

    t = 0;
    IOR(i, 1, n+1) {
        if(B[i] > x) {
            if(t == 0) t = B[i];
            else if(t == B[i]) t = 0;
            else return false;
        }
    }

    return t == 0;
}