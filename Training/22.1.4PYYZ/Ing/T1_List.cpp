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

const int N_ = 1e9;

int l, r, ans, block;
bool Vs[N_];

bool Chk(int x) {
	if(x == 1) return false;

	vector<int> Num; Num.clear();

	int sm = 0;
	while(x) { sm += x % 10; Num.push_back(x % 10); x /= 10; }

	if(sm % 2) return false;

	memset(Vs, 0, (sm+10)*sizeof(bool));

	Vs[0] = 1;
	Ir(i, 0, Num.size()) 
		SR(v, sm/2, Num[i]) {
			Vs[v] |= Vs[v-Num[i]];
			if(Vs[sm/2]) return true;
		}
	return false;
}

int L[N_<<1], R[N_<<1];
int sm;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	block = 1000000;

	for(int i = 1; i <= N_; i += block+1) {
		int res = 0;
		IR(v, i, i + block)	res += Chk(v);
		cout << res << ",";
	}

	return 0;
	sm = 0;
	for(int i = 1; i <= N_; i += block+1) { 
		L[++sm] = i; R[sm] = i + block; 
	}
	if(R[sm] < N_) sm++, L[sm] = R[sm-1] + 1, R[sm] = N_;
	
	IR(i, 1, sm) cout << L[i] << ",";

	cout << "0,";
	IR(i, 1, sm) cout << R[i] << ",";

	cout << sm << "\n";

	return 0;
} /**/













