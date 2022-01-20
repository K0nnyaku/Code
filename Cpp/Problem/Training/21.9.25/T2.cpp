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

const int MAXN = 1e4 + 10;

int A[MAXN];
int n, flag;

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
	IN >> n; 

	IOR(i, 1, n+1) 
		IN >> A[i], flag = (A[i] == 1 ? i : flag);

	IOR(i, 1, n+1) {
		int l = flag, r = flag;

		while(A[--l] <= i && l >= 1);
		while(A[++r] <= i && r <= n);

		printf("%d", r - l - 1 == i);
	}


} /**/







