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

Node Pre[MAXN][MAXN];

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

    return 0;
} /**/

void First::Solve() {
    Node s, t, Ans[MAXN];
    int idx = 0;
    memset(Vis, 0, sizeof Vis);
    IOR(i, 1, n+1) IOR(v, 1, m+1) 
        if(Mp[i][v] == 1) s = { i, v };
        else
        if(Mp[i][v] == 3) t = { i, v };
    
    queue<Node> Q; Q.push(Node(s.x, s.y, 0));
    while(!Q.empty()) {
        int x = Q.front().x, y = Q.front().y, dep = Q.front().dep;

        printf("!!%d %d %d %d!!\n", s.x, s.y, x, y);

        if(x == t.x && y == t.y) break;

        Q.pop();
        Ans[idx++] = { x, y, dep }; Vis[x][y] = 1;

        printf("??%d %d %d %d??\n", s.x, s.y, x, y);
        IOR(i, 0, 4) {
            int tx = x + Wayx[i], ty = y + Wayy[i];
            if(!Vis[tx][ty] && Mp[tx][ty] && tx <= n && ty <= m && tx > 0 && ty > 0) {
                Q.push(Node(tx, ty, dep+1));
                Pre[tx][ty] = Node(x, y);
            }
        }
    }

    Pre[s.x][s.y].x = Pre[s.x][s.y].y = 0;

    stack<Node> sk;
    int x = t.x, y = t.y;
    while(Pre[Pre[x][y].x][Pre[x][y].y].x && Pre[Pre[x][y].x][Pre[x][y].y].y) {
        sk.push(Node(Pre[x][y]));
        x = Pre[x][y].x, y = Pre[x][y].y;
    }

    printf("%llu\n", sk.size() + 2);
    while(!sk.empty()) {
        printf("%d %d\n", sk.top().x, sk.top().y);
        sk.pop();
    }
    printf("%d %d", t.x, t.y);
}
