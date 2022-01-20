#include<cstdio>
using namespace std;
#define LCV ((lc) ? (lc->val) : (0))
#define RCV ((rc) ? (rc->val) : (0))
#define TLCV ((T and T->lc) ? (T->lc->val) : (0))
#define TRCV ((T and T->rc) ? (T->rc->val) : (0))

const int MAXRT = 2e5 + 10;
const int MAXVAL = 1e9 + 10;

struct Seg_W {
    Seg_W* lc;
    Seg_W* rc;

    int val;

    Seg_W() { lc = rc = NULL; val = 0; }

    void Insert(int, int, int);
    int Ask(int, int, Seg_W*, int);
    void Up();
}*rt[MAXRT];

int N, M, Index;

int main() {
    scanf("%d%d", &N, &M);
    rt[Index] = new Seg_W;

    while(N--) {
        int T;
        scanf("%d", &T);
        rt[++Index] = new Seg_W; *rt[Index] = *rt[Index-1];
        rt[Index]->Insert(-MAXVAL, MAXVAL, T);
    }

    while(M--) {
        int l, r, pos;
        scanf("%d%d%d", &l, &r, &pos);
        printf("%d\n", rt[r]->Ask(-MAXVAL, MAXVAL, rt[l-1], pos));
    }

    return 0;
}

void Seg_W::Insert(int l, int r, int pos) {
    if(l == r) { val++; return; }

    int mid = (l + r) >> 1;
    if(pos <= mid) {
        if(!lc) lc = new Seg_W;
        else { Seg_W T = *lc; lc = new Seg_W; *lc = T; }
        lc->Insert(l, mid, pos);
    }else {
        if(!rc) rc = new Seg_W;
        else { Seg_W T = *rc; rc = new Seg_W; *rc = T; }
        rc->Insert(mid + 1, r, pos);
    }

    Up();
    //printf("Insert: Index = %d l = %d r = %d pos = %d val = %d\n",Index, l, r, pos, val);

}


int Seg_W::Ask(int l, int r, Seg_W* T, int pos) {
    //printf("Index = %d l = %d r = %d pos = %d val: %d\n",Index, l, r, pos, TLCV);
    if(l == r) return l;

    int mid = (l + r) >> 1;
    if(pos <= LCV - TLCV) return lc->Ask(l, mid, (T ? T->lc : NULL), pos);
    else return rc->Ask(mid+1, r, (T ? T->rc : NULL), pos - (LCV - TLCV)); 
}

void Seg_W::Up() {
    val = LCV + RCV;
}

