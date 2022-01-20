#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <= k; i++)
#define Ir(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <  k; i++)
#define SR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i >= k; i--)
#define Sr(i, v, k, ...) for(int i = v-1, ##__VA_ARGS__; i >= k; i--)
#define ER(i, v, p, q, k, ...) for(int  i = p.k[q], v = p.To[i], ##__VA_ARGS__; i; i = p.Nt[i], v = p.To[i])
#define Er(i, v, p, q, k, ...) for(int &i = p.k[q], v = p.To[i], ##__VA_ARGS__; i; i = p.Nt[i], v = p.To[i])
#define FL(x, y) memset(x, y, sizeof x)
#define DG(x) cout << "Debug: " << #x << "=" << x << "\n"
#define ERR   cout << "Fuck\n"

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

struct Node {
	int l, r;
	Node(int l_ = 0, int r_ = 0) { l = l_; r = r_; }
	friend bool operator<(const Node &x, const Node &y) {
		return (x.l > y.l && x.l < y.r) ^ (x.r > y.l && x.r < y.r); }
};

const int N_ = 1e3 + 7;
const int C_ = 1e5 + 7;
const int P = 1e9 + 7;

vector<Node> A[C_];
vector<int> Col[C_], S;
long long ans;
int n;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n;
	IR(i, 1, n) {
		int x; IN >> x;
		Col[x].push_back(i);
		S.push_back(x);
	}

	sort(S.begin(), S.end());

	int cnt = unique(S.begin(), S.end()) - S.begin();

	Ir(i, 0, cnt) Ir(v, 0, Col[S[i]].size()) Ir(k, v+1, Col[S[i]].size()) 
		A[S[i]].push_back(Node(Col[S[i]][v], Col[S[i]][k]));

	Ir(p, 0, cnt) Ir(u, 0, A[S[p]].size()) 
		Ir(q, p+1, cnt) Ir(v, 0, A[S[q]].size()) ans += A[S[p]][u] < A[S[q]][v], ans %= P;

	cout << ans << "\n";

	return 0;
} /**/














