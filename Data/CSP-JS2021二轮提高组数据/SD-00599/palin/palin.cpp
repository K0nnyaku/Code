#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 +5;
int n, t, f, a[2 * N], vis[N], b[2 * N];
string ans;
deque <int> q;
inline void dfs(int now, string res){
	if (f) return ;
	if (now == 2 * n + 1){
		cout << res << endl;
		f = 1;
		return ;
	}
	int x = q.front(), y = q.back();
	if (now <= n){ 
		if (! vis[x]){
			vis[x] = 1;
			b[now] = x;
			q.pop_front();
			dfs(now + 1, res + "L");
			vis[x] = 0;
			q.push_front(x);
		} 	
		if (! vis[y]){
			vis[y] = 1;
			b[now] = y;
			q.pop_back();
			dfs(now + 1, res + "R");
			vis[y] = 0;
			q.push_back(y);
		}
	}
	else {
		if (x == b[2 * n + 1 - now]){
			b[now] = x;
			q.pop_front();
			dfs(now + 1, res + "L");
			q.push_front(x);
		}
		if (y == b[2 * n + 1 - now]){
			b[now] = y;
			q.pop_back();
			dfs(now + 1, res + "R");
			q.push_back(y);
		}
	}
}
int main(){
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &t);
	while (t --){
		q.clear();
		memset(b, 0, sizeof b);
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n; ++i){
			scanf("%d", &a[i]);
			q.push_back(a[i]);
		}
		
		ans = "", f = 0;
		dfs(1, ans);
		if (!f) cout << -1 << endl;
	}	
	return 0;
}
