//21!9-324@emb
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+1;

int n, m1, m2;
int cntt1[MAXN], cntt2[MAXN], segTree[MAXN << 2][2];

struct flightt {
	int arrive, leave;
} ff1[MAXN], ff2[MAXN];

inline int read() {
	int x = 0; char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x;
}

bool cmp(const flightt &a, const flightt &b) {
	return a.arrive < b.arrive;
}

inline void push_up(int p, int idd) {
	segTree[p][idd] = min(segTree[p << 1][idd], segTree[p << 1 | 1][idd]);
}

int query(int p, int l, int r, flightt gk, int idd) {//询问廊桥编号最小且离开时间小于gk的到达时间廊桥&修改 
	if (l == r) {
		segTree[p][idd] = gk.leave;
		return l;
	}
	int mid = (l + r) >> 1;
	int ans = 0;
	if (segTree[p << 1][idd] < gk.arrive) ans = query(p << 1, l, mid, gk, idd);
	else ans = query(p << 1 | 1, mid + 1, r, gk, idd);
	push_up(p, idd);
	return ans;
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);

	n = read(), m1 = read(), m2 = read();
	for (int i = 1; i <= m1; i++) {
		ff1[i].arrive = read(), ff1[i].leave = read();
	}
	for (int i = 1; i <= m2; i++) {
		ff2[i].arrive = read(), ff2[i].leave = read();
	}
	
	sort(ff1 + 1, ff1 + m1 + 1, cmp);
	sort(ff2 + 1, ff2 + m2 + 1, cmp);
	
	cntt1[query(1, 1, m1, ff1[1], 0)] = 1;
	for (int i = 2; i <= m1; i++) {
		cntt1[query(1, 1, m1, ff1[i], 0)]++;
	}
	
	cntt2[query(1, 1, m2, ff2[1], 1)] = 1;
	for (int i = 2; i <= m2; i++) {
		cntt2[query(1, 1, m2, ff2[i], 1)]++;
	}
	
	for (int i = 1; i <= n; i++) {
		cntt1[i] += cntt1[i - 1];
		//cout << cntt1[i] << ' ';
	}
	//cout << endl;
	
	for (int i = 1; i <= n; i++) {
		cntt2[i] += cntt2[i - 1];
		//cout << cntt2[i] << ' ';
	}
	//cout << endl;
	
	int ansss = 0;
	for (int i = 0; i <= n; i++) {
		ansss = max(ansss, cntt1[i] + cntt2[n - i]);
	}
	cout << ansss;

	fclose(stdin);
	fclose(stdout);
	return 0;
}


