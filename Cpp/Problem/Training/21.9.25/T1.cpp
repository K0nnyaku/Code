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

const int MAXN = 1e5 + 10;

int len, sum;
int A[MAXN];
char S[MAXN];
bool flag;

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
	
	scanf("%s", S); len = strlen(S);
	reverse(S, S+len);

	IOR(i, 0, len)  
		A[i] = S[i] - '0', sum += A[i], flag |= !A[i];

	if(sum % 3 or !flag) {
		cout << -1 << "\n";
		return 0;
	}
	IOR(i, 0, len) 
		if(A[i] == 0) {
			swap(A[0], A[i]);
			break;
		}

	sort(A+1, A+len);

	reverse(A, A+len);

	IOR(i, 0, len) cout << A[i];


} /**/

















