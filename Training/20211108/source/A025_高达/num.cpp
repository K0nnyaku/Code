#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k;
long long f[100],ans;
bool vis[100];
int main()
{
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&f[i]);
	sort(f+1,f+1+n);
	if(k==1){
		cout<<f[n]-f[1]<<endl;
		return 0;
	}
	if(k==n){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++){
		int cnt=0,tmp=0,op=0;
		bool flag=0;
		for(int j=1;j<=n;j++){
			if(vis[j]) continue;
			if(!flag)
				op=j,flag=true;
			vis[j]=1;
			cnt++;
			if(cnt==n/k){
				tmp=j;
				break;
			}
			int t=j+1;
			while(1){
				if(f[t]!=f[j])
					break;
				t++;
			}
			j=t-1;
		}
		//cout<<tmp<<' '<<op<<endl;
		ans+=f[tmp]-f[op];
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
