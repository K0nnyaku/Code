// ³å£¡ 
#include<cstdio>
#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
using namespace std;

struct node {
	int arr, lea;
} a[100001], b[100001];

bool cmp(node x, node y) {
	return x.arr < y.arr;
}

struct gogogo {
	bool used = 0;
	int leave = 0x7f7f7f7f;
} ava1[100000], ava2[100000];

int init(gogogo ava[], int len, int tm) {
	for(int i = 1; i <= len; i++) {
		if(!ava[i].used)continue;
		else if(ava[i].leave < tm)ava[i].used = 0;
	}
	for(int i = 1; i <= len; i++) {
		if(!ava[i].used)return i;
	}
	return 0;
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);

	int n, m1, m2, mmax = 0, p;
	cin >> n >> m1 >> m2;
	for(int i = 1; i <= m1; i++) cin >> a[i].arr >> a[i].lea;
	sort(a + 1, a + m1 + 1, cmp);
	for(int i = 1; i <= m2; i++) cin >> b[i].arr >> b[i].lea;
	
	sort(b + 1, b + m2 + 1, cmp);
	int c1 = 0, c2 = 0;
	for(int i = 0; i <= n; i++) {
		gogogo tempp;
		tempp.leave = 0x7f7f7f7f;
		tempp.used = 0;
		c1 = c2 = 0;
		int tttt = max(i, n - i);
		for(int k = 0; k <= tttt; k++){
			ava1[k] = ava2[k] = tempp;
		}
		for(int j = 1; j <= m1; j++) {
			p = init(ava1, i, a[j].arr);
			if(p) {
				ava1[p].used = 1;
				ava1[p].leave = a[j].lea;
				c1++;
			}
		}
		for(int j = 1; j <= m2; j++) {
			p = init(ava2, n - i, b[j].arr);
			if(p) {
				ava2[p].used = 1;
				ava2[p].leave = b[j].lea;
				c2++;
			}
		}
		mmax = max(mmax, c1 + c2);
	}
	
	cout << mmax << endl;


	fclose(stdin);fclose(stdout);
	return 0;
}
