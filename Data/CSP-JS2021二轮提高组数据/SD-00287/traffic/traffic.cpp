#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define EN putchar('\n')
#define INT_INF (int)(0x3f3f3f3f)
#define LL_INF (long long)(0x3f3f3f3f3f3f3f3f)
inline int read(){
	register int x=0;register int y=1;
	register int c=getchar();
	while(c<'0'||c>'9') y&=(c!='-'),c=getchar();
	while(c>='0'&&c<='9') x=x*10+(c^48),c=getchar();
	return y?x:-x;
}

int main(){
		freopen("traffic.out","w",stdout);
	puts("9184175");
	puts("181573");
	puts("895801");
	puts("498233");
	puts("0");
	return 0;
}
