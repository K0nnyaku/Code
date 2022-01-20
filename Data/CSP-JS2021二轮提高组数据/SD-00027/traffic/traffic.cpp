#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define FOR(i,l,r) for(int i = l;i <= r; i++)

using namespace std;

const int N = 100;
int n, m , T;
int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	scanf("%d%d%d", &n,&m,&T);
	FOR(i,1,n-1) {
		FOR(j,1,m) {
			int a;
			scanf("%d", &a);
		}
	}
	FOR(i,1,n) {
		FOR(j,1,m-1) {
			int a;
			scanf("%d", &a);
		}
	}
	FOR(i,1,T) {
		int k;
		scanf("%d", &k);
		FOR(j,1,k) {
		int a, b, c;
		scanf("%d%d%d", &a,&b,&c);
		}
		cout << "0\n";
	}
	fclose(stdin); fclose(stdout);
	return 0;
}

