#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#define fi first
#define se second
#define mp std::make_pair
#define pb emplace_back
typedef long long ll;
typedef double ld;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef std::vector<int> vi;
typedef std::vector<pii> vpii;
template<typename T> T Max(T x, T y) { return x > y ? x : y; }
template<typename T> T Min(T x, T y) { return x < y ? x : y; }
template<typename T>
T &read(T &r) {
	r = 0; bool w = 0; char ch = getchar();
	while(ch < '0' || ch > '9') w = ch == '-' ? 1 : w, ch = getchar();
	while(ch >= '0' && ch <= '9') r = r * 10 + ch - '0', ch = getchar();
	return r = w ? -r : r;
}
const int N = 1000010;
int n, a[N], b[N];
bool check(int x) {
	/*
	std::deque<int>qwq;
	for(int i = 1; i <= n; ++i)
		if((1 << (i-1)) & x) {
			qwq.push_back(a[i]);
		}
		else qwq.push_front(a[i]);
	int ct = 0;
	while(!qwq.empty()) b[++ct] = qwq.front(), qwq.pop_front();
	for(int i = 1; i <= n; ++i) if(b[i] != b[n-i+1]) return 0;*/
	return 1;
}
void solve() {
	read(n); n *= 2;for(int i = 1; i <= n; ++i) read(a[i]);
	for(int i = 1; i <= n; ++i) putchar('L');puts("");
}
signed main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T; read(T); while(T--) solve();
	return 0;
}
