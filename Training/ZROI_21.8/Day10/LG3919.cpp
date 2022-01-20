#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXM = 1e6 + 10;
const int MAXV = 1e6 + 10;

struct Seg {
    int lc, rc;
    int l, r;
    int val;

    Seg() { lc = rc = l = r = val = 0; }

    void Init(int L, int R);
    void Ins(int pos, int v);
}rt[MAXM];

int n, m;
int Index;

int main() {
    scanf("%d%d", &n, &m);
    rt[0].l = 0, rt[0].r = MAXV;
    for(int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        rt[0].Ins(i, x);
    }


    return 0;
}

void Seg::Init(int L, int R) {
    l = L, r = R;
    if(l == r) { scanf("%d", &val); return ; }
}