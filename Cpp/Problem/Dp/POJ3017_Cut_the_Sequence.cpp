//#include<bits/stdc++.h>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)
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

const int _N = 1e6 + 2;
const int _E = 20 + 2;
const int INF = 0x3f3f3f3f;

struct Node {
	long long val, pos;
	Node(long long _pos = 0, long long _val = 0) {
		pos = _pos, val = _val;
	}
	bool friend operator<(const Node &x, const Node &y) {
		return x.val > y.val;
	}
	bool friend operator==(const Node &x, const Node &y) {
		return x.val == y.val && x.pos == y.pos;
	}
};

long long A[_N], F[_N], C[_N], P[_N], St[_N][_E], S[_N];
long long n, m;

long long Ask(long long l, long long r);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	IN >> n >> m;
	IR(i, 1, n) IN >> A[i], S[i] = S[i-1] + A[i];

	//C[i]
	IR(i, 1, n) {
		int l = 1, r = i;
		while(l < r) {
			int mid = (l + r) >> 1;
			if(S[i] - S[mid-1] <= m) r = mid;
			else l = mid + 1;
		}
		C[i] = l-1;
	}

//	IR(i, 1, n) 
//		printf("C[%d] = %d\n", i, C[i]);

	//St
//	IR(i, 0, n) P[i] = log2(i); 
	IR(i, 0, n) P[i] = log(i*1.0) / log(2.0); 
	IR(i, 1, n) St[i][0] = A[i];
	IR(e, 1, P[n]) IR(i, 1, n-(1 << e)+1) 
		St[i][e] = max(St[i][e-1], St[i+(1 << (e-1))][e-1]);

	//Dp
	memset(F, 0x3f, sizeof F);
	F[0] = 0;
	deque<Node> Q;
	priority_queue<Node> Hf; 
	priority_queue<Node> Hs;
	
	IR(i, 1, n) {

		while(Q.size() && Q.back().val <= A[i]) 
			Hs.push(Node(Q.back().pos, F[Q.back().pos] + A[Q.back().pos+1])),
			Q.pop_back();
		while(Q.size() && Q.front().pos < C[i]) 
			Hs.push(Node(Q.front().pos, F[Q.front().pos] + A[Q.front().pos+1])),
			Q.pop_front();

		while(Hf.size() && Hs.size() && Hf.top() == Hs.top()) 
			Hf.pop(), Hs.pop();

		if(Hf.size()) 
			F[i] = Hf.top().val;

		F[i] = min( F[i], F[C[i]] + Ask(C[i]+1, i) );

		Q.push_back(Node(i, A[i]));
		Hf.push(Node(i, F[i] + A[i+1]));

	}

	cout << (F[n] != INF ? F[n] : -1);

	return 0;
} /**/

long long Ask(long long l, long long r) {
	long long p = P[r-l+1];
	return max(St[l][p], St[r-(1<<p)+1][p]);
}

















