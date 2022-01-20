#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e6 + 10;
const int INF = 0x3f3f3f3f;

namespace Splay {
    int Ch[MAXN][2], Mark[MAXN], Size[MAXN], Pre[MAXN], Cnt[MAXN], Val[MAXN];
    int index, root;

    void Up(int x);
    void Rotate(int x);
    void Splay(int x, int goal = 0);
    void Sp(int x);
    void Insert(int x);
    int Kth(int x);
    bool Way(int x);

    void Solve(int x, int y);
    void Output(int now);
}

int n, m;
int main() {

    scanf("%d", &n);
    for(int i = 1; i <= n+2; i++) 
        Splay::Insert(i);
    scanf("%d", &m);
    while(m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        Splay::Solve(x, y);
    }
    Splay::Output(Splay::root);

    return 0;
}


void Splay::Rotate(int x) {
    int pre = Pre[x], ppre = Pre[pre], way = Way(x),
    bro = Ch[x][way ^ 1];

    Ch[pre][way] = bro; Pre[bro] = pre;
    Ch[ppre][Way(pre)] = x; Pre[x] = ppre;
    Ch[x][way^1] = pre; Pre[pre] = x;
    Up(pre); Up(x);
}

void Splay::Splay(int x, int goal) {
    while(Pre[x] != goal) {
        int pre = Pre[x], ppre = Pre[pre];
        if(ppre != goal) 
            if(Way(x) == Way(pre)) Rotate(pre);
            else Rotate(x);
        Rotate(x);
    } 
    if(!goal) root = x;
}

void Splay::Insert(int x) {
    int cur = root, p = 0;
    while(cur && x != Val[cur]) 
        p = cur, cur = Ch[cur][x > Val[cur]];

    if(cur) Cnt[cur]++;
    else {
        cur = ++index;
        if(p) Ch[p][x > Val[p]] = cur;
        Ch[cur][0] = Ch[cur][1] = 0; 
        Cnt[cur] = Size[cur] = 1;
        Val[cur] = x; Pre[cur] = p;
    } 

    Splay(cur);
}

int Splay::Kth(int x) {
    int cur = root;
    while(1) {
        Sp(cur);
        if(Ch[cur][0] && x < Size[Ch[cur][0]])
            cur = Ch[cur][0];
        else 
        if(x > Ch[cur][0] + Cnt[cur]) 
            x -= Ch[cur][0] + Cnt[cur],
            cur = Ch[cur][1];
        else {
            Splay(cur);
            return cur;
        } 
    }
}

void Splay::Up(int x) { Size[x] = Size[Ch[x][0]] + Size[Ch[x][1]] + Cnt[x]; }
void Splay::Sp(int x) { 
    if(Mark[x]) {
        Mark[Ch[x][0]] ^= 1; Mark[Ch[x][1]] ^= 1;
        Mark[x] = 0; swap(Ch[x][0], Ch[x][1]);
    }
}
bool Splay::Way(int x) { return x == Ch[Pre[x]][1]; }

void Splay::Solve(int x, int y) {
    x = Kth(x); y = Kth(y+2);
    Splay(x); Splay(y, x);
    Mark[Ch[Ch[root][1]][0]] ^= 1;
}

void Splay::Output(int now) {
    Sp(now);
    if(Ch[now][0]) Output(Ch[now][0]);
    if(Val[now] > 1 && Val[now] < n + 2) printf("%d ", Val[now] - 1);
    if(Ch[now][1]) Output(Ch[now][1]);
}