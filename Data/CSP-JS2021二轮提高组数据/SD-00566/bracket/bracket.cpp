#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=1e9+7;
long long n,k;
char s[505];
long long mul(long long a,long long b,long long p){
	long long ans=1,tes=a;
	while(b){
		if(b&1)	ans=ans*tes%p;
		tes=tes*tes%p;
		b>>=1;
	}
	return ans;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%c",s[i]);
	printf("%lld\n",mul(2,n-2,mod)-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

