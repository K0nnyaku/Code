#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
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

int F(int x);

int main() { /**/
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif
    IOR(i , 1, 50) 
        if(F(i) == i) printf("%d\n", i);

    return 0;
} /**/

int F(int x) {
    if(x == 1 || x == 3) return x;
    if(!(x % 2)) return F(x / 2);
    if(!((x - 1) % 2)) return 2 * F((x - 1) / 2 + 1) - F((x - 1) / 4);
    return 3 * F((x - 3) / 2 + 1) - 2 * F((x - 3) / 4);
}