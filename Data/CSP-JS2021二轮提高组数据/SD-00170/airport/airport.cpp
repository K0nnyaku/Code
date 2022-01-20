#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int M = 100000 + 100;

int n, m1, m2, m12, m22;

pair<int, int> q1[2 * M], q2[2 * M];

int p[M];
int check(int v) {
	if(v < 0 || v > n) return 0;
	
	int cnt = 0, rmn = v;
	memset(p, 0, sizeof p);
	for(int i = 1; i <= m12; ++i) {
		int tp = q1[i].second;
		if(p[tp] == 0) {
			if(rmn > 0) {
				++cnt;
				--rmn;
				p[tp] = 1;
			}
			else p[tp] = 2;
		}
		else {
			if(p[tp] == 1) ++rmn;
		}
	}
	
	rmn = n - v;
	memset(p, 0, sizeof p);
	for(int i = 1; i <= m22; ++i) {
		int tp = q2[i].second;
		if(p[tp] == 0) {
			if(rmn > 0) {
				++cnt;
				--rmn;
				p[tp] = 1;
			}
			else p[tp] = 2;
		}
		else {
			if(p[tp] == 1) ++rmn;
		}
	}
	
	return cnt;
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &m1, &m2);
	m12 = m1 * 2;
	m22 = m2 * 2;
	for(int i = 1; i <= m1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		q1[i * 2 - 1] = make_pair(a, i);
		q1[i * 2] = make_pair(b, i);
	}
	for(int i = 1; i <= m2; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		q2[i * 2 - 1] = make_pair(a, i);
		q2[i * 2] = make_pair(b, i);
	}
	sort(q1 + 1, q1 + 1 + m12);
	sort(q2 + 1, q2 + 1 + m22);
	
	int l = 0, r = n;
	while(l < r - 2) {
		int ml = (l + r - 1) / 2, mr = ml + 1;
		int lv = check(ml), rv = check(mr);
		
		if(lv < rv) l = ml;
		else r = mr;
	}
	printf("%d", max(max(check(l), check(r)), check(l + 1)));
	return 0;
}
