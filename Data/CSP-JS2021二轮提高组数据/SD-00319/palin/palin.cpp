#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
const int N = 2e6 + 5;

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

int T;
int n;
int a[N];
int b[N];

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	
	T = re();
	while (T -- ) {
		n = re();
		for(int i = 1; i <= n; i++)
			a[i] = re(), printf("L");
		
		for(int i = 1; i <= n; i++)
			printf("R");
		printf("\n");
	}
	
	return 0;
}

