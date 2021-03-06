#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define T(x) E[x].to
#define V(x) E[x].val

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

const int MAXN = 4 + 10;
const int MAXL = 30 + 10;

string S;
int Ans[MAXN];
int len, idx;
bool flag;

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif

    cin >> S;
	S[S.size()] = '-';
    char c;
	IOR(i, 0, 4) {
		int x, v = 0;
		if(i == 0) c = S[idx++];

		for(v = i != 0; !isdigit(c) || c == '0'; c = S[idx++], v++)
			if(c != '.' || v > 1 || i == 0) flag = 1;
		for(x = 0; isdigit(c); c = S[idx++]) x = x * 10 + c - '0';

		Ans[i] = x <= 255 ? x : 255;
		flag |= x > 255;
	}

	if(!flag && S[idx-1] == '-') {
		printf("YES\n");
		return 0;
	}

	printf("NO\n");
	IOR(i, 0, 3) 
		printf("%d.", Ans[i]);
	printf("%d", Ans[3]);

	return 0;
} /**/