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
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;

const int MAXN = 1e3 + 10;

int Mp[MAXN][MAXN];
int n, x, lfx, lfy, rtx, rty;

bool Check_Illegal();

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
#endif

	IN >> n >> x;

	IOR(i, 1, n+1) {
		int a, b; IN >> a >> b;
		lfx = min(lfx, a), lfy = min(lfy, b);
		rtx = max(rtx, a), rty = max(rty, b);

		if(Check_Illegal()) {
			cout << "illegal\n";
			return 0;
		}

		int res = Check_Win();
		if(res == 1) {
			cout << "Alice " << i << "\n";
			return 0;
		}

		if(res == 2) {
			cout << "Bob" << i << "\n";
			return 0;
		}
	}

	cout << "draw\n";

	return 0;
} /**/














