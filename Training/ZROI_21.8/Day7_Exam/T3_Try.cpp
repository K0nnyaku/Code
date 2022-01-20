#include<cstdio>
#include<algorithm>
using namespace std;

struct Seg_W {
    Seg_W* lc;
    Seg_W* rc;

    int l;
    int r;
    int val;

    Seg_W() { lc = rc = NULL; l = r = val =0; }

    void Insert(int);
    void Up();
    int Ask(int);
}

int main() {

    return 0;
}


