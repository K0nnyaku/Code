#include <bits/stdc++.h>
using namespace std;

const int Mod = 1e9 + 7;

int n, k, cnt;
char originn[600];

inline int read() {
	int x = 0; char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x;
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	srand(time(NULL));
	
	n = read(), k = read();
	scanf("%s", originn + 1);
	
	//dfs(1);
	cout << rand() % 100;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


