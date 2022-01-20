#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 2e3 + 10;
const int INF = 0x3f3f3f3f;
#define LC(x) ((lc)?(lc->x):(0))
#define RC(x) ((rc)?(rc->x):(0))


struct Seg_W {
	Seg_W* lc;
	Seg_W* rc;

	long long mxx;
	long long sum;
	long long left;
	long long right;

	void Free();	
	void Insert(int l, int r, int pos, long long x);
	void Up();

	Seg_W(long long _mxx = -INF, long long _sum = -INF, long long _left = -INF,
			long long _right = -INF) {
		mxx = _mxx; sum = _sum; left = _left; right = _right;
		lc = rc = NULL;
	}

}*rt = new Seg_W;


struct Node {
	int x;
	int y;
	long long w;

	Node(int _x = 0, int _y = 0, long long _w = 0) {
		x = _x; y = _y; w = _w;
	}

	friend bool operator<(Node x, Node y) {
		return x.x < y.x;
	}
};

int t;

void Init();

int main() {
	#ifdef LOCAL
		freopen("In.in", "r", stdin);
	#endif 

	scanf("%d", &t);
	while(t--) {
		Node A[MAXN];
		long long ans = -INF;
		int C[MAXN];
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d%d%lld", &A[i].x, &A[i].y, &A[i].w);
			C[i] = A[i].y;
		}

		int sum = unique(C+1, C + n + 1) - C;
		sort(C + 1, C + sum + 1);
		sort(A + 1, A + n + 1);
		for(int i = 1; i <= n; i++) A[i].y = lower_bound(C+1, C+sum+1, A[i].y) - C;

//		for(int i = 1; i <= n; i++) {
//			printf("i = %d, x = %d, y = %d\n", i, A[i].x, A[i].y);
//		}

		for(int i = 1; i <= n; i++) {
			rt->Free();
			for(int j = i; j <= n; j++) {
				while(j == n || A[j].x == A[j+1].x)
					rt->Insert(1, n, A[j].y, A[j].w), j++;
				ans	= max(ans, rt->mxx);
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}

void Seg_W::Free() {
	if(lc) lc->Free(), delete lc, lc = NULL;
	if(rc) rc->Free(), delete rc, rc = NULL;
}

void Seg_W::Up() {
	sum = LC(sum) + RC(sum); 
	mxx = max(max(LC(mxx), RC(mxx)), LC(right) + RC(left));
	left = max(left, max(LC(sum) + RC(left), LC(mxx)));
	right = max(right, max(RC(sum) + LC(right), RC(mxx)));
}

void Seg_W::Insert(int l, int r, int pos, long long x) {
	if(l == r) { sum = left = right = mxx = sum != -INF ? sum + x : x; return ; }
//	printf("l = %d, r = %d, pos = %d\n", l, r, pos);

	if(!lc) lc = new Seg_W;
	if(!rc) rc = new Seg_W;
	
	int mid = (l + r) >> 1;
	pos <= mid ? lc->Insert(l, mid, pos, x) : rc->Insert(mid+1, r, pos, x);

	Up();
}













