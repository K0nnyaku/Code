#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int N=105;
int n,k,s[N],sh[N],c;
long long a[N],sum,yi[N],er[N],ans=1e9-1;
map<long long,map<long long,long long> > mapp;
void dfs(int x){
	if(x==n+1){
		sum=0;
		memset(yi,0x3f,sizeof(yi));
		for(int i=1;i<=n;i++) yi[sh[i]]=min(yi[sh[i]],a[i]),er[sh[i]]=max(er[sh[i]],a[i]);
		for(int i=1;i<=k;i++) sum+=er[i]-yi[i];
		ans=min(ans,sum);
	}
	for(int i=1;i<=k;i++){
		if(s[i]<c&&mapp[i][a[x]]==0) s[i]++,sh[x]=i,mapp[i][a[x]]=1,dfs(x+1),s[i]--,sh[x]=0,mapp[i][a[x]]=0;
	}
}
int main(){
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	scanf("%d%d",&n,&k);c=n/k;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	dfs(1);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
