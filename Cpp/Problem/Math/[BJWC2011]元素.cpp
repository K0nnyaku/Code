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

const int N_ = 1e3 + 3;
const int L_ = 60;

struct Node {
	long long x, y;
	Node(long long x_ = 0, long long y_ = 0) { x = x_; y = y_; }
	friend bool operator<(const Node &x, const Node &y) { return x.y > y.y; }
};

Node A[N_];
long long Lb[N_];
int n;

bool Ins(long long x);

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n;
	IR(i, 1, n) IN >> A[i].x >> A[i].y;

	sort(A+1, A+n+1);

	long long ans = 0;
	IR(i, 1, n) 
		if(Ins(A[i].x)) ans += A[i].y;

	cout << ans << "\n";

	return 0;
} /**/

bool Ins(long long x) {
	Sr(i, L_, 0) {
		if(!(x >> i)) continue;
		if(!Lb[i]) { Lb[i] = x; return true; }
		x ^= Lb[i];
	}
	return false;
}







