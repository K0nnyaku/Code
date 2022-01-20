#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 5e5 + 5;

int re() {
	int x = 0, f = 1;
	char ch = getchar();

	while (ch < '0'||ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}

	while (ch <= '9'&&ch >= '0') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}

	return x * f;
}

int n, m1, m2;

int f1[N];
int f2[N];

struct bal {
	int l;
	int q;
};
bal a1[N], a2[N];

bool vis[N];

int cmp(bal a, bal b) {
	return a.l < b.l; 
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = re(); m1 = re(); m2 = re();
	
	for(int i = 1; i <= m1; ++i)
	a1[i].l = re(), a1[i].q = re();
	
	for(int i = 1; i <= m2; ++i)
	a2[i].l = re(), a2[i].q = re();
	
	int sta = 1;
	bool flag = 0;
	
	for(int i = 1; i <= n; i++) {
		
		if(flag) {
			f1[i] = f1[i - 1];
			continue;
		}
		
		for(int j = sta; j <= m1; j++)
			if(!vis[j]) {
				sta = j;
				break ;
			}
				
		int num =  0, val = 0;
		
		for(int j = sta; j <= m1; j++) {
			if(vis[j])
				continue;
			
			if(a1[j].l >= val)
				val = a1[j].q, num++, vis[j] = 1;
		}
		
		f1[i] = num + f1[i - 1];
		
		if(f1[i] == m1||num == 0)
			flag = 1;
	}
	
	sta = 1;
	flag = 0;
	memset(vis, 0, sizeof(vis));
	
	for(int i = 1; i <= n; i++) {
		
		if(flag) {
			f2[i] = f2[i - 1];
			continue;
		}
		
		for(int j = sta; j <= m2; j++)
			if(!vis[j]) {
				sta = j;
				break ;
			}
				
		int num =  0, val = 0;
		
		for(int j = sta; j <= m2; j++) {
			if(vis[j])
				continue;
			
			if(a2[j].l >= val)
				val = a2[j].q, num++, vis[j] = 1;
		}
		
		f2[i] = num + f2[i - 1];
		
		if(f2[i] == m2||num == 0)
			flag = 1;
	}
	
	int maxa = 0;
	
	for(int i = 1; i <= n; i++)
		maxa = max(maxa, f1[i] + f2[n - i]);
	
	printf("%d\n", maxa);
	
	return 0;
}

/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/

/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
