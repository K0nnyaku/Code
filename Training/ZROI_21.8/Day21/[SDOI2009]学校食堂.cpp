#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

const int MB = 1 << 21;
struct FastIO {
    char Buf[MB + 100], *p, *e;
    int GetChar() {
        if(p == e) p = Buf, e = Buf + fread(Buf, 1, MB, stdin);
        return p == e ? EOF : *p++;
    }
    template<typename T>
    FastIO& operator>>(T& x) {
        char c, l;
        for(c = 0; !isdigit(x); x = GetChar()) l = c;
        for(x = 0; isdigit(x); x = GetChar()) x = x * 10 + c - '0';
        if(l == '-') x = -x;
        return *this;
    }
}IO;

int main() { /**/
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif

    return 0;
} /**/

