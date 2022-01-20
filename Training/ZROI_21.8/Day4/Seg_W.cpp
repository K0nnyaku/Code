#include<cstdio>
using namespace std;
const int MAX = 1e7 + 10;
#define LCV ((lc) ? (lc->val) : (0))
#define RCV ((rc) ? (rc->val) : (0))

struct Seg_W {
    Seg_W* lc;
    Seg_W* rc;

    int l; 
    int r;

    int val;

    Seg_W(int _l = 0, int _r = 0) { l = _l; r = _r; lc = rc = NULL; val = 0; }

    void Insert(int k);
    void Delete(int k);
    void Up();
    int Ask_Sum(int, int);
    Seg_W* Ask_Rank(int);
}*Rt;

int N;

int main() {
    //freopen("TestS.out","w",stdout);
    Rt = new Seg_W(-MAX, MAX);

    scanf("%d", &N);
    while(N--) {
        int opt, x;
        scanf("%d%d",&opt, &x);

        switch(opt) {
            case 1: Rt->Insert(x); break;
            case 2: Rt->Delete(x); break;
            case 3: printf("%d\n", Rt->Ask_Sum(-MAX,x-1)+1); break;
            case 4: printf("%d\n", Rt->Ask_Rank(x)->l); break;
            case 5: printf("%d\n", Rt->Ask_Rank( Rt->Ask_Sum(-MAX,x-1) )->l); break;
            case 6: printf("%d\n", Rt->Ask_Rank( Rt->Ask_Sum(-MAX,x)+1 )->l); break;
        }
    }

    return 0;
}

void Seg_W::Insert(int k) {
    //printf("%d %d %d\n", l, r, val);
    if(l == r) { val++; return; }

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

void Seg_W::Delete(int k) {
    if(l == r) { val--; return; }

    int mid = (l+r) >> 1;
    k <= mid ? lc->Delete(k) : rc->Delete(k);

    Up();
}

void Seg_W::Up() { val = LCV + RCV; }

int Seg_W::Ask_Sum(int L, int R) {
    //printf("%d %d %d\n", l, r, val);
    if(l >= L and r <= R) return val;

    int T = 0;
    if(lc and L <= lc->r) T += lc->Ask_Sum(L, R);
    if(rc and R >= rc->l) T += rc->Ask_Sum(L, R);

    return T;
}

Seg_W* Seg_W::Ask_Rank(int k) {
    //printf("%d %d %d\n", l, r, val);
    if(l == r) return this;

    return LCV < k ? rc->Ask_Rank(k - LCV) : lc->Ask_Rank(k); 
}
