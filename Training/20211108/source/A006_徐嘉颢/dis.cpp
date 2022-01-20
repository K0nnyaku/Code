#include <bits/stdc++.h>
#define int long long
#define Efor(xx, yy) for(int xx = Head[yy]; xx; xx = Next[xx])
#define Lfor(xx, yy, zz, xyz) for(int xx = yy; xx <= zz; xx += xyz)
#define Rfor(xx, yy, zz, xyz) for(int xx = yy; xx >= zz; xx -= xyz)
using namespace std;
const int kN = 1e6 + 16, kDot = 1e5 + 15;
int n, m;
int tot, Head[kN], Ver[kN], Next[kN];
bool Edge[55][55], Vis[kN];
int On[kDot][42], Un[kDot][42];
void Ins(int x, int y) {
    Ver[++tot] = y;
    Next[tot] = Head[x];
    Head[x] = tot;
}
int BFS(int St, int k) {
    queue <pair<int, int> > Q;
    int cnt = 0;
    Lfor (i, 1, n, 1) Vis[i] = 0;
    Vis[St] = 1, Q.push(make_pair(0, St));
    while (Q.size()) {
        int x = Q.front().second, dis = Q.front().first; Q.pop(); 
        Efor (e, x) {
            int y = Ver[e];
            if (Vis[y] or Edge[x][y]) continue;
            Vis[y] = 1;
            if (y > St and dis + 1 <= k) cnt++;
            if (dis + 1 < k) {
                Q.push(make_pair(dis + 1, y));
            }
        }
    }
    return cnt;
}
void DFS(int x, int Fa, int Limit) {
    Efor (e, x) {
        int y = Ver[e];
        if (y == Fa) continue;
        DFS(y, x, Limit);
        Lfor (i, 1, Limit, 1) Un[x][i] += Un[y][i - 1];
    }
    // Lfor (i, 0, Limit, 1) {
        // printf("Un[%lld][%lld] : %lld\n", x, i, Un[x][i]);
    // }
}
void Solve(int x, int Fa, int Limit) {
    Efor (e, x) {
        int y = Ver[e];
        if (y == Fa) continue;
        if (!(y & 1))
           {
                Lfor (i, 2, Limit, 1) {
                    On[y][i] = Un[x][i - 1] - Un[y][i - 2];
                    // printf("On[%lld][%lld] : %lld\n", y, i, On[y][i]);
                }
           }
        else
        {
            Lfor (i, 3, Limit, 1)
                {
                    On[y][i] = Un[x][i - 1] - Un[y][i - 2];
                    // printf("On[%lld][%lld] : %lld\n", y, i, On[y][i]);
                }
        }
        Solve(y, x, Limit);
    }
}
signed main() {
#ifdef FIO
    freopen("D:/Code/In.in", "r", stdin);
    freopen("D:/Code/Out.out", "w", stdout);
#else
    freopen("dis.in", "r", stdin);
    freopen("dis.out", "w", stdout);
#endif
    cin >> n >> m;
    Lfor (i, 2, n, 1) Ins(i, i / 2), Ins(i / 2, i);
    if (n <= 50) {
        while (m --> 0) {
            char Opt;
            int x;
            cin >> Opt >> x;
            if (Opt == '-') Edge[x][x / 2] = Edge[x / 2][x] = 1;
            else {
                int sum = 0;
                Lfor (i, 1, n, 1) {
                    sum += BFS(i, x);
                }
                cout << sum << "\n";
            }
        }
    } else {
        while (m --> 0) {
            char Opt;
            int x;
            cin >> Opt >> x;
            Lfor (i, 1, n, 1) {
                Un[i][0] = 1;
                Lfor (k, 1, x, 1) On[i][k] = Un[i][k] = 0;
            }
            DFS(1, 0, x), Solve(1, 0, x);
            int sum = 0;
            Lfor (i, 1, n, 1) {
                // cout << "i : " << i << "\n";
                Lfor (k, 1, x, 1) {
                    sum += On[i][k] + Un[i][k];
                    
                // cout << "\t" << k << " : " << On[i][k] << " " << Un[i][k] << " \n";
                }
                    
            }
            cout << sum << "\n";
        }
    }
    return 0;
}