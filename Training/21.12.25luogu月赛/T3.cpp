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

int n;

int Chk(int x);

int main() { /**/
	IN >> n;
	int l = 1, r = n;
	while(l < r) {
		int mid = (l + r) >> 1, res = Chk(mid);

		if(res == 0) l = mid + 1;
		else
		if(res == 2) r = mid;
		else {
			printf("! %d\n", mid);
			fflush(stdout);
			return 0;
		}
	}

	printf("! %d\n", l);
	fflush(stdout);

	return 0;
} /**/

int Chk(int x) {
	printf("? %d %d\n", x, x);
	fflush(stdout);
	int u, v; IN >> u >> v;
	return v;
}










