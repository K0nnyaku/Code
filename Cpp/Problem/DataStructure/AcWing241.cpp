#include<bits/stdc++.h>
using namespace std;

#define IOR(x, y, z) for(int x = y; x < z; x++)
#define LOR(x, y, z) for(int x = y; x > z; x--)

struct FastIN {
	template<typename T>
	FastIN& operator >>(T& x) {
		char l, c;
		for(c = 0; !isdigit(c); c = getchar()) l = c;
		for(x = 0; isdigit(c); c = getchar()) x = x * 10 + c - '0'; 
		if(l == '-') x = -x;
		return *this;
	}
}IN;

const int MAXN = 2e5 + 10;
const int MAXV = 2e5 + 10;

struct Bit {
	int Tr[MAXN<<2];

	void Clear();
	void Change(int x, int y);
	void Init();
	int Ask(int l, int r);
};

Bit Bt;
long long Ic[MAXN], Dw[MAXN], A[MAXN];
long long n, ans;

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
//	freopen("Out.out", "w", stdout);
#endif

	IN >> n;

	IOR(i, 1, n+1) 
		IN >> A[i];

	IOR(i, 1, n+1) {
		Bt.Change(A[i], 1);
		Ic[i] = Bt.Ask(A[i] + 1, n);
	}

	Bt.Clear();
	LOR(i, n, 0) {
		Bt.Change(A[i], 1);
		Dw[i] = Bt.Ask(A[i] + 1, n);
	}

	IOR(i, 2, n) 
		ans += Ic[i] * Dw[i]; 

	cout << ans << " ";

	memset(Ic, 0, sizeof Ic);
	memset(Dw, 0, sizeof Dw);
	ans = 0;

	Bt.Clear();
	IOR(i, 1, n+1) {
		Bt.Change(A[i], 1);
		Ic[i] = Bt.Ask(1, A[i]-1);
	}

	Bt.Clear();
	LOR(i, n, 0) {
		Bt.Change(A[i], 1);
		Dw[i] = Bt.Ask(1, A[i] - 1);
	}

	IOR(i, 2, n) 
		ans += Ic[i] * Dw[i]; 

	cout << ans;

	return 0;
} /**/

void Bit::Clear() {
	memset(Tr, 0, sizeof Tr);
}

int Bit::Ask(int l, int r) {
	l--; int ans = 0;
	while(l < r) ans += Tr[r], r -= (r & -r);
	while(l > r) ans -= Tr[l], l -= (l & -l);
	return ans;
}

void Bit::Change(int x, int v) {
	while(x <= n) 
		Tr[x] += v, x += x & -x; 
}

void Bit::Init() {
	IOR(i, 1, n+1) if(i + (i & -i) <= n) 
		Tr[i + (i & - i)] += Tr[i];
}














