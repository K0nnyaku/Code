#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>

const int N=5e2+11;
const int MD=1e9+7;

//struct Ele {
//	int tp,sp,len;
//};
//
//Ele err={-1,-1,-1};
//
//#define _STACK_
//
//struct STK {
//	Ele a[N];
//	int hd;
//	
//	inline void push(Ele x) {
//		a[++hd]=x;
//	}
//	inline Ele pop() {
//		return 1<=hd?a[hd--]:err;
//	}
//	inline const Ele & top() {
//		return 1<=hd?a[hd]:err;
//	}
//} stk;
//
//#undef _STACK_

int n,k;
char s[N];
int a[N];
int ask[N],m;
bool zflag,qflag;

int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	srand(time(0)|104041);
	scanf("%d%d",&n,&k);
	scanf(" %s",s+1);
	for(int i=1;i<=n;i++) {
		if(s[i]=='*') a[i]=0;
		if(s[i]=='(') a[i]=1;
		if(s[i]==')') a[i]=2;
		if(s[i]=='?') {
			a[i]=3;
			ask[++m]=i; 
		}
	}
	// check the zero case
	zflag=n==0;
	for(int i=1,mcnt=0;i<=n && !zflag;i++) {
		if(!a[i]) mcnt++;
		else mcnt=0;
		if(k<mcnt) zflag=1;
	}
	if(zflag) {
		printf("0\n");
	}
	else if(m==0) {
		printf("1\n");
	}
	else {
		printf("%d\n",rand()%MD);
	}
	
	
	return 0;
}

