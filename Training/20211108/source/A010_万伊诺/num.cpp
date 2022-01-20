#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#define ll long long
using namespace std;
map<int,map<int,int> > vis;
int n,k,z;
ll a[100],cun[100][100],ans=-1,dan,sum[100];
inline void dfs(int t){
	if(t>n){
		dan=0;
		for(int i=1;i<=k;i++){
			sort(cun[i]+1,cun[i]+1+z);
			dan+=cun[i][z]-cun[i][1];
		}
		if(ans==-1) ans=dan;
		else ans=min(ans,dan);
		return;
	}
	for(int i=1;i<=k;i++){
		if(sum[i]<z&&vis[i][a[t]]==0){
			sum[i]++;
			vis[i][a[t]]++;
			cun[i][sum[i]]=a[t];
			dfs(t+1);
			sum[i]--;
			vis[i][a[t]]--;
		}
	}
}
int main()
{
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	scanf("%d%d",&n,&k);
	z=n/k;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	dfs(1);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
