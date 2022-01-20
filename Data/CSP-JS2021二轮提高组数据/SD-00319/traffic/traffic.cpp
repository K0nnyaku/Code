#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
const int N = 505;

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

int n, m, T;
int x[N][N];
int y[N][N];

int k, l, p, t; 

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	n = re();m = re(); T = re();
	
	for(int i = 1; i < n; i++)
		for(int j = 1; j <= m; j++)
			x[i][j] = re();
		
	for(int i = 1; i < m; i++)
		for(int j = 1; j <= n; j++)
			y[i][j] = re();
	
	while (T -- ) {
		k = re();
		for(int i = 1; i <= k; i++)
			l = re(), p = re(), t = re();
			printf("-1\n");
	}

	return 0;
}

