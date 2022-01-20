#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e5 + 10;
int n, m1, m2, Ans, vis1[maxn], vis2[maxn], sum1[maxn], sum2[maxn], f1[maxn], f2[maxn];

struct node {
	int a, b, id;
}M1[maxn], M2[maxn];

bool cmp(node x, node y) {
	if (x.a == y.a) return x.b < y.b;
	return x.a < y.a;
}

int solve(int x) {
	int sum1 = 0, sum2 = 0;
	priority_queue<int, vector<int>, greater<int> > q1, q2;
	for (int i = 1; i <= m1; i++) {
		if (!q1.empty() && q1.top() < M1[i].a) {
			q1.pop();
			q1.push(M1[i].b);
			sum1++;
		}
		else if (q1.size() < x) {
			q1.push(M1[i].b);
			sum1++;
		}
	}
	for (int i = 1; i <= m2; i++) {
		if (!q2.empty() && q2.top() < M2[i].a) {
			q2.pop();
			q2.push(M2[i].b);
			sum2++;
		}
		else if (q2.size() < (n - x)) {
			q2.push(M2[i].b);
			sum2++;
		}
	}
	return sum1 + sum2;
}

signed main () {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &m1, &m2);
	if (n <= 5000) {
		for (int i = 1; i <= m1; i++) scanf("%d%d", &M1[i].a, &M1[i].b);
		for (int i = 1; i <= m2; i++) scanf("%d%d", &M2[i].a, &M2[i].b);
		sort(M1 + 1, M1 + 1 + m1, cmp);
		sort(M2 + 1, M2 + 1 + m2, cmp);
		for (int i = 0; i <= n; i++) {
			Ans = max(Ans, solve(i));
		}
		cout << Ans;
		fclose(stdin);
		fclose(stdout);
		return 0;	
	}
	else {


		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q1, q2;
	
		for (int i = 1; i <= m1; i++) scanf("%d%d", &M1[i].a, &M1[i].b);
		for (int i = 1; i <= m2; i++) scanf("%d%d", &M2[i].a, &M2[i].b);
		sort(M1 + 1, M1 + 1 + m1, cmp);
		sort(M2 + 1, M2 + 1 + m2, cmp);
		for (int i = 1; i <= m1; i++) {
			if (!q1.empty() && q1.top().first < M1[i].a) {
				int id = q1.top().second;
				q1.pop();
				f1[i] = id;
				q1.push(make_pair(M1[i].b, id));
			}
			else {
				int x = q1.size();
				f1[i] = x + 1;
				q1.push(make_pair(M1[i].b, x + 1));
			}
		}
		for (int i = 1; i <= m2; i++) {
			if (!q2.empty() && q2.top().first < M2[i].a) {
				int id = q2.top().second;
				f2[i] = id;
				q2.pop();
				q2.push(make_pair(M2[i].b, id));
			}
			else {
				int x = q2.size();
				f2[i] = x + 1;
				q2.push(make_pair(M2[i].b, x + 1));
			}
		}
		for (int i = 1; i <= m1; i++) vis1[f1[i]]++;
		for (int i = 1; i <= m2; i++) vis2[f2[i]]++; 
		for (int i = 1; i <= n; i++) sum1[i] = sum1[i - 1] + vis1[i];
		for (int i = 1; i <= n; i++) sum2[i] = sum2[i - 1] + vis2[i];
		for (int i = 0; i <= n; i++) {
			Ans = max(Ans, sum1[i] + sum2[n - i]);
		}
		cout << Ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
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

