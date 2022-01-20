#include<iostream>
#include<cstdio>
#include<algorithm>
#define mod 1000000007
using namespace std;
int n;
long long f[50010],ans;
bool flag=0;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&f[i]);
		ans=(ans+((f[i]^f[i])*(f[i]*f[i]))%mod)%mod;
		if(f[i]!=f[1])
			flag=1;
	}
	if(!flag){
		cout<<0<<endl;
		return 0;
	}
	if(n<=3000){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j)
					ans=(ans+((f[i]^f[j])*(f[i]^f[j]))%mod)%mod;
		cout<<ans%mod<<endl;
	}
	else{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				ans=(ans+((f[i]^f[j])*(f[i]^f[j]))%mod)%mod;
				ans=(ans+((f[i]^f[j])*(f[i]^f[j]))%mod)%mod;
			}
		cout<<ans%mod<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
