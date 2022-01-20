#include<cstdio>
using namespace std;
const int MAX = 1e6 + 10;
#define LCV ((lc) ? (lc->val) : (0))
#define RCV ((rc) ? (rc->val) : (0))

struct Seg_W {
    Seg_W* lc;
    Seg_W* rc;

    int val;

	Seg_W() {
		lc = rc = NULL;
		val = 0;
	}

    void Insert(int, int, int k);
    void Delete(int, int, int k);
    void Up();
	void Del();
    int Ask_Rank(int, int, int);
}*Rt;

int N, tot;

int Abs(int x);

int main() {
	freopen("In.in","r",stdin);
    Rt = new Seg_W;

	int n, q;
	scanf("%d%d", &n, &q); tot = n;
	while(n--) {
		int x;
		scanf("%d", &x);
		Rt->Insert(1, MAX, x);
	}

	while(q--) {
		int x;
		scanf("%d", &x);
		if(x < 0) {
			Rt->Delete(1, MAX, Abs(x));
			tot--;
		}
		else {
			Rt->Insert(1, MAX, x);
			tot++;
		}
	}

	if(tot) {
		printf("%d", Rt->Ask_Rank(1, MAX, 1));
	}
	else {
		printf("%d", 0);
	}


    return 0;
}

void Seg_W::Del() {
	if(lc && !lc->val) lc->Del(), delete lc;
	if(rc && !rc->val) rc->Del(), delete rc;
}

void Seg_W::Insert(int L, int R, int k) {
    if(L == R) { val++; return; }

    int mid = (L + R) >> 1;

    if(k <= mid) {
        if(!lc) lc = new Seg_W;
        lc->Insert(L, mid, k);
    } else {
        if(!rc) rc = new Seg_W;
        rc->Insert(mid+1, R, k);
    }

    Up();
}

void Seg_W::Delete(int L, int R, int k) {
    if(L == R) { val--; return; }
	
	int mid = (L + R) >> 1;

	k <= LCV ? lc->Delete(L, mid, k) : rc->Delete(mid+1, R, k - LCV);

    Up();
}

void Seg_W::Up() { val = LCV + RCV; Del(); }

int Seg_W::Ask_Rank(int L, int R, int k) {
    if(L == R) return L;

	int mid = (L + R) >> 1;
    return k > LCV ? rc->Ask_Rank(mid+1, R, k - LCV) : lc->Ask_Rank(L, mid, k); 
}

int Abs(int x) {
	return x < 0 ? -x : x;
}
