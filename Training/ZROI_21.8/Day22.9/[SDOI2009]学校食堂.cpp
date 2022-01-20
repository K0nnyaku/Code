#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

int MB = 1 << 21;
struct FastIO {
    char Buf[MB + 100], *p, *e;
    int GetChar() {
        if(p == e) p = Buf, e = Buf + fread(Buf, 1, MB, stdin);
        return p == e ? EOF : *p++;
    } 
    template<typename T>
    FastIO& operator>>(T& x) {
        int c, l;
        for(c = 0; !isdigit(c); c = GetChar()) l = c;
        for(x = 0; isdigit(c); c = GetChar()) x = x * 10 + c - '0';
        if(l == '-') x = -x;
        return *this;
    }
} IN;

namespace main {
    const int MAXN = 1e3 + 10;
    const int MAXP = (1 << 9) + 1;

    struct { int tm, eat; } S[MAXN];
    int F[MAXN][MAXP][20];
    int n;

    void Solve() {
        IO >> n;
        IOR(i, 1, n+1) 
            IO >> S[i].eat >> S[i].tm;
        
        IOR(i, 1, n+1) IOR(v, 0, 1 << 8) IOR(k, 0, 15){
            if()
        } 

    }
}

int main() { /**/

    return 0;
} /**/