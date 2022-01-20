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

const int _N = 50 + 10;

int A[_N<<1], B[_N<<1];
int t, n;
char Ans[_N<<1];
bool flag;

bool Check();
void Force(int pos, int l, int r);

int main() { /**/
//
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);

//	freopen("D:\\Data\\palin\\palin1.in", "r", stdin);
//////	freopen("D:\\Data\\palin\\palin.out", "w", stdout);


	IN >> t;
	while(t--) {
		IN >> n;
		memset(B, 0, sizeof B);
		flag = 0;
		IOR(i, 0, n << 1) 
			IN >> A[i];

		Force(0, 0, (n << 1) - 1);
		if(flag) {
			IOR(i, 0, n << 1) 
				cout << Ans[i];
			cout << "\n";
		}
		else
			cout << -1 << "\n";
	}
	return 0;
} /**/

bool Check() {
	for(int l = 0, r = (n << 1) - 1; l < r; l++, r--) 
		if(B[l] != B[r]) return false;
	return true;
}

void Force(int pos, int l, int r) {
	
	if(flag) return ;
	if(pos == n << 1) {
		flag = Check();
		return ;
	}

	if(!flag && l <= r) 
		Ans[pos] = 'L', B[pos] = A[l], Force(pos+1, l+1, r);
	if(!flag && l <= r) 
		Ans[pos] = 'R', B[pos] = A[r], Force(pos+1, l, r-1);
}

/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/












