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
 
//const int MAXN = 9e6 + 10;
const int MAXN = 3e3 + 10;
const int MAXC = 2;
const int P = 1e9 + 7;
 
int Tr[MAXN*MAXN][MAXC];
int Pos[MAXN], Fa[MAXN*MAXN], Dp[MAXN*MAXN]; 
int m, ans, cnt, idx, z;
 
void TrieIns(int p, int k);
void NormalIns(int x);

void Add(int &x,int y){  //手动取模
	x+=y;
	while(x>=P) x-=P;
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/In.in", "r", stdin);
	freopen("I:/Code/Out.out", "w", stdout);
#endif
	Dp[0] = 1;
	IN >> m;
 
	IOR(i, 0, m) {
		int x; IN >> x;
		NormalIns(x);
		cout << ans << "\n";
	}
 
	return 0;
} /**/
 
void NormalIns(int x) {
	Pos[idx++] = 0;
	IOR(i, 0, idx) {
		int t = Pos[i];
		if(!Tr[t][x]) TrieIns(Pos[i], x);
		Pos[i] = Tr[t][x];
	}
}
 
void TrieIns(int p, int k) {
	Tr[p][k] = ++cnt;
	Fa[cnt] = p;
 
	int hash = 0, ffa;
	p = cnt;
 
	IOR(i, 0, 4) {
		ffa = Fa[p],
		hash += (Tr[ffa][0] != p) << i;
 
//		hash += (Tr[ffa][0] != p) * (1 << i);
 
//		Q.push(Tr[ffa][0] != p);
 
//		if(i == 3) {
//			for(int k = 1, v = 0; k <= 8; k *= 2, v++) {
//				int tp = Q.front(); Q.pop();
//				hash += k * tp;
 
//			}
//			cout << "\n!!!!\n";
//			IOR(i, 0, 4) cout << a[i] << " ";
//			cout << hash << "\n";
//			cout << "\n!!!!\n";
//		}
 
		if( (i != 3) || (hash != 3 && hash != 5 && hash != 14 && hash != 15) )
			Add(Dp[cnt], Dp[ffa]);
//			Dp[cnt] = (Dp[cnt] % P + Dp[ffa] % P) % P;
 
		p = ffa;
 
		if(p == 0) break;
	}
//	ans = (ans % P + Dp[cnt] % P) % P;
	Add(ans, Dp[cnt]);
}
 
 
 
 
 
 
 
 
