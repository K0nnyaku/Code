#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks") 
#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)
#define ER(i, x) for(int i = Head[x]; i; i = E[i].next)

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

const int _N = 1e3 + 2;
const int _C = 2e7 + 2;

struct Node {
	int pos, val;
	Node(int _pos = 0, int _val = 0) {
		pos = _pos, val = _val;
	}
};

int C[_N], W[_N], Num[_N], F[_C];
int n, m;

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	IN >> n >> m;
	IR(i, 1, n) 
		IN >> C[i] >> W[i] >> Num[i];

	memset(F, 0xcf, sizeof F);
	F[0] = 0;
	deque<Node> Q;
	IR(i, 1, n) IR(u, 0, C[i]-1) SR(p, (m-u)/C[i], 0) {

		if(p == (m-u)/C[i]) 
			SR(k, p-1, max(p-Num[i], 0)) {
				if(k == p - 1) Q.clear();
				int tmp = F[u+k*C[i]] - k * W[i];
				while(Q.size() && Q.back().val <= tmp) Q.pop_back();
				Q.push_back(Node(k, tmp));
			}

		while(Q.size() && Q.front().pos >= p) Q.pop_front();

		if(Q.size()) 
			F[u + p * C[i]] = 
					max(F[u + p * C[i]], 
						Q.front().val + W[i] * p);
		
		int k = p - Num[i] - 1, tmp;
		if(k >= 0) {
			tmp = F[u + k * C[i]] - W[i] * k;
			while(Q.size() && Q.back().val < tmp) Q.pop_back();
			Q.push_back(Node(k, tmp));
		}
	}

	int ans = 0;
	IR(i, 1, m) 
		ans = max(ans, F[i]);
	
	cout << ans << "\n";
	
	return 0;
} /**/












