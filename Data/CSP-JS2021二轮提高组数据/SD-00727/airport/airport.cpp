#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <utility>
#include <cmath>
#include <algorithm>
#include <map>
#define MAXN 100010
#define INF 2147483647
using namespace std;
//--------------------------------------------------
struct Node {
	int l, r, c; 
} e[MAXN];
//--------------------------------------------------
int n, mNei, mJi, cnt1 = 0, cnt2 = 0, op1 = 0, op2 = 0, Max = -INF;
int tree1[MAXN], tree2[MAXN], tmp[MAXN << 1], Airp[MAXN][2];
map<int, int> vis;
//--------------------------------------------------
int read() {
	int f = 0, x = 0; char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}
int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}
bool Comp(Node a, Node b) {
	if (a.l != b.l) return a.l < b.l;
	return a.r < b.r;
}
int Lowbit(int i) {
	return i & (-i);
}
void Update(int pos, int i, int tree[]) {
	while (pos <= cnt1) {
		tree[pos] += i;
		pos += Lowbit(pos);
	}
	return ;
}
int GetSum(int pos, int tree[]) {
	int Sum = 0;
	while (pos >= 1) {
		Sum += tree[pos];
		pos -= Lowbit(pos);
	}
	return Sum;
}
//--------------------------------------------------
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = read(); mNei = read(); mJi = read();
	for (int i = 1, l, r; i <= mNei; ++i) {
		l = read(); r = read();
		e[++cnt2].l = l;
		e[cnt2].r = r;
		e[cnt2].c = 0;
		tmp[++cnt1] = l;
		tmp[++cnt1] = r;
	}
	for (int i = 1, l, r; i <= mJi; ++i) {
		l = read(); r = read();
		e[++cnt2].l = l;
		e[cnt2].r = r;
		e[cnt2].c = 1;
		tmp[++cnt1] = l;
		tmp[++cnt1] = r;
	}
	sort(tmp + 1, tmp + 1 + cnt1);
	for (int i = 1; i <= cnt1; ++i)
		vis[tmp[i]] = i;
	for (int i = 1; i <= cnt2; ++i) {
		e[i].l = vis[e[i].l];
		e[i].r = vis[e[i].r];
	}
	sort(e + 1, e + 1 + cnt2, Comp);
	for (int num = 0; num <= n; ++num) {
		int ans = 0;
		for (int i = 1; i <= cnt1; ++i) tree1[i] = tree2[i] = 0;
		for (int i = 1, l, r, c; i <= cnt2; ++i) {
			l = e[i].l; r = e[i].r; c = e[i].c;
			if (c == 0) {
				++op1;
				Airp[op1][0] = GetSum(l, tree1);
				if (num - Airp[op1][0] <= 0) continue;
				++ans;
				Update(l, 1, tree1);
				Update(r, -1, tree1);
			}
			else {
				++op2;
				Airp[op2][1] = GetSum(l, tree2);
				if (n - num - Airp[op2][1] <= 0) continue;
				++ans;
				Update(l, 1, tree2);
				Update(r, -1, tree2);
			}
		}
		Max = max(Max, ans);
	}
	printf("%d\n", Max);
	fclose(stdin); fclose(stdout); 
	return 0;
}
