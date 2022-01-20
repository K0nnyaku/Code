---
title: AcWing375 蚂蚁
date: 2021-11-12 10:53:02
tags: [二分图, 二分图匹配, 二分图带权匹配, 网络流, 费用流, Dinic, Spfa]
---

### [AcWing375](https://www.acwing.com/problem/content/description/377/)

### 注意

* #### 实数比较 
* #### 曼哈顿距离

### 代码
```cpp
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

const int N_ = 4e2 + 2;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-17;

template<typename T, int N, int M>
struct Edge {
	int Nt[M << 1], To[M << 1], I[N], H[N]; int cnt;
	double W[M << 1];
	T C[M << 1];
	Edge() { FL(Nt, 0); FL(To, 0); FL(I, 0); FL(H, 0); FL(W, 0); FL(C, 0); cnt = 1; }
	void AdI(int u, int v, int c, double w) {
		Nt[++cnt] = I[u]; To[cnt] = v; C[cnt] = c; W[I[u] = cnt] = w; 
		Nt[++cnt] = I[v]; To[cnt] = u; C[cnt] = 0; W[I[v] = cnt] = -w; 
	}
};

struct { int x, y; } A[N_<<1];
Edge<int, N_, N_*N_> I;
double Far[N_];
int n, s, t, ans;
bool Vv[N_], Vq[N_];

double Dis(int x, int y);
int Dic(int x, int fl);
bool Spfa();

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
//	freopen("I:/Code/Data/WA.out", "w", stdout);
#endif
	IN >> n;
	IR(i, 1, n<<1) IN >> A[i].x >> A[i].y;

	IR(i, 1, n) IR(v, n+1, n<<1) 
		I.AdI(i, v, 1, Dis(i, v));

	s = 0, t = (n << 1) + 1;
	IR(i, 1, n)		 I.AdI(s, i, 1, 0);
	IR(i, n+1, n<<1) I.AdI(i, t, 1, 0);

	while(Spfa()) 
		FL(Vv, 0), Dic(s, INF);
	
	IR(i,1,n) ER(v,k,I,i,I) if(!I.C[v] && k != s) { cout << k-n << "\n"; break; }

	return 0;
} /**/

double Dis(int x, int y) { return sqrt( pow(A[x].x - A[y].x, 2) + pow(A[x].y- A[y].y, 2) ); }

bool Spfa() {
	queue<int> Q;   Q.push(s);

	Ir(i, 1, N_) Far[i] = INF;

	Far[s] = 0;
	FL(Vq, 0);	     Vq[s] = 1; 
	I.H[s] = I.I[s];

	while(!Q.empty()) {
		int tp = Q.front(); Q.pop();
		Vq[tp] = 0;

		ER(i,v,I,tp,I) {
			if(Far[tp] + I.W[i] - Far[v] < EPS && abs(Far[tp]+I.W[i]-Far[v]) > EPS && I.C[i]) {
				Far[v] = Far[tp] + I.W[i];
				I.H[v] = I.I[v];
				if(!Vq[v]) Q.push(v), Vq[v] = 1;
			}
		}
	}

	return abs(Far[t]-INF) > EPS;
}

int Dic(int x, int fl) {
	if(x == t) return fl;
	int res = fl; Vv[x] = 1;

	ER(i,v,I,x,H) {
		if(abs(Far[x]+I.W[i]-Far[v])<=EPS && I.C[i] && !Vv[v]) {
			int k = Dic(v, min(fl, I.C[i]));

			I.H[x] = i;  ans += k * I.W[i];
			I.C[i] -= k, I.C[i^1] += k; res -= k;

			if(!res) return fl;
			if(!k) Far[v] = 0;
		}
	}
	Vv[x] = 0;
	return fl - res;
}
```
