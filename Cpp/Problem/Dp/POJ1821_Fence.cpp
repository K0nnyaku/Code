//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
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

const int _N = 1e4 + 6e3 + 10;
const int _M = 1e2 + 10;

struct Worker {
	int l, p, s;
	friend bool operator<(const Worker &x, const Worker &y) {
		return x.s < y.s;
	}
}A[_M];
struct Node {
	int pos, val;
	Node(int _pos = 0, int _val = 0) {
		pos = _pos; val = _val;
	}
};
#define S(x) A[x].s
#define P(x) A[x].p
#define L(x) A[x].l
int F[_M][_N];
int m, n;

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	IN >> n >> m;
	IOR(i, 1, m+1) 
		IN >> A[i].l >> A[i].p >> A[i].s;

	sort(A+1, A+m+1);

	deque<Node> Q; 
	IOR(i, 1, m+1) IOR(v, 1, n+1) {                          
		if(v == S(i)) {
			Q.clear();
			IOR(k, max(0, v-L(i)), S(i)) {
				int tmp = F[i-1][k] - P(i) * k;
				while(Q.size() && Q.back().val <= tmp) Q.pop_back();
				Q.push_back( Node(k, tmp) );
			}
		}
		if(v >= S(i)) {
			while(Q.size() && Q.front().pos < v - L(i)) Q.pop_front();
			if(Q.size()) F[i][v] = max(F[i][v], Q.front().val + v * P(i));
		}
		F[i][v] = max(F[i][v], max( F[i-1][v], F[i][v-1]) );
	}

	int ans = 0;
	IOR(i, 1, n+1) 
		ans = max(ans, F[m][i]);

	cout << ans << "\n";

	return 0;
} /**/


















