#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k) for(int i = v; i <= k; i++)
#define Ir(i, v, k) for(int i = v; i <  k; i++)
#define SR(i, v, k) for(int i = v; i >= k; i--)
#define Sr(i, v, k) for(int i = v-1; i >= k; i--)
#define ER(i, v, p, q, k) for(int i = p.k[q], v = p.To[i]; i; i = p.Nt[i], v = p.To[i])
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

const int N_ = 1e5 + 7;

map<unsigned long long, bool> Mp;
vector<int> Num;
int In[N_];
int n, ans;

template<int N, int M>
struct Edge {
	int I[N], Nt[M], To[M]; int cnt;
	Edge() { FL(I, 0); FL(Nt, 0); FL(To, 0); cnt = 1; }

	void AdI(int u, int v) { In[u]++; In[v]++; Nt[++cnt] = I[u]; To[I[u]=cnt] = v; } 
};

Edge<N_, N_<<1> I;

unsigned long long Turn(int l, int r) {
	unsigned long long res = 0;
	l--;

	/*
	printf("Turn:");
	Ir(i, l, r) printf("%d ", Num[i]);
	printf("Finish\n");
	*/

	for(int i = l, k = 13331; i < r; i++, k*=13331)
		res += Num[i] * k;
	return res;
}

void Force() {
	int t = Num.size();

	/*
	printf("\nBefor Force:\n");
	Ir(i, 0, t) cout << Num[i] << " ";
	printf("\n----------------\n");
	*/

	IR(i, 1, t) IR(v, 1, t-i+1) {
		unsigned long long tmp = Turn(v, v+i-1);
		if(!Mp[tmp]) ans++, Mp[tmp] = 1;
	}
}

void Solve(int x, int y) {
	Num.push_back(In[x]);
	
	int tmp = Num.size();

	ER(i,v,I,x,I) if(v != y) {
		Solve(v, x);
		while(Num.size() > tmp) Num.pop_back();
	}

	if(In[x] == 2) { Force(); }
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n;
	Ir(i, 1, n) {
		int u, v; IN >> u >> v;
		I.AdI(u, v); I.AdI(v, u);
	}

	Solve(1, 1);

	cout << ans << "\n";

	return 0;
} /**/













