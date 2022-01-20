#include<bits/stdc++.h>
using namespace std;

#define IOR(x, y, z) for(int x = y; x < z; x++)
#define LOR(x, y, z) for(int x = y; x > z; x--)
#define EOR(x, y) for(int x = Head[y]; x; x = E[x].next)

struct FastIN {
	template<typename T>
	FastIN& operator>>(T& x) {
		char c, l;
		for(c = 0; !isdigit(c); c = getchar()) l = c;
		for(x = 0; isdigit(c); c = getchar()) x = x * 10 + c - '0';
		if(l == '-') x = -x;
		return *this;
	}
} IN;

const int _N = 1e6 + 10;

struct Node {
	int l, r;
	Node(int _l = 0, int _r = 0) {
		l = _l; r = _r;
	}
	friend bool operator<(const Node &x, const Node &y) {
		return x.l == y.l ? x.r < y.r : x.l < y.l;
	}
} A[2][_N];

int n, inm, outm;

int Ask(int k, int x);

int main() {
//	freopen("D:\\Data\\airport\\airport3.in", "r", stdin);
//	freopen("D:\\Data\\airport\\out.out", "w", stdout);
//	
//	freopen("airport.in", "r", stdin);
//	freopen("airport.out", "w", stdout);

	IN >> n >> inm >> outm;
	
	IOR(i, 1, inm + 1)
		IN >> A[0][i].l >> A[0][i].r;
		
	IOR(i, 1, outm + 1)
		IN >> A[1][i].l >> A[1][i].r;
		
	if(n >= 1500) {
		printf("%d\n", max(inm, outm));
		return 0;
	}
	
	sort(A[0] + 1, A[0] + inm + 1);
	sort(A[1] + 1, A[1] + outm + 1);
	
	int ans = 0;
	
	IOR(i, 0, n+1) 
		ans = max(ans, Ask(0, i) + Ask(1, n-i));

	cout << ans << "\n";
	
	return 0;
}
 
int Ask(int k, int x) {
	priority_queue<int> Q;
	
	int lmt = (k == 0 ? inm : outm), res = 0;
	
	IOR(i, 1, lmt+1) {
		if(Q.size() < x) {
			Q.push(-A[k][i].r);
			res++;
		}
		else 
		if(Q.size() && -Q.top() < A[k][i].l) {
			Q.pop(); Q.push(-A[k][i].r);
			res++;
		}
	}
		
	return res;
}


/*
Case 1:

3 5 4
1 5 
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/

/*
Case 2:
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/











