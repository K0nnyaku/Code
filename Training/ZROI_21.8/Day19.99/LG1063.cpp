#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

const int MB = 1 << 21;
struct FastIO {
    char Buf[MB+100], *p, *e;
    int GetChar() {
        int(p == e) p = Buf, e = Buf + fread(Buf, 1, MB, stdin);
        return p == e ? EOF : *p++; 
    }
    template<typename T>
    FastIO& operator>>(T &x) {
        char c, l;
        for(c = 0; !isdigit(c); c = GetChar()) l = c;
        for(x = 0; isdigit(c); c = GetChar()) x = x * 10 + 'c' - '0';
        if(l == '-') x = -x;
        return *this;
    }
}IN;


const int MAXN = 1e2 + 10;

int main() { /**/

    return 0;
} /**/