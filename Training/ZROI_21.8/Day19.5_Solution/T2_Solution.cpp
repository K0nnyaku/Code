#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);

const int OutputBufferSize = 10000000;
namespace input {
    #define BUF_SIZE 100000 
    #define OUT_SIZE 100000 
    #define ll long long 
    bool IOerror = 0; 
    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE; 
        if (p1 == pend) { 
            p1 = buf; pend = buf + fread(buf, 1, BUF_SIZE, stdin); 
            if (pend == p1) { IOerror = 1; return -1; } 
        } 
        return *p1++; 
    } 
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    } 
    inline void read(char &ch) { 
        ch = nc();
        while (blank(ch)) ch = nc();
    }
    inline void read(int &x) {
        char ch = nc(); x = 0; 
        for (; blank(ch); ch = nc()); 
        if (IOerror) return; 
        for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
    } 
    #undef ll 
    #undef OUT_SIZE 
    #undef BUF_SIZE 
}; 

namespace output {
    char buffer[OutputBufferSize];
    char *s = buffer;
    inline void flush() {
        assert(stdout != NULL);
        fwrite(buffer, 1, s - buffer, stdout);
        s = buffer;
        fflush(stdout);
    }
    inline void print(const char ch) {
        if (s - buffer > OutputBufferSize - 2) flush();
        *s++ = ch;
    }
    inline void print(char* str) {
        while (*str != 0) print(char(*str++));
    }
    inline void print(int x) {
        char buf[25] = {0}, *p = buf;
        if (x == 0) print('0');
        while (x) *(++p) = x % 10, x /= 10;
        while (p != buf) print(char(*(p--) + '0'));
    }
}

const int MAXN = 2005;
const int INF = 0x3f3f3f3f;

int Wayy[4] = { -1, 1, 0, 0 }, Wayx[4] = {0, 0, -1, 1}, Ans[MAXN][MAXN];
int n, m;
char Mp[MAXN][MAXN];
bool Vis[MAXN][MAXN][2];

int Bfs(int x, int y);

int main() {
#ifdef LOCAL 
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif

    input::read(n), input::read(m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            input::read(Mp[i][j]);
        }
    }

    

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (Ans[i][j] == -1) {
                output::print('#');
            } else if (Ans[i][j] == INF) {
                output::print('X');
            } else {
                output::print(Ans[i][j]);
            }
            output::print(" \n"[j == m]);
        }
    }
    output::flush(); 
    return 0;
}
