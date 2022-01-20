#include<cstdio>
#include<queue>
#define LL long long
using namespace std;
const int N = 2e5 + 55;
int n, m, u, v;
LL Fir, Ans, Flo[N], Deg[N];
struct Second{
    LL Sum, Size;
}Sec;

int cnt, Last[N];
struct Edge{
    int to, nt;
}E[N];
void Add(int u, int v) {
    E[++cnt].to = v;
    E[cnt].nt = Last[u];
    Last[u] = cnt;
}

int main() {
    scanf("%d%d",&n,&m);
    if (m == 0) {
        Ans = (1ll) * n * (n - 1) * (n - 2);
    }
    else {
        for (int i = 1; i <= m; i++) {
            scanf("%d%d",&u,&v);
            Add(u, v); Deg[v]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (Deg[i] == 0) {
                q.push(i); Fir++;
                Flo[i] = 1;
            }
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (Flo[u] == 2)    Sec.Sum++;
            else if (Flo[u] > 2)    break;
            for (int i = Last[u]; i; i = E[i].nt) {
                int v = E[i].to;
                Deg[v]--; Flo[v] = Flo[u] + 1;
                if (Flo[u] == 2)    Sec.Size++;
                if (Deg[v] == 0)    q.push(v);
            }
        }

        Ans += Sec.Sum * (Sec.Sum - 1) + Sec.Size;
    }
    
    printf("%lld",Ans);
    return 0;
}