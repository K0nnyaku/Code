#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)

const int MB = 1 << 21;
struct FastIN {
    char Buf[MB+100], *p, *e;
    int Getchar() {
        if(p == e) p = Buf, e = Buf + fread(Buf, 1, MB, stdin);
        return p == e ? EOF : *p++;
    }
    template<typename T>
    FastIN& operator>>(T& x) {
        char 
    }
}