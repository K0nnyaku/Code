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

const int N_ = 50 + 7;
const int M_ = 1e5 + 7;

vector<int> Num[2], Mp[2];
int V[2][M_];
int n;
bool Fg[2];

namespace Sub3 { void Solve() { cout << 0 << "\n"; } }
namespace Sub4 { 
	bool p = 0;

	bool Chk(int x, int pos) {
		Ir(i, 0, n) 
			if(V[p^1][Num[p^1][i]] > 0 
					&& Num[p^1][i] != Mp[p][pos]) {
				V[p^1][Num[p^1][i]]--; return false;
			}
		return true;
	}

	void Solve() {
		p ^= !Fg[1];

		int ans = 0;
		Ir(i, 0, n) 
			ans += Chk(Num[p][i], i);
		cout << ans << "\n";
	}
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n;

	Ir(i, 0, n) {
		int x, y; IN >> x >> y;	

		Fg[0] = Fg[0] | (V[0][x]++);
		Fg[1] = Fg[1] | (V[1][y]++);
		Num[0].push_back(x), Num[1].push_back(y);
		Mp[0].push_back(y),  Mp[1].push_back(x);
	}

	if(!Fg[0] && !Fg[1]) Sub3::Solve();
	else Sub4::Solve();
//	if(!Fg[0] || !Fg[1]) Sub4::Solve();




	return 0;
} /**/











