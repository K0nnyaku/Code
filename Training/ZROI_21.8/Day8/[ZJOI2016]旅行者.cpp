#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN = 1e4 + 10;
const int MAXM = 1e4 + 10;
const int MAXQ = 1e4 + 10;
const int INF = 0x3f3f3f3f;

struct Question {
    int a, b, x, y, ans;
    Question(int _st = 0, int _ed = 0, int _ans = INF) { st = _st; ed = _ed; ans = _ans; }
    friend bool operator<(Question x, Question y) { return x.st < y.st; }
}Q[MAXQ];

int E[MAXN][MAXN], D[MAXN];
int n, m, q;

void Dijkstra(int st, int a, int b, int x, int y);
void Solve(int a, int b, int x, int y);

int main() { /**/
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j < m; j++) scanf("%d", &E[i][j]), E[j][i] = E[i][j];
    for(int i = 1; i < n; i++)
        for(int j = 1; j <= m; j++) scanf("%d", &E[i][j]), E[j][i] = E[i][j];
    scanf("%d", &q);
    for(int i = 0; i < q; i++) scanf("%d%d", Q[i].st, Q[i].ed);

    Solve(1, 1, n, m);

    return 0;
} /**/

void Solve(int a, int b, int x, int y) {
    if(a == x || b == y) return;
    memset(D, 0, sizeof D);

    if(x - a >= y - b) {
        int mid = (x - a) / 2;
        for(int i = 1; i <= m; i++) Dijkstra((i - 1) * n + mid, a, b, x, y);
        for(int i = 0; i < q; i++) Q[i].ans = min(Q[i].ans, D[Q[i].st]+D[Q[i].ed]);

        for(int i = 0; i < q; i++) 
            if(Q[i].ans == INF) {
                if(Q[i].st < mid) 
                    Solve(a, b, mid, y);
                else 
                    Solve(mid, b, x, y);
            }
    }
    else {
        int mid = (y - b) / 2;
        for(int i = 1; i <= n; i++) Dijkstra((mid-1)*n + i, a, b, x, y);
        for(int i = 0; i < q; i++) Q[i].ans = min(Q[i].ans, D[Q[i].st] + D[Q[i].ed]);

        for(int i = 0; i < q; i++) {
            if(Q[i].ans == INF) {
                if(Q[i].st < mid) 
                    Solve()
            }
        }
    }
    
}

