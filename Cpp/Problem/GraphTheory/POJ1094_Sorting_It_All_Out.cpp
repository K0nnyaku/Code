#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define T(x) E[x].to
#define V(x) E[x].val

struct FastIN
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getchar())l=c;
		for(x=0;isdigit(c);c=getchar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;

const int MAXN = 26 + 10;

struct { int u, v; }Re[MAXN];

bool E[MAXN][MAXN];
int n, m;

void Init();
void Floyd();

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    while(IN >> n >> m && n && m) {
        IOR(i, 0 m) {
            char a, b, opt; 
            getchar();
            a = getchar(), opt = getchar(), b = getchar();

            Re[i].u = a - 'A' + 1;
            Re[i].v = b - 'A' + 1;

            if(opt == '<') swap(Re[i].a, Re[i].b);

            E[Re[i].u][Re[i].v] = 1;
        } 
        Floyd();
    }

	return 0;
} /**/

void Init() {
    memset(E, 0, sizeof E);
}

void Floyd() {
    IOR(k, 1, n+1) IOR(i, 1, n+1) IOR(v, 1, n+1) 
        E[i][v] |= E[i][k] & E[k][v];
}