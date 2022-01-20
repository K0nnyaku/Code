//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define IOR(x, y, z) for(int x = y; x < z; x++)
#define LOR(x, y, z) for(int x = y; x > z; x--)
#define EOR(x, y) for(int x = Head[y]; x; x = E[x].next)
#define V(i) E[i].val
#define T(i) E[i].to

struct FastIN {
	template<typename T>	
	FastIN& operator>>(T& x) {
		char l, c;
		for(c = 0; !isdigit(c); c = getchar()) l = c;
		for(x = 0; isdigit(c); c = getchar()) x = x * 10 + c - '0';
		if(l == '-') x = -x;
		return *this;
	}
} IN; 

const int _N = 1e2 + 2;
const int _V = 1e3 + 2;
const int _K = 30 + 2;

int F[_V][_K], C[_N], V[_N];
int n, rk, b, T;

int main() {
#ifdef LOCAL
	freopen("I:/Code/In.in", "r", stdin);
	freopen("I:/Code/WA.out", "w", stdout);
#endif 
	IN >> T;
	while(T--) {
		IN >> n >> b >> rk;

		memset(F, 0, sizeof F);
		memset(V, 0, sizeof V);
		memset(C, 0, sizeof C);

		IOR(i, 1, n+1) IN >> V[i];
		IOR(i, 1, n+1) IN >> C[i];

		IOR(i, 1, n+1) LOR(v, b, C[i]-1) {
			int q = 1, p = 1, cnt = 0;
			int Tmp[_K];

			while(q <= rk && p <= rk && cnt < rk << 1) {
				if(F[v][q] >= F[v-C[i]][p] + V[i]) 
					Tmp[++cnt] = F[v][q++];
				else
					Tmp[++cnt] = F[v-C[i]][p++] + V[i];
				cout << v - C[i] << "!!!\n";
			}

			cout << "-------------------------\n";
			IOR(i, 1, (rk << 1) + 1) 
				printf("Tmp[%d] = %d ", i, Tmp[i]);
			cout << "\n";

			while(q <= rk) Tmp[++cnt] = F[v][q++];
			while(p <= rk) Tmp[++cnt] = F[v-C[i]][p++] + V[i];

			cout << "-------------------------\n";
			IOR(i, 1, (rk << 1) + 1) 
				printf("Tmp[%d] = %d ", i, Tmp[i]);
			cout << "\n";

			unique(Tmp + 1, Tmp + (rk << 1) + 2);

			IOR(k, 1, rk+1) F[v][k] = Tmp[k];
		}

		IOR(i, 1, rk+1) 
			printf("F[b][%d] = %d ", i, F[b][i]);
		cout << "\n";

		cout << F[b][rk] << "\n";
	}

	return 0;
}










