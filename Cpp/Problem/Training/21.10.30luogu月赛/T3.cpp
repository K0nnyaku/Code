#include<bits/stdc++.h>
using namespace std;

#define IR(i, st, ed) for(int i = st; i <= ed; i++)
#define LR(i, st, ed) for(int i = st; i >= ed; i--)
#define ER(i, x) for(int i = Head[x]; i; i = E[i].next)

struct FastIN
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getchar())l=c;
		for(x=0;isdigit(c);c=getchar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;

const int N_ = 5e3 + 2;

struct Node {
	int l, r;
	bool opt;
	Node(int l_ = 0, int r_ = 0, int opt_ = 0) {
		l = l_, r = r_, opt = opt_;
	}
} Ansa[N_], Ansb[N_];

char A[N_];
int n, acnt, bcnt;

int main() { /**/
#ifdef LOCAL
	freopen("I:/Code/Data/In.in", "r", stdin);
	freopen("I:/Code/Data/AC.out", "w", stdout);
#endif
	IN >> n;
	scanf("%s", A+1);

	bool flag = 0;
	IR(i, 1, n) if(A[i] != 'A') flag = 1;

	if(!flag) {
		cout << n / 2 << "\n";
		IR(i, 1, n-1) 
			i++,
			cout << i << " " << i << " BAA" << "\n";
		return 0;
	}

	flag = 0;
	IR(i, 1, n) if(A[i] == A[i-1]) flag = 1;
	if(!flag) {
		cout << 0 << "\n";
		return 0;
	}

	flag = 0;
	IR(i, 1, n) if(A[i] == 'C') flag = 1;
	if(!flag) {
		int atmp = 0, btmp = 0;
		char Sa[n+2], Sb[n+2];	
		IR(i, 1, n) 
			Sa[i] = i % 2 ? 'A' : 'B';
		IR(i, 1, n) 
			Sb[i] = i % 2 ? 'B' : 'A';

//		IR(i, 1, n) 


		return 0;
	}


	return 0;
} /**/















