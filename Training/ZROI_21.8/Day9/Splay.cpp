#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 2e5 + 10;
const int INF = 0x3f3f3f3f;
//#define LOCAL

namespace SplayTree {
    int Ch[MAXN][2];
    int Size[MAXN], Val[MAXN], Pre[MAXN], Cnt[MAXN];
    int root, index;
    void Up(int x);
    void Rotate(int x);
    void Splay(int x, int goal = 0);
    void Find(int x);
    void Insert(int x);
    void Remove(int x);
    bool Way(int x);
    int Kth(int x);
    int Rank(int x);
    int QyPre(int x);
    int QySucc(int x);
    
    void Init();
} 

int n;

int main() {
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif
//    SplayTree::Init();
    SplayTree::Insert(INF);
    SplayTree::Insert(-INF);    
    scanf("%d", &n);
    while(n--) {
        int opt, x;
        scanf("%d%d", &opt, &x);
        switch(opt) {
            case 1: SplayTree::Insert(x); break;
            case 2: SplayTree::Remove(x); break;
            case 3: printf("%d\n", SplayTree::Rank(x)); break;
            case 4: printf("%d\n", SplayTree::Val[SplayTree::Kth(x+1)]); break;
            case 5: printf("%d\n", SplayTree::Val[SplayTree::QyPre(x)]); break;
            case 6: printf("%d\n", SplayTree::Val[SplayTree::QySucc(x)]); break;
        }
    }

    return 0;
}

void SplayTree::Up(int x) { Size[x] = Size[Ch[x][0]] + Size[Ch[x][1]] + Cnt[x]; }

void SplayTree::Rotate(int x) {
    int pre = Pre[x], ppre = Pre[pre], way = Way(x), 
        bro = Ch[x][way ^ 1];
    Ch[pre][way] = bro; Pre[bro] = pre;
    Ch[ppre][Way(pre)] = x; Pre[x] = ppre;
    Ch[x][way ^ 1] = pre; Pre[pre] = x;
    Up(pre); Up(x);
}

void SplayTree::Splay(int x, int goal) {
    while(Pre[x] != goal) {
        int y = Pre[x], z = Pre[y];
        if(z != goal) 
            if(Way(x) == Way(y)) Rotate(y);
            else Rotate(x);
        Rotate(x);
    }
    if(!goal) root = x;
}

void SplayTree::Find(int x) {
    int cur = root;
    while(Ch[cur][x > Val[cur]] && x != Val[cur]) 
        cur = Ch[cur][x > Val[cur]];
    Splay(cur);
}

void SplayTree::Insert(int x) {
    int cur = root, p = 0;
    while(cur && x != Val[cur])
        p = cur, cur = Ch[cur][x > Val[cur]];
    
    if(cur) Cnt[cur]++;
    else {
        cur = ++index;
        if(p) Ch[p][x > Val[p]] = cur;
        Ch[cur][0] = Ch[cur][1] = 0;
        Val[cur] = x; Pre[cur] = p;
        Cnt[cur] = Size[cur] = 1;
    }

    Splay(cur);
}

int SplayTree::Kth(int x) {
    int cur = root;
    while(1) {
        if(Ch[cur][0] && x <= Size[Ch[cur][0]]) 
            cur = Ch[cur][0];
        else 
        if(x > Size[Ch[cur][0]] + Cnt[cur])    
            x -= Size[Ch[cur][0]] + Cnt[cur],
            cur = Ch[cur][1];
        else {
            Splay(cur);
            return cur;
        }
    }
}

int SplayTree::Rank(int x) {
    Find(x);
    return Size[Ch[root][0]];
}

int SplayTree::QyPre(int x) {
    Find(x);
    if(Val[root] < x) return root;
    int cur = Ch[root][0];
    while(Ch[cur][1]) cur = Ch[cur][1];
    Splay(cur);
    return cur;
}

int SplayTree::QySucc(int x) {
    Find(x);
    if(Val[root] > x) return root;
    int cur = Ch[root][1];
    while(Ch[cur][0]) cur = Ch[cur][0];
    Splay(cur);
    return cur;
}

void SplayTree::Remove(int x) {
    int last = QyPre(x), nxt = QySucc(x);
    Splay(last); Splay(nxt, last);
    int del = Ch[nxt][0];
    if(Cnt[del] > 1) Cnt[del]--, Splay(del);
    else Ch[nxt][0] = 0;
    Up(nxt); Up(root);
}

bool SplayTree::Way(int x) {
    return x == Ch[Pre[x]][1];
}