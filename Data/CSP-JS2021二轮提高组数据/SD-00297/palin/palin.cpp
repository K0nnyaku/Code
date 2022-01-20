#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}

const int MAXN = 25;
int s[MAXN];
vector<int> b;
vector<char> ans, curans;
bool sucflag;
inline void chk() {
	int rlim = b.size();
	for (int i = 0; i < rlim / 2; ++i) {
		if (b[i] != b[rlim - i - 1])
			return;
			// 不是回文串，走。 
	}
	
	/*
	for (auto i : curans)
		cerr << i << " ";
	for (auto i : b)
		cerr << i << " ";
	cerr << endl;
	*/
	
	if (!sucflag) {
		sucflag = 1;
		ans = curans; 
		return;
	} // 如果第一次，无论如何都接受 
	for (int i = 0; i < rlim; ++i) {
		if (ans[i] < curans[i])
			return;
//		cerr << ans[i] << curans[i] << " ";
	} // 不是第一次，和上次比较字典序 
	ans = curans;
	// 能跑到这里证明字典序更小 
}
int vis[MAXN], n;
void dfs(int lcur, int rcur, int cnt) {
	if (lcur > rcur) {
		chk();
		return;
	}
	if (sucflag && curans.back() > ans[curans.size() - 1])
		return;
	if (cnt <= n && b.size() && vis[b.back()] == 2)
		return;
	b.push_back(s[lcur]);
	curans.push_back('L');
	
//	if (cnt > n || !vis[s[lcur]]) {
		++vis[s[lcur]];
		dfs(lcur + 1, rcur, cnt + 1);
		--vis[s[lcur]];
//	}
	
	curans.pop_back();
	b.pop_back();
	
	
	b.push_back(s[rcur]);
	curans.push_back('R');
	
//	if (cnt > n || !vis[s[rcur]]) {
		++vis[s[rcur]];
		dfs(lcur, rcur - 1, cnt + 1);
		--vis[s[rcur]];
//	}
	
	curans.pop_back();
	b.pop_back();
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T = read();
	while (T--) {
		memset(s, 0, sizeof s);
		memset(vis, 0, sizeof vis);
		b.clear(); ans.clear(); curans.clear();
		sucflag = 0;
		n = read();
		for (int i = 1; i <= n * 2; ++i) s[i] = read();
		dfs(1, 2 * n, 0);
		if (!sucflag)
			printf("-1");
		else
			for (int i = 0; i < ans.size(); ++i)
				printf("%c", ans[i]);
		printf("\n");
	}
	return 0;
}
