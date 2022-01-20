#include <bits/stdc++.h>
#define DBG if (debug)
#define ND if (!debug)
using namespace std;

typedef pair<int, int> PII;
const int N = 100005;

bool debug = false;

inline void read(int &x) {
	int sum = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		sum = (sum * 10 + c - '0'); 
		c = getchar();
	}
	x = f * sum;
}

struct pc { // plane combination
	int a, b, cnt, ps;
	
	bool operator <(const pc &ref) const {
		return a < ref.a;
	}
} p1[N], p2[N], in1[N], in2[N];

inline void combine(pc in1[], pc p1[], int m1, int &idx1) {
	int a = 0, b = 0;
	p1[++idx1].a = in1[1].a;
	p1[idx1].b = in1[1].b;
	p1[idx1].cnt = 1;
	priority_queue<PII, vector<PII>, greater<PII>> minq;
	minq.push(make_pair(p1[idx1].b, idx1));
	for (int i = 2; i <= m1; i++) {
		a = in1[i].a;
		b = in1[i].b;
		PII t = minq.top();
		DBG printf("Pos %d has min r %d\n", t.second, t.first);
		if (a > t.first) {
			p1[t.second].b = b;
			p1[t.second].cnt++;
			minq.pop();
			minq.push(make_pair(b, t.second));
			DBG printf("Plane #%d (%d, %d) combined into %d (minr = %d)\n", i, a, b, t.second, t.first);
		} else {
			p1[++idx1].a = a;
			p1[idx1].b = b;
			p1[idx1].cnt = 1;
			minq.push(make_pair(b, idx1));
			DBG printf("Plane #%d (%d, %d) newed at %d\n", i, a, b, idx1);
		}
	}
}

int n, m1, m2, idx1, idx2;

int main() {
	ND freopen("airport.in", "r", stdin);
	ND freopen("airport.out", "w", stdout);
	read(n);
	read(m1);
	read(m2);
	for (int i = 1; i <= m1; i++) {
		read(in1[i].a);
		read(in1[i].b);
	}
	for (int i = 1; i <= m2; i++) {
		read(in2[i].a);
		read(in2[i].b);
	}
	sort(in1 + 1, in1 + m1 + 1);
	sort(in2 + 1, in2 + m2 + 1);

	combine(in1, p1, m1, idx1);
	combine(in2, p2, m2, idx2);
	
	DBG {
		for (int i = 1; i <= idx1; i++) {
			printf("(%d, %d)", p1[i].a, p1[i].b);
		}
		puts("");
		for (int i = 1; i <= idx2; i++) {
			printf("(%d, %d)", p2[i].a, p2[i].b);
		}
		puts("");
	}
	int ans = 0;
	sort(p1 + 1, p1 + idx1 + 1);
	sort(p2 + 1, p2 + idx2 + 1);
	for (int i = 1; i <= idx1; i++) {
		p1[i].ps = p1[i - 1].ps + p1[i].cnt;
	}
	for (int i = 1; i <= idx2; i++) {
		p2[i].ps = p2[i - 1].ps + p2[i].cnt;
	}
	for (int domestic = 0; domestic <= n; domestic++) {
		ans = max(ans, p1[domestic].ps + p2[n - domestic].ps);
	}
	printf("%d\n", ans);
	return 0;
}
