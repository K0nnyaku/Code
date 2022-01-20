#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 1000010;
//int fr[maxn];//firstsite
//int fd[maxn];//firstdeep
int a[maxn];
//bool boba = false;//back
//int bade = -1;//backdeep
int n;
//void dfs1(int deep, int l, int r) {
////	if(boba) {
////		if(deep > bade) {
////			return;
////		}
////		boba = false;
////		bade = -1;
////	}
//	if(deep == n) {
//		cout << "ok";
////		dfs2()
//	}
//	if(!fr[a[l]]) {
//		cout << l << '-';
////		boba = true;
////		bade = fd[a[l]];
//		fd[a[l]] = deep;
//		fr[a[l]] = l;
//		dfs1(deep + 1, l + 1, r);
//	}
////	if(boba) {
////		if(deep > bade) {
////			return;
////		}
////		boba = false;
////		bade = -1;
////	}
//	if(!fr[a[r]]) {
//		cout << r << '+';
////		boba = true;
////		bade = fd[a[r]];
//		fd[a[r]] = deep;
//		fr[a[r]] = r;
//		dfs1(deep + 1, l, r - 1);
//	}
//}
int main() {
//	freopen("palin.in", "r", stdin);
//	freopen("palin.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		cin >> n;
		memset(fr, 0, sizeof fr);
		memset(fd, 0, sizeof fd);
		for(int i = 1; i <= (n << 1); ++i) {
			cin >> a[i];
		}
		for(int i = 0; i < (1 << n); ++i) {
			string st = "";
			for(int j = 0; j < n; ++j) {
//				if(i & (1 << j)) {
////					st += 'L';
//					
//				} 
			}
		}
//		dfs1(0, 1, (n << 1));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
