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

const int N_ = 3e6 + 7;

template<int N>
struct LCT {
	int F[N], Q[N][2], C[N][2], T[N], Ed[N];

	void Cn(int x, int y, int p) { F[x] = y; C[y][p] = x; }
	void Rv(int x) { swap(C[x][0], C[x][1]); T[x] ^= 1; }

	void UpQ(int x) { Q[x][0] = C[x][0] [Q][0] + C[x][1] [Q][0] + Q[x][1] + Ed[x]; }
	void SpS(int x) {
		if(T[x]) {
			if(C[x][0]) Rv(C[x][0]);
			if(C[x][1]) Rv(C[x][1]);
			T[x] = 0;
		}
	}
#define Is(x) (x != C[F[x]][0] && x != C[F[x]][1])
#define W(x)  (x != C[F[x]][0])

	void Sp(int x) { while(!Is(x)) Sp(F[x]); SpS(x); }

	void Rot(int x) {
		int u = F[x], v = F[u], p = W(x), q = W(u);
		if(!Is(u)) Cn(x, v, q); else F[x] = v;
		Cn(C[x][p^1], u, p);	Cn(u, x, p^1);
		UpQ(u); 
	}

	void Sy(int x) {
		Sp(x);
		for(int y; y = F[x], !Is(x); Rot(x))
			if(!Is(y)) Rot(W(x) == W(y) ? y : x);
		UpQ(x);
	}

	void Acc(int x) {
		for(int y = 0; x; x = F[y=x])
			Sy(x), Q[x][1] += C[x][1] [Q][0] - C[y][0] [Q][1], C[x][1] = y, UpQ(x);
	}

	void CgRt(int x) { Acc(x); Sy(x); Rv(x); }

	void Split(int x, int y) { CgRt(x); Acc(y); Sy(y); }

	void Cut(int x, int y) {
		Split(x, y);
		if(F[x] == y && !C[x][1]) F[x] = C[y][0] = 0;
		else                      ERR;
		UpQ(x); UpQ(y);
	}

	void Link(int x, int y) {
		 Split(x, y);
		 if(!F[x]) F[x] = y, Q[y][1] += Q[x][0];
		 else      ERR;
		 UpQ(x); UpQ(y);
	}
};

LCT<N_<<1> Tr;
string S;
int Fl[N_<<1], En[N_<<1], Ch[N_<<1][2];
int cnt, las, q, mask;

void Extend(int c) {
	int p = las, u;
	En[las=u=++cnt] = En[p] + 1; Tr.Ed[u] = 1;
	while(p && !Ch[p][c]) Ch[p][c] = u, p = Fl[p];
	if(!p) Fl[u] = 1, Tr.Link(u, 1);
	else {
		int q = Ch[p][c];
		if(En[q] == En[p] + 1) Fl[u] = q, Tr.Link(u, q);
		else {
			int v = ++cnt;
			memcpy(Ch[v], Ch[q], sizeof Ch[q]);
			Tr.Link(v, Fl[q]);  Tr.Cut(p, Fl[p]);  Tr.Link(p, v); Tr.Link(u, v);
			Fl[v] = Fl[q]; En[v] = En[p] + 1; Fl[q] = Fl[u] = v;
			while(Ch[p][c] == q) Ch[p][c] = v, p = Fl[p];
		}
	}
}

string decodeWithMask(const string &s, int mask) {
	string chars = s;
	for (int j = 0; j < chars.size(); j++) 
		mask = (mask * 131 + j) % chars.size(),
		swap(chars[j], chars[mask]);
	return chars;
}

int Qy(string &x) {
	int p = 1;
	Ir(i, 0, x.size()) 
		if(Ch[p][x[i]-'A']) p = Ch[p][x[i]-'A'];
		else return 0;
	Tr.Sy(p);
	return Tr.Q[p][0];
}

int main() { /**/
#ifdef LOCAL
	freopen("/home/k0nnyaku/Code/Data/P5212_1.in", "r", stdin);
	freopen("/home/k0nnyaku/Code/Data/WA.out", "w", stdout);
#endif
	
	IN >> q; cin >> S; 

	cnt = las = 1;

	Ir(i, 0, S.size()) Extend(S[i]-'A');
	
	while(q--) {
		string Opt, X; cin >> Opt >> X;	
		X = decodeWithMask(X, mask);

		if(Opt == "ADD") Ir(i, 0, X.size()) Extend(X[i]-'A');
		else { int ans = Qy(X); cout << ans << "\n"; mask ^= ans; }
	}

	return 0;
} /**/



















