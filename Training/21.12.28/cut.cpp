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


namespace Sub1 {

const int N_ = 20 + 3;
const int M_ = 50 + 3;
const int L_ = 32 + 3;

struct Edge {
	long long v, x, y; 
	Edge(int x_ = 0, int y_ = 0, int v_ = 0) { x = x_; y = y_; v = v_; }
};

Edge I[M_];
long long E[L_];
long long n, m, nw;

long long Solve(int x);
long long Chk(long long x, int k);
long long Turn(char *S);
void Nrut(long long x);

void Work() {
	E[0] = 1;
	Ir(i, 1, L_) E[i] = E[i-1] * 2;

	IN >> n >> m;
	IR(i, 1, m) {
		long long x, y, w; char S[N_];        
		IN >> x >> y; scanf("%s", S);
		w = Turn(S);
		I[i] = Edge(x, y, w);
		nw |= (1 << x-1); nw |= (1 << y-1);
		Nrut(Solve(i));
	}

}

long long Turn(char *S) {
	long long res = 0;
	int len = strlen(S);

	Ir(i, 0, len) res += (S[i] == '1') * E[len-i-1];
	return res;
}

long long Solve(int k) {
	long long res = -1;
	for(long long i = nw; i >= 0; i--) {
		i &= nw;
		if(i < 0) break;
		res = max(res, Chk(i, k));
	}
	return res;
}

long long Chk(long long x, int k) {
	long long res = 0;
	IR(i, 1, k) {
		if((x & (1 << I[i].x-1)) ^ (x & (1 << I[i].y-1))) res ^= I[i].v;
	}
	return res;
}

void Nrut(long long x) {
	stack<int> Sk;
	while(x) {
		Sk.push(x % 2);
		x /= 2;
	}
	if(!Sk.size()) cout << 0;
	while(Sk.size())
		cout << Sk.top(), Sk.pop();
	cout << "\n";
}

}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#else 
	freopen("cut.in",  "r", stdin);
	freopen("cut.out", "w", stdout);
#endif
	Sub1::Work();

	return 0;
} /**/



