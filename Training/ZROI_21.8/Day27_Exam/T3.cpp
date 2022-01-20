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

const int MAXK = 10 + 10;
const int INF = 0x3f3f3f3f;

long long Num[MAXK];
long long n, k, ans = INF;

long long Check(int idx) {
	long long res = 0, x = n;
	LOR(i, idx, 0) {
		if(Num[i] > x) 
			continue;

		res += x / Num[i];	
		x %= Num[i];

		if(!x) 
			return res;
	}
}

void Wk(int step) {
	if(step > k) {
		ans = min(ans, Check(step-1));
//		if(ans == 12) {
//		printf("\n");
//		IOR(i, 1, step) 
//			printf("%d ", Num[i]);
//		printf("\n");
//
//		}
		return ;
	}

	IOR(i, 2, 6) {
		Num[step] = Num[step-1] * i;
		Wk(step+1);
	}
}


int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
//printf("st = %llu\n", clock());

	IN >> n >> k;
	Num[1] = 1;
	Wk(2);

	printf("%lld\n", ans);

//printf("ed = %llu\n", clock());

	return 0;
} /**/