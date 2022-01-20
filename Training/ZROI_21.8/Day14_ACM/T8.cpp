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
};

const int MAXN = 2e5 + 10;

int Out[MAXN*2];
struct Node {
    int x;
    int y;
    bool friend operator<(Node x, Node y) {
        return Out[x.y] < Out[y.y];
    }
}Eg[MAXN*3];

int n, iNdex;

int main() {
    scanf("%d", &n);
    IOR(i, 1, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        Out[x]++;
        Out[y]++;
        Eg[++iNdex].x = x; Eg[iNdex].y = y;
        Eg[++iNdex].x = y; Eg[iNdex].y = x;
    }
    
    sort(Eg+1, Eg+1+iNdex);

    IOR(i, 1, iNdex+1) {
        printf("%d %d\n", Eg[i].x, Eg[i].y);
    }

    return 0;
}
