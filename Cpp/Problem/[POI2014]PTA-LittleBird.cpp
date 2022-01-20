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

const int MAXN = 1e6 + 10;

struct Node{
	int pos, val;
	Node(int _pos = 0, int _val = 0) {
		pos = _pos; val = _val;
	}
};
deque<Node> Q;
int H[MAXN], q, n, F[MAXN];

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
//	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	IN >> n;
	IOR(i, 0, n) IN >> H[i];

	IN >> q;
	while(q--) {
		int lm, ans = 0, pos = 0; IN >> lm;
		F[0] = 0;

		Q.clear(); Q.push_back(Node(0, H[0]));

		IOR(i, 1, n) {
			while(pos + lm < i) 
				Q.pop_front(), pos = Q.size() ? Q.front().pos : i;

			F[i] = F[Q.front().pos] + (Q.front().val <= H[i]);

			while(Q.back().val < H[i] && !Q.empty()) 
				Q.pop_back();

			Q.push_back(Node(i, H[i]));
		}

		cout << ans << "\n";
	}


	return 0;
} /**/







 
