#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;

struct Seg 
{
	Seg *lc;
	Seg *rc;
	int l;
	int r;
	LL val;
	LL add;
	LL mul;

	void Init(LL,LL);
	void Sp();
	void Add(LL,LL,LL);
	void Mul(LL,LL,LL);
	void Up();
	void Sp_A(LL);
	void Sp_M(LL);
	LL Ask(LL,LL);
	
	Seg() {val = add = 0; mul = 1;}	
}*rt;

LL N, M, P;
int main() /**/
{
	scanf("%lld%lld%lld",&N,&M,&P);
	rt = new Seg;
	rt->Init(1,N);
	for(int i = 1; i <= M; i++)
	{
		LL op, x, y, k;
		scanf("%lld",&op);
		switch(op)
		{
			case 1: scanf("%lld%lld%lld",&x,&y,&k); rt->Mul(x,y,k); break;
			case 2: scanf("%lld%lld%lld",&x,&y,&k); rt->Add(x,y,k); break;
			case 3: scanf("%lld%lld",&x,&y); printf("%lld\n",rt->Ask(x,y)); break;
		}
	}
	
	return 0;	
} /**/

void Seg::Init(LL L, LL R)
{
	l = L; r = R;
	if(l == r) {scanf("%lld",&val); return;}
	LL mid = (l+r)>>1;
	lc = new Seg;	lc->Init(l,mid);
	rc = new Seg;	rc->Init(mid+1,r);
	Up();
}
void Seg::Add(LL L, LL R, LL k)
{
	if(l >= L and r <= R) {Sp_A(k); return;}
	Sp();
	if(L <= lc->r) lc->Add(L,R,k);
	if(R >= rc->l) rc->Add(L,R,k); 
	Up();
}
void Seg::Mul(LL L, LL R, LL k)
{
	if(l >= L and r <= R) {Sp_M(k); return;}
	Sp();
	if(L <= lc->r) lc->Mul(L,R,k);
	if(R >= rc->l) rc->Mul(L,R,k);
	Up();
}
void Seg::Sp_A(LL k)
{	
	val = (val + (r-l+1) * k) % P;
	add = (add + k) % P;
+
void Seg::Sp_M(LL k)
{
	val = (val * k) % P;
	add = (add * k) % P;
	mul = (mul * k) % P;
}
void Seg::Sp()
{
	if(mul != 1) {lc->Sp_M(mul); rc->Sp_M(mul);}
	if(add) {lc->Sp_A(add); rc->Sp_A(add);}
	mul = 1; add = 0;
}
LL Seg::Ask(LL L, LL R)
{
	if(l >= L and r <= R) return val;
	Sp();
	LL T = 0;
	if(L <= lc->r) T = (T + lc->Ask(L,R)) % P;
	if(R >= rc->l) T = (T + rc->Ask(L,R)) % P;
	return T;  
}
void Seg::Up() {val = (lc->val + rc->val) % P;}
