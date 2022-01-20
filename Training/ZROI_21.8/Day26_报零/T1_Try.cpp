#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define T(x) E[x].to
#define V(x) E[x].val

const int MAXN = 16 + 10;
const int MAXK = 4 + 10;

struct Node { 
    int x, y, dep;
    Node(int _x = 0, int _y = 0, int _dep = 0) {
        x = _x; y = _y; dep = _dep;
    } 
};
int n, m, k;
int Mp[MAXN][MAXN], Idx[MAXK], Wayx[4] = {0, 0, -1, 1}, Wayy[4] = {1, -1, 0, 0};

namespace First {

bool Vis[MAXN][MAXN];

void Solve();
}

namespace Second {
    Node S[10], T[10];
    int Pm;
    
    void Solve();

    bool CC(int mp, int, int);
    bool Check(int mp, int a, int b, int x, int y);
    void Wk(int, int, int);
}

int Turn(int x, int y);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &k);
    IOR(i, 1, n+1) {
        getchar();
        IOR(v, 1, m+1) {
            char ch = getchar(); 
            if(ch == 'S') Mp[i][v] = 1;
            else 
            if(ch == '.') Mp[i][v] = 2;
            else 
            if(ch == 'T') Mp[i][v] = 3;
        }
    }
    if(k == 1) 
        First::Solve();
    else
    if(k == 2) 
        Second::Solve();

	return 0;
} /**/

void Second::Solve() {

    int idxs = 0, idxt = 0;
    IOR(i, 1, n+1) IOR(v, 1, m+1) 
        if(Mp[i][v] == 1) S[idxs++] = { i, v }; 
        else if(Mp[i][v] == 3) T[idxt++] = { i, v };

    IOR(i, 0, 1 << (n * m + 1)) 
        IOR(v, 0, 2) IOR(k, 0, 2) 
            if(v != k) {
                if(Check(i, v, 0, k, 1)) {
                    Wk(i, v, 0);
                    i ^= 1;
                    Wk(i, k, 1);
                    return ;
                }
                else 
                if(Check(i, v, 1, k, 0)) {
                    Wk(i, v, 1);
                    i ^= 1;
                    Wk(i, k, 0);
                    return ;
                }
//                printf("%d\n", i);
            }
}

bool Second::Check(int mp, int a, int b, int x, int y) {
    if(!CC(mp, a, b)) return 0;
    mp ^= mp;
    if(CC(mp, x, y)) return 1;
    return 0;
}

bool Second::CC(int x, int y, int z) {
    Node s = S[y], t = T[z], Ans[MAXN];
    bool Vis[MAXN][MAXN];
    int idx = 0, adep;
    memset(Vis, 0, sizeof Vis);
    queue<Node> Q; Q.push(Node(s.x, s.y, 0));

    while(!Q.empty()) {
        int x = Q.front().x, y = Q.front().y, dep = Q.front().dep;
        adep = dep+1;
        if(x == t.x && y == t.y) return true;

        Q.pop();
        Ans[idx++] = { x, y, dep }; Vis[x][y] = 1;

        IOR(i, 0, 4) {
            int tx = x + Wayx[i], ty = y + Wayy[i];
            if(!Vis[tx][ty] && (i >> (Turn(tx, ty) - 1)) & 1 && tx <= n && ty <= m && ty > 0 && tx > 0)
                Q.push(Node(tx, ty, dep+1));
        }
    }

    return false;
}

void Second::Wk(int x, int y, int z) {
    Node s = S[y], t = T[z], Ans[MAXN];
    bool Vis[MAXN][MAXN];
    int idx = 0, adep;
    memset(Vis, 0, sizeof Vis);
    queue<Node> Q; Q.push(Node(s.x, s.y, 0));

    while(!Q.empty()) {
        int x = Q.front().x, y = Q.front().y, dep = Q.front().dep;
        adep = dep+1;
        if(x == t.x && y == t.y) break;

        Q.pop();
        Ans[idx++] = { x, y, dep }; Vis[x][y] = 1;

        IOR(i, 0, 4) {
            int tx = x + Wayx[i], ty = y + Wayy[i];
            if(!Vis[tx][ty] && (i >> (Turn(tx, ty)-1)) & 1 && tx <= n && ty <= m && tx > 0 && ty > 0)
                Q.push(Node(tx, ty, dep+1));
        }
    }

    int tdep = 0;
    printf("%d\n", adep);
    printf("%d %d\n", s.x, s.y);
    IOR(i, 0, idx) {
        if(Ans[i].dep > tdep) {
            printf("%d %d\n", Ans[i].x, Ans[i].y);
            tdep = Ans[i].dep;
        }
    }
    printf("%d %d\n", t.x, t.y);
}

int Turn(int x, int y) {
    return (x - 1) * m + y;
}

void First::Solve() {
    Node s, t, Ans[MAXN];
    int idx = 0, adep;
    memset(Vis, 0, sizeof Vis);
    IOR(i, 1, n+1) IOR(v, 1, m+1) 
        if(Mp[i][v] == 1) s = { i, v };
        else 
        if(Mp[i][v] == 3) t = { i, v };
    queue<Node> Q; Q.push(Node(s.x, s.y, 0));
    while(!Q.empty()) {
        int x = Q.front().x, y = Q.front().y, dep = Q.front().dep;
        adep = dep+1;
        if(x == t.x && y == t.y) break;

        Q.pop();
        Ans[idx++] = { x, y, dep }; Vis[x][y] = 1;

        IOR(i, 0, 4) {
            int tx = x + Wayx[i], ty = y + Wayy[i];
            if(!Vis[tx][ty] && Mp[tx][ty] && tx <= n && ty <= m && tx > 0 && ty > 0)
                Q.push(Node(tx, ty, dep+1));

        }
    }

    int tdep = 0;
    printf("%d\n", adep);
    printf("%d %d\n", s.x, s.y);
    IOR(i, 0, idx) {
        if(Ans[i].dep > tdep) {
            printf("%d %d\n", Ans[i].x, Ans[i].y);
            tdep = Ans[i].dep;
        }
    }
    printf("%d %d", t.x, t.y);
}