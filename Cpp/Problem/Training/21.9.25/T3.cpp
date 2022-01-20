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

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif

} /**/
