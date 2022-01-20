#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <stdio.h>
using namespace std;

const int N = 1e5 + 9;
int T, n, g, cnt;
int a[N], ans[N];
bool vis[N];
int main(){
//	freopen("palin.in", "r", stdin);
//	freopen("palin.out", "w", stdout);
	cin >> T;
	while(T--){
		scanf("%d", &n);
		for(register int i = 1;i <= 2 * n;i++){
			cin >> a[i];
		}
		for(register int i = 1;i <= 2 * n;i++){
			if(a[i] == a[2 * n - i + 1]){
				g++;
			}
			vis[i] = 1;
			for(register int j = 1;j <= 2 * n;j++){
				if(a[i] == a[j] && vis[j] == 0){
					cnt++;
					ans[cnt] = j - i;
				}
			}
		}
		if(g == 2 * n){
			int h = 2 * n;
			while(h--){
				cout << "L";
			}
			return 0;
		}
		
		else {
			cout << -1;
			return 0;
		}	
	}
//	fclose(stdin);
//	fclose(stdout);
	
	return 0;
}
