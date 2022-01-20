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

template<int N, int M>
struct Edge {
	int I[N], Nt[M], To[M];
	int cnt;
	void Cl() { FL(I, 0); FL(Nt, 0); FL(To, 0); cnt = 1; }
	void AdI(int u, int v) { Nt[++cnt] = I[u]; To[I[u]=cnt] = v; }
};

Edge<N_, N_<<1> I; 

vector<int> Ans;
int W[N_], In[N_];
int t, n;

int FdRs(int x, int y) {
	int tmp = 0;

	ER(i,v,I,x,I) if(v != y) 
		tmp += FdRs(v, x);

	if(In[x] != 1) 
		return W[x] = tmp, tmp > 0 ? 1 : (tmp == 0 ? 0 : -1);
	return W[x];
}

void FdLf(int x, int y) {
	ER(i,v,I,x,I) if(v != y) FdLf(v, x);

	if(In[x] == 1 && !W[x]) Ans.push_back(x);		
}

void FdPt(int x, int y) {
	ER(i,v,I,x,I) if(v != y)
		if(W[v] == 0 || W[v] == -1) FdPt(v, x);
	if(In[x] == 1 && !W[x]) Ans.push_back(x);
}

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/rab/rab.in", "r", stdin);
	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> t;
	while(t--) {
		I.Cl(); Ans.clear();

		FL(W, 0); FL(In, 0); 

		IN >> n; IN >> W[0];
		In[1]++;
		IR(i, 2, n) { int x; IN >> x; I.AdI(i, x); I.AdI(x, i); In[x]++; In[i]++; }
		IR(i, 1, n) IN >> W[i], W[i] = W[i] ? (W[i]==1 ? -1 : 0) : 1;

		int rs = FdRs(1, 1);

		if(rs < 0) { cout << "-1\n"; continue; }

		if(rs == 1) FdLf(1, 1);
		else        FdPt(1, 1);

		sort(Ans.begin(), Ans.end());

		cout << Ans.size() << " ";

		Ir(i, 0, Ans.size()) 
			cout << Ans[i] << " ";
		cout << "\n";

	}

	return 0;
} /**/















