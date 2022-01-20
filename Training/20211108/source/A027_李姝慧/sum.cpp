#include<iostream>
#include<cstdio>
#include<cmath>
#define ri register int
using namespace std;
const int N=5e4+5;
int n;
long long a[N],mod=1e9+7,ans;
int read(){
	long long x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d",&n);
	for(ri i=1;i<=n;i++) a[i]=read();
	for(ri i=1;i<=n;i++){
		for(ri j=i+1;j<=n;j++){
			ans+=2*(a[i]^a[j])*(a[i]^a[j]);
			if(ans>mod) ans%=mod;
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
