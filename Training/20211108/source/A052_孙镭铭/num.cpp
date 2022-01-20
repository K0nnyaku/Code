#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<set>
#include<stack>
#include<algorithm>
#define ll long long
#define ull unsigned long long
using namespace std;
template<class T> void read(T &x){
	x=0;int w=0;char g=getchar();
	while(!isdigit(g)){w |=(g=='-');g=getchar();}
	while(isdigit(g)){x=(x<<3)+(x<<1)+(g xor 48);g=getchar();}
	x=w ?-x : x;
	return ;
}
int n,k;
long long a[75];
long long ans;
int main(){
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	read(n);read(k);
	for(int i=1;i<=n;i++)
		read(a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=k;i++)
		ans+=a[n/k*i]-a[n/k*(i-1)+1];
	printf("%lld",ans);
	return 0;
}
