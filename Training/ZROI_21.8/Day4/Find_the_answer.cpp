#include<cstdio>
using namespace std;
const int MAXV = 1e9 + 10;
const int MAXN = 1e5 + 10;
#define LCV ((lc) ? (lc->val) : (0))
#define RCV ((rc) ? (rc->val) : (0))

struct Seg_W {
    Seg_W* lc;
    Seg_W* rc;

    int l; 
    int r;

    int val;
	int sum

    Seg_W(int _l = 0, int _r = 0) { l = _l; r = _r; lc = rc = NULL; val = 0; }

    void Insert(int k);
    void Up();
    int Ask(int, int);
	
	void Del();
}*Rt;

int t;

int main() {
	scanf("%d", t);
	
	while(n--) {
		Rt = new Seg(-MAXV, MAXV);
		int n, m;
		scanf("%d%d", &n, &m);

		for(int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x); 

			printf("%d\n", Rt->Ask(x));

			Rt->Insert(x);
		}

	}


    return 0;
}

void Seg_W::Insert(int k) {
    //printf("%d %d %d\n", l, r, val);
    if(l == r) { val++; sum += k; return; }

    int mid = (l + r) >> 1;

    if(k <= mid) {
        if(!lc) lc = new Seg_W(l, mid);
        lc->Insert(k);
    } else {
        if(!rc) rc = new Seg_W(mid+1, r);
        rc->Insert(k);
    }

    Up();
}

void Seg_W::Up() { val = LCV + RCV; sum = LCS + RCS; }

int Seg_W::Ask(int x) {
	if(RCS <= x && RCV > LCV) return rc->Ask(x) + RCS;


    return T;
}

void Del() {
	if(lc) lc->Del(), delete lc;
	if(rc) rc->Del(), delete rc;
}
















