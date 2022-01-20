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
 
const int MAXN = 60 + 10;
const int MAXV = 1e6 + 10;
 
long long T[MAXN], A[MAXN], C[MAXN][MAXN];
long long Bk[MAXV]; 
long long n, s, k, t, ans, cnt;
 
void Pre();
 
int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	IN >> n >> k >> s >> t;
	IOR(i, 0, n) IN >> T[i];
 
	Pre();
 
	if((s | t) ^ t) return cout << 0, 0;
 
	IOR(i, 0, n) 
		if( (s & T[i]) == s && (t | T[i]) == t ) 
			A[cnt++] = T[i];
 
	IOR(i, 1, k+1) 
		ans += C[cnt][i];
 
	int lm = s ^ t; 
	for(int i = lm; i; i = (i - 1) & lm) {
		IOR(v, 0, cnt) Bk[A[v] & i]++;
 
		IOR(v, 0, cnt) {
			IOR(l, 1, k+1) 
				ans += C[Bk[A[v] & i] ][l] * (__builtin_popcount(i) & 1 ? -1 : 1);
			Bk[A[v] & i] = 0;
		}
	}
 
	cout << ans;
 
	return 0;
} /**/
 
void Pre() {
	IOR(i, 0, MAXN) C[i][0] = 1;
 
	IOR(i, 1, MAXN) IOR(v, 1, MAXN)
			C[i][v] = C[i-1][v] + C[i-1][v-1];
}
