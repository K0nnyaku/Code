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

const int N_ = 1e5 + 7;

template<typename T, int N>
struct FenWickSS {
	struct FenWickPS {
		T A[N];	
		FenWickPS() { FL(A, 0); }
		T AkP(int x) {
			T res = 0;
			while(x) res += A[x], x -= x & -x;
			return res;
		}
		T AkS(int l, int r) { return AkP(r) - AkP(l-1); }
		void CgP(int x, T y) { while(x < N) A[x] += y, x += x & -x; }
	};

	FenWickPS S, C;
	T Sm[N];

	FenWickSS() { FL(Sm, 0); }
	
	T AkS(int l, int r) {
		return Sm[r] + (r+1) * S.AkP(r) - C.AkP(r) 
						- (Sm[l-1] + l * S.AkP(l-1) - C.AkP(l-1) );
	}
	void CgS(int l, int r, T v) {
		S.CgP(l, v);   S.CgP(r+1, -v);
		C.CgP(l, v*l); C.CgP(r+1, -(r+1)*v);
	}
	T& operator[](const int &x) { return Sm[x]; }
};


FenWickSS<long long, N_> Tr;
int n, m;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n >> m;
	IR(i, 1, n) {
		int x; IN >> x;
		Tr[i] = Tr[i-1] + x;
	}
	IR(i, 1, m) {
		int opt, x, y, k; 
		IN >> opt >> x >> y;
		if(opt == 1) {
			IN >> k;
			Tr.CgS(x, y, k);
		} 
		else cout << Tr.AkS(x, y) << "\n";
	}

	return 0;
} /**/












