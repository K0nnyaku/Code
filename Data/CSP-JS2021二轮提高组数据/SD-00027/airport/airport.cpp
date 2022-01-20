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

const int N = 100010;

struct node {
	int s, e;
	bool operator > (const node &another) const{
		return e > another.e;
	}
}a1[N], a2[N];
priority_queue<node, vector<node>, greater<node> > q1, q2;
int n, m1, m2, ans;

bool cmp(const node &a, const node &b) {
	return a.s < b.s;
}
int mymax(int a, int b) {
	return a > b ? a : b;
}
int m1_maxn, m2_maxn;

int check(int sum1) {
	while(q1.size()) q1.pop(); 
	while(q2.size()) q2.pop();
	int sum2 = n - sum1, res1 = 0, res2 = 0;
	FOR(i,1,m1) {
		while(!q1.empty() && a1[i].s >= q1.top().e) q1.pop();
		if(q1.size() + 1 > sum1) continue;
		q1.push(a1[i]); res1++; 
	}
	FOR(i,1,m2) {
		while(!q2.empty() && a2[i].s >= q2.top().e) q2.pop();
		if(q2.size() + 1 > sum2) continue;
		q2.push(a2[i]); res2++; 
	}
	return res1 + res2;
}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &m1, &m2);
	FOR(i,1,m1) {
		scanf("%d%d", &a1[i].s, &a1[i].e);
	}
	FOR(i,1,m2) {
		scanf("%d%d", &a2[i].s, &a2[i].e);
	}
	sort(a1+1, a1+1+m1, cmp);
	sort(a2+1, a2+1+m2, cmp);
	FOR(i,1,m1) {
		while(!q1.empty() && a1[i].s >= q1.top().e) q1.pop();
		q1.push(a1[i]);
		m1_maxn = mymax(m1_maxn, q1.size());
	}
	
	FOR(i,1,m2) {
		while(!q2.empty() && a2[i].s >= q2.top().e) q2.pop();
		q2.push(a2[i]);
		m2_maxn = mymax(m2_maxn, q2.size());
	}
	//cout << m1_maxn << ' ' << m2_maxn<<"\n";
	if(m1_maxn + m2_maxn <= n ) {
		printf("%d\n", m1 + m2);
		return 0;
	}
	int st = mymax(0, n - m2_maxn);
	int ed = min(n, m1_maxn);
	FOR(i,st,ed) {
		ans = mymax(ans, check(i));
	}
	printf("%d\n", ans);
	fclose(stdin); fclose(stdout);
	return 0;
}

