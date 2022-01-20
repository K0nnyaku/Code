#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)

const int MB=1<<21;
struct FastIN
{
	char buf[MB+100],*p,*e;
	int getChar()
	{
		if(p==e) p=buf,e=buf+fread(buf,1,MB,stdin);
		return p==e?EOF:*p++;
	}
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;

#define ADD(x) Tr[x].add
#define LC(x) Tr[x].lc
#define RC(x) Tr[x].rc
#define V(x) Tr[x].val
#define L(x) Tr[x].l
#define R(x) Tr[x].r    

const int MAXN = 1e7 + 10;

struct Seg { int lc, rc, l, r, val, add; } Tr[MAXN * 2];
int rt, idx;
void Init(int& x, int L, int R);
void Change(int x, int L, int R, int _val);
int Ask(int x, int pos);
int New() { return idx++; }
void Sp(int x) { 
    if(LC(x)) V(LC(x)) += ADD(x); ADD(LC(x)) += ADD(x);
    if(RC(x)) V(RC(x)) += ADD(x); ADD(RC(x)) += ADD(x);
    ADD(x) = 0; }

int n, k;

int main() { /**/
#ifdef LOCAL 
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif

    IN >> k >> n; k -= 1;
    Init(rt, 1, n);

    bool flag = 0;
    int L = 1, R = n;
    while(L < R) {
        int mid = (L + R) >> 1, val = Ask(rt, mid);
        if(val < 0) L = mid + 1;
        else 
        if(val > 0) R = mid;
        else {
                flag = 1;
                break;
            }
    }
    if(flag) printf("YES\n");
    else printf("NO\n");

    while(k--) {
        int l, r, val;
        IN >> l >> r >> val;
        Change(rt, l, r, val);

        bool flag = 0;
        int L = 1, R = n;
        while(L < R) {
            int mid = (L + R) >> 1, val = Ask(rt, mid);
            if(val < 0) L = mid + 1;
            else 
            if(val > 0) R = mid;
            else {
                flag = 1;
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
} /**/

void Init(int& x, int L, int R) {
    x = New(); 
    L(x) = L, R(x) = R; 
    if(L == R) { IN >> V(x); V(x) -= L; return ; } 

    int mid = (L + R) >> 1;
    Init(LC(x), L, mid); 
    Init(RC(x), mid+1, R);
}

void Change(int x, int L, int R, int _val) {

    if(L <= L(x) && R >= R(x)) {
        V(x) += _val; ADD(x) += _val;
        return ;
    }
    if(L <= R(LC(x))) Change(LC(x), L, R, _val);
    if(R >= L(RC(x))) Change(RC(x), L, R, _val);
}

int Ask(int x, int pos) {
//    if(L(x) == R(x)) return V(x);
    if(L(x) == R(x)) {
        return V(x);
    }
    Sp(x);

    int mid = (L(x) + R(x)) >> 1;

    if(mid >= pos) return Ask(LC(x), pos);
    else return Ask(RC(x), pos);
}