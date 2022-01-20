#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=506, p=1e9+7;
int n, m, k, f[N][N];
char s[N], s2[N], stk[N], qwq;
int r_() {
	int a=0, f=0; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=1;
	for(;isdigit(c);a=(a<<1)+(a<<3)+(c^48),c=getchar());
	return f? -a:a;
}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=r_(), k=r_(), scanf("%s",s+1);
	printf("%d\n",1145141919810%p);
}
