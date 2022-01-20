#include <cstdio>
#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

const int N = 1005;
typedef long long ll;

inline void read(int &x) {
	register char ch = 0; register bool w = 0;
	for(x = 0; !std::isdigit(ch); w |= ch == '-', ch = getchar());
	for(; std::isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	(w) && (x = -x);
	return;
}

bool vis[N], nw[N];
int n, m, ind[N], outd[N], v, k;
std::vector<int> vals;
std::vector<std::pair<int, int>> edge[N];
std::map<std::pair<int, int>, bool> mp;

bool dfs(int now, int val) {
    if(nw[now]) return 0;
    vis[now] = 1;
    nw[now] = 1;
    if(now == n) {
        vals.push_back(val);
        nw[now] = 0;
        return 1;
    }
    for(auto v : edge[now]) {
        if(!dfs(v.first, val + v.second)) return 0;
    }
    nw[now] = 0;
    return 1;
}
int main() {
    freopen("I:\\Code\\Data\\In.in", "r", stdin);
    read(k), read(v);
    fclose(stdin);
    freopen("I:\\Code\\Data\\WA.out", "r", stdin);
    freopen("I:\\Code\\Data\\AC.out", "w", stdout);
    read(n), read(m);
    std::map<std::pair<int, int>, int> mp;
    for(int i = 1; i <= m; ++i) {
        int u, v, c; read(u), read(v), read(c);
        edge[u].push_back(std::make_pair(v, c));
        if(u == v) {
            printf("WA1\n"); return 0;
        }
        if(mp.find({u, v}) != mp.end()) {
            printf("WA1\n"); return 0;
        }
        mp[{u, v}] = 1;
        // edge[v].push_back(std::make_pair(u, c));
        ++ind[v], ++outd[u];
    }
    if(ind[1] || outd[n]) {printf("WA4\n"); return 0;}
    if(!dfs(1, 0)) {printf("WA2\n"); return 0;}
    std::sort(vals.begin(), vals.end());
    if((int)vals.size() != k) {printf("WA3\n"); return 0;}
    for(unsigned i = 0; i < vals.size(); ++i) {
        if(vals[i] != v + (int)i) {printf("WA3\n"); return 0;}
    }
    printf("AC\n");
    return 0;
}
