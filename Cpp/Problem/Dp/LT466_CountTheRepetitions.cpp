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

const int _C = 1e2 + 10;
const int _K = 26 + 10;
const int _E = 20 + 10;
const int INF = 0x3f3f3f3f;

int F[_E][_C];
int n1, n2, len1, len2, ans;
char S1[_C], S2[_C];
bool Bk[_K];

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	scanf("%s%s", S1+1, S2+1);
	IN >> n1 >> n2;
	len1 = strlen(S1+1), len2 = strlen(S2+1);

	memset(F, 0x3f, sizeof F);

	//Pre
	IOR(i, 1, len1+1) {
		F[0][i] = i-1;
		int v = 1; 
		bool mk = 0;
		while(v <= len2) IOR(k, mk ? 1 : i, len1+1) 
			v += (S1[k] == S2[v]), F[0][i]++, mk = 1;
	}	
			
	//Dp
	int lmt = log2(n1 * len1 / len2);
	IOR(e, 1, lmt+1) IOR(i, 1, len1+1) 
		F[e][i] = 
			F[e-1][ F[e-1][i] ] + F[ e - 1 ][ (F[e-1][i] + i) % len1 ],
		printf("e = %d, i = %d, F = %d\n", 
				e, i, F[e][i]);

	//Ans
	IOR(i, 1, len1+1) {
		int tmp = 0, now = i;
		LOR(k, lmt, -1) if(i + F[k][i] <= len1 * n1) 
			i += F[k][i], tmp += k;
		ans = max(ans, tmp);
	}

	cout << (1 << ans) / n2;

	return 0;
} /**/


















