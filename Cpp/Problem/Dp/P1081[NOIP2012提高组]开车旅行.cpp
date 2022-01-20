#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define T(x) E[x].to
#define V(x) E[x].val

struct FastIN
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getchar())l=c;
		for(x=0;isdigit(c);c=getchar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;

const int _N = 1e5 + 10;
const int _E = 20 + 10;

struct Node{
	int val, pos;
	Node(int _val = 0, int _pos = 0) {
		val = _val; pos = _pos;
	}
	friend bool operator<(Node x, Node y) {
		return x.val < y.val;
	}
};


int NtA[_N], NtB[_N], Far[_N], High[_N], F[_N][_E][2];
int DisA[_N][_E][2], DisB[_N][_E][2];
int n, m;

int Abs(int x);
int Calc(int x, int s);
void PreForNext();

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	IN >> n;
	IOR(i, 0, n) IN >> High[i];
	IOR(i, 0, n-1) Far[i] = Abs(High[i] - High[i+1]);

	PreForNext();

	IOR(i, 0, n) 
		F[i][0][0] = NtA[i],
		F[i][0][1] = NtB[i];
	IOR(e, 1, _E) IOR(i, 0, n-1) IOR(v, 0, 1) 
		if(e != 1) 
			F[i][e][v] = F[F[i][e-1][v]][e-1][v];
		else
			F[i][e][v] = F[F[i][e-1][v]][e-1][v^1];

	IOR(i, 0, n-1) 
		DisA[i][0][0] = DisB[i][0][0] = High[NtA[i]] - High[i],
		DisA[i][0][1] = DisB[i][0][1] = High[NtB[i]] - High[i];

	IOR(e, 1, _E) IOR(i, 0, n-1) IOR(v, 0, 1) 
		if(e != 1)
			DisA[i][e][v] = 
				DisA[F[i][e-1][v]][e-1][v] + DisA[i][e-1][v],
			DisB[i][e][v] = 
				DisB[F[i][e-1][v]][e-1][v] + DisB[i][e-1][v];
		else
			DisA[i][e][v] = 
				DisA[F[i][e-1][v]][e-1][v] + DisA[i][e-1][v^1],
			DisB[i][e][v] = 
				DisB[F[i][e-1][v]][e-1][v] + DisB[i][e-1][v^1];

	return 0;
} /**/

int Abs(int x) {
	return x < 0 ? -x : x;
}

void Pre() {
	NtA[n] = -1;
	set<Node> S;
	IOR(i, n, 0) {
		S.insert(Node(High[i], i));	
		Node nxt = *S.upper_bound(High[i-1], i);
		Node pre = *(--S.lowwer_bound(High[i-1], i));
		NtA[i-1] = Abs(nxt.val - High[i-1]) > Abs(pre.val - High[i-1]) 
			? pre.pos : nxt.pos;
	}

	NtB[n] = NtB[n-1] = -1;
	IOR(i, n, 0) {
		S.insert(Node(High[i], i));	
		if(i >= n-2) continue;

		Node nxt = *S.upper_bound(High[i-1], i);
		Node pre = *(--S.lowwer_bound(High[i-1], i));

		NtA[i-1] = Abs(nxt.val - High[i-1]) < Abs(pre.val - High[i-1]) 
			? pre.pos : nxt.pos;
	}
}

int Calc(int x, int s) {
	LOR(i, _E, -1) {
		if(Dis)<++>	
	}
}















