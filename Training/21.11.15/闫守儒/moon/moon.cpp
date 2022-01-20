#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k) for(int i = v; i <= k; i++)
#define Ir(i, v, k) for(int i = v; i <  k; i++)
#define SR(i, v, k) for(int i = v; i >= k; i--)
#define Sr(i, v, k) for(int i = v-1; i >= k; i--)
#define ER(i, v, p, q, k) for(int i = p.k[q], v = p.To[i]; i; i = p.Nt[i], v = p.To[i])
#define FL(x, y) memset(x, y, sizeof x)

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

const int N_ = 1e5 + 2;
const int BK_ = 500 + 2;
const int P = 1e9 + 7;
const long long INF = 1e18 + 10;

long long A[N_]; 
int n, q;

void Pre();

namespace Sub1 {
	void Work() { 
		while(q--) {
			int op, l, r, x;
			IN >> op;
			if(op == 1) {
				IN >> l >> r >> x;
				IR(i, l, r) if(A[i] <= x) A[i] += x;
			}
			else
			if(op == 2) {
				IN >> l >> r;
				long long res = 0;
				IR(i, l, r) res += A[i], res %= P;
				cout << res << "\n";
			}
			else
			if(op == 3) {
				IN >> l >> r >> x;
				int res = 0;
				IR(i, l, r) res += A[i] <= x;
				cout << res << "\n";
			}
		}
	}
}
namespace Sub2 {
	vector<long long> Vc[BK_];
	long long Ps[N_], L[N_], R[N_], Sm[N_];
	int bk;

	void Work(); 
	void Pre();
	int AskNm(int l, int r, long long x);
	long long AskSm(int l, int r);

	void Work() {
		Pre();
		/*
		IR(i, 1, bk) {
			printf("bk = %d, l = %d, r = %d\n", i, L[i], R[i]);
			Ir(v, 0, Vc[i].size())
				cout << Vc[i][v] << " ";
			cout << "\n";
			cout << Sm[i] << "\n";
		}
		*/
		while(q--) {
			int op, l, r; long long x;
			IN >> op;
			if(op == 2) {
				IN >> l >> r;
				cout << AskSm(l, r) << "\n";
			}
			else {
				IN >> l >> r >> x;
				cout << AskNm(l, r, x) << "\n";
			}
		}
	}

	void Pre() {
		bk = sqrt(n);
		IR(i, 1, bk)
			L[i] = (i - 1) * bk + 1, 
			R[i] = i * bk;
		if(R[bk] < n) bk++, L[bk] = R[bk-1]+1, R[bk] = n;
		
		IR(i, 1, bk) IR(v, L[i], R[i]) 
			Sm[i] += A[v], Sm[i] %= P, 
			Ps[v] = i, Vc[i].push_back(A[v]);

		IR(i, 1, bk) 
			sort(Vc[i].begin(), Vc[i].end());
	}

	long long AskSm(int l, int r) {
		long long res = 0;
		int p = Ps[l], q = Ps[r];
		if(p == q) {
			IR(i, l, r) res += A[i], res %= P;
			return res;	
		}

		Ir(i, p+1, q) 
			res += Sm[i], res %= P;
		IR(i, l, R[p]) res += A[i], res %= P;
		IR(i, L[q], r) res += A[i], res %= P;

		return res;
	}

	int AskNm(int l, int r, long long x) {
		int p = Ps[l], q = Ps[r], res = 0;

		if(p == q) {
			IR(i, l, r) res += A[i] <= x;
			return res;
		}

		Ir(i, p+1, q) {
			auto it = lower_bound(Vc[i].begin(), Vc[i].end(), x+1);
			res += it - Vc[i].begin();
		}
		IR(i, l, R[p]) res += A[i] <= x;
//			printf("i = %d, A[i] = %d, res = %d\n", i, A[i], res);
		IR(i, L[q], r) res += A[i] <= x;

		return res;
	}
}
namespace Sub3 { };


int main() { /**/
#ifdef LOCAL
//	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/moon3.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#else
	freopen("moon.in", "r", stdin);
	freopen("moon.out", "w", stdout);
#endif
	IN >> n >> q;
	IR(i, 1, n) IN >> A[i];

	if(n <= 5e3) Sub1::Work();
	else Sub2::Work();

	return 0;
} /**/












