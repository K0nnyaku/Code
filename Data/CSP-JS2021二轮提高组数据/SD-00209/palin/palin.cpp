#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
const int MAXN = 5e5 + 10;
int T, n, a[MAXN << 1];
bool tag;
std::vector<int> now;
template <class I> inline void read(I &x){
	x = 0; int f = 1; char ch;
	do { ch = getchar(); if(ch == '-') f = -1; } while(ch < '0' || ch > '9');
	do { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); } while(ch >= '0' && ch <= '9');
	x *= f; return; 
}
void DFS(int u){
	if(tag == 1) return;
	if(u == 2 * n + 1){
		int l = 1, r = 2 * n;
		std::vector<int> p;
		for(int i = 0; i < 2 * n; ++i){
			if(now[i] == 0) p.push_back(a[l]), ++l;
			if(now[i] == 1) p.push_back(a[r]), --r;
		}
		tag = 1;
		for(int i = 1; i <= n; ++i){
			if(p[i - 1] != p[2 * n - i]){
				tag = 0;
				break;
			}
		}
		if(tag){
			for(int i = 0; i < 2 * n; ++i){
				if(now[i] == 0) putchar('L');
				else putchar('R');
			}
			puts("");
		}
		return;
	}
	now.push_back(0);
	DFS(u + 1);
	now.pop_back();
	now.push_back(1);
	DFS(u + 1);
	now.pop_back();
	return;
}
void solve(void){
	tag = 0;
	read(n);
	for(int i = 1; i <= 2 * n; ++i) read(a[i]);
	DFS(1);
	if(!tag) puts("-1");
	return;
}
int main(){
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	read(T);
	while(T--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
