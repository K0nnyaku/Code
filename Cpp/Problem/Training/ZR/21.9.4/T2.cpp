#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);
#define T(x) E[x].to
#define V(x) E[x].val

const int MB=1<<21;
struct FastIN
{
	char buf[MB+100],*p,*e;
	int getChar()
	{
		if(p==e) p=buf,e=buf+fread(buf,1,MB,stdin);
		return p==e?EOF:*p++;
	}
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;
//

const int MAXL = 10 + 10;

vector<int> A[MAXL];
int len;
char S[MAXL];

int Count(int x);
bool Check(int x);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
	scanf("%s", S); len = strlen(S);

	IOR(i, 0, 1 << len) 
		A[Count(i)].push_back(i);
	
	IOR(i, 0, len + 1) 
		IOR(v, 0, A[i].size()) 
			if(Check(A[i][v])) {
				printf("%d\n", i);
				goto END;
			}
//	printf("%d\n", Check(64));

	END: ;

	return 0;
} /**/

int Count(int x) {
	int res = 0;
	IOR(i, 0, len) 
		res += ((x >> i) & 1);
	return res;
}

bool Check(int x) {

/*
	printf("\n-------------\n");
	IOR(i, 0, len) 
		printf("%d ", (x >> i) & 1);
		printf("\n%d\n", x);
	printf("\n-------------\n");
*/
	
	IOR(i, 0, len) {
		IOR(v, i, len && ((x >> v) & 1)) i = v;

		int l = i, r;
		for(r = l; r < len && !((x >> r) & 1); r++) i = r + 1;

//		printf("%d %d\n", l, r);

		stack<char> Sk;
		IOR(v, l, r) 
			if(S[v] == 'P') 
				if(Sk.size()) Sk.pop();
				else Sk.push('P');
			else 
				Sk.push('A');

		if(Sk.size()) return false;
	}
	return true;
}
