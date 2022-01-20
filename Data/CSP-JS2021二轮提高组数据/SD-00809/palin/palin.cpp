#include <bits/stdc++.h>
using namespace std;

int t, n, a[1001];
bool usedd[1001];
vector<int> b;

inline int read() {
	int x = 0; char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x;
}

string dfs(string ope, int l, int r) {
	if (r - l + 1 == n) {
		int noww = b.size() - 1;
		while (noww >= 0) {
			if (a[l] == b[noww]) ope += "L", noww--, l++;
			else if (a[r] == b[noww]) ope += "R", noww--, r--;
			else return "-1";
		}
		return ope;
	} else {
		string ans = "-1";
		if (!usedd[a[l]]) {
			usedd[a[l]] = 1;
			b.emplace_back(a[l]);
			ans = dfs(ope + "L", l + 1, r);
			b.pop_back();
			usedd[a[l]] = 0;
		}
		if (!usedd[a[r]] && ans == "-1") {
			usedd[a[r]] = 1;
			b.emplace_back(a[r]);
			ans = dfs(ope + "R", l, r - 1);
			b.pop_back();
			usedd[a[r]] = 0;
		}
		return ans;
	}
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out" , "w", stdout);
	
	t = read();
	while (t--) {
		n = read();
		for (int i = 1; i <= 2*n; i++) {
			a[i] = read();
		}
		
		cout << dfs("", 1, 2*n) << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


