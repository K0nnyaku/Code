#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 2e6 + 7;

int t, n, a[MAXN];
bool fg;

int main(){
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d", &n);
		for(int i = 1; i <= 2 * n; i++){
			scanf("%d", &a[i]);
		}
		for(int i = 1; i <= 2 * n; i++){
			if(a[i] != a[2 * n - i + 1]){
				printf("-1\n");
				fg = 1;
				break;
			}
		}
		if(fg != 1){
			for(int i = 1; i <= 2 * n; i++){
				printf("L");
			}
			printf("\n");
		}
		memset(a, 0, sizeof(a));
	}
	return 0;
}
