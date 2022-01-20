#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define Ir(i, st, ed) for(int i = st; i < ed; i++)
#define SR(i, st, ed) for(int i = st; i >= ed; i--)
#define Sr(i, st, ed) for(int i = st; i > ed; i--)
#define ER(i, x) for(int i = Head[x]; i; i = E[i].next)

struct FastIN 
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c, l;
		for(c = 0; !isdigit(c); c = getchar() ) l = c;
		for(x = 0; isdigit(c); c = getchar() ) x = x * 10 - '0' + c;
		if(l == '-') x =- x;
		return *this;
	}
}IN;

const int N_ = 3e5 + 2;
const int K_ = 1e2 + 2;
const int INF = 0x3f3f3f3f;

int A[N_], F[N_][K_][2];
int n, k;

void Pre();

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#else
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
#endif
	IN >> n >> k;
	IR(i, 1, n) IN >> A[i];

	Pre();

	IR(i, 1, n) {
		long long ans = 0;

		IR(v, 0, k-1) {
			int l = v, r = k - v - 1;
			int p, q;

			if((!F[i][l][0] && l) || (!F[i][r][1] && r)) continue;

			if(!F[i][l][0]) p = i;
			else if(!F[i][l+1][0]) p = F[i][l][0];
			else p = F[i][l][0] - F[i][l+1][0];
			if(!l) p = i - F[i][1][0];

			if(!F[i][r][1]) q = n - i;
			else if(!F[i][r+1][1]) q = n - F[i][r][1] + 1;
			else q = F[i][r+1][1] - F[i][r][1];
			if(!r) q = F[i][1][1] ? F[i][1][1] - i : 1;

			ans += p * q;
		}
		cout << ans << " ";
	}

	return 0;
} /**/

void Pre() {

	IR(i, 1, n) {
		int cnt = 1;
		SR(v, i-1, 1 && cnt <= k) if(A[v] > A[i]) 
			F[i][cnt++][0] = v;
	}

	IR(i, 1, n)  {
		int cnt = 1;
		IR(v, i+1, n && cnt <= k) if(A[v] > A[i]) 
			F[i][cnt++][1] = v; 
	}
}

















