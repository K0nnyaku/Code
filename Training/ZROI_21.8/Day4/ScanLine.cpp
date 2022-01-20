#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e5 + 10;

struct Seg {
	Seg *lc, *rc;
	int l, r;
	int cnt, len;

	void Init(int L, int R);
	void Modify(int L, int R, bool x);
	int Ask(int L, int R);
}*rt = new Seg;

struct Line {
	int x;
	int y1;
	int y2;
	bool x;

	Line(int _x = 0, int _y1 = 0, int _y2 = 0, bool _x) {
		x = _x; y1 = _y1; y2 = _y2; x = _x;
	}

	friend bool operator<(Line x, Line y) {
		return x.x < y.x;
	}
}L[MAXN];

int n, iNdex, ans, mx = -1;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int a, b, x, y;
		scanf("%d%d%d%d", &a, &b, &x, &y);
		L[iNdex++] = Line(a, y, b, 1);
		L[iNdex++] = Line(x, y, b, -1);
		mx = max(mx, max(y, b));
	}

	rt->Init(1, mx);

	for(int i = 0; i < n-1; i++) {
		rt->Modify(L[i].y1, L[i].y2, L[i].x);
		int len = rt->Ask(1, mx);
		ans += len * (L[i+1].x - L[i].x);
	}

	printf("%d", ans);

	return 0;
}

void Seg::Init(int L, int R) {
	l = L, r = R;
	if(l == r) return ;
	
	int mid = (L + R) >> 1;

	
}
































