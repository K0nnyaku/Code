#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stack>
#include<cstring>
#include<string>
#include<map>
#include<queue>
using namespace std;
const int maxn=100005;
int n,m1,m2;
int end[maxn],cnt[maxn],end2[maxn],cnt2[maxn],sum[maxn],sum2[maxn];
struct node{
	int st,en;
};
node pla[maxn],pla2[maxn];
bool cmp(node x,node y){
	return x.st<y.st;
}
priority_queue<int>q;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	int tot=0;
	for(int i=1;i<=m1;i++)scanf("%d%d",&pla[i].st,&pla[i].en);
	for(int i=1;i<=m2;i++)scanf("%d%d",&pla2[i].st,&pla2[i].en);
	sort(pla+1,pla+1+m1,cmp);
	sort(pla2+1,pla2+1+m2,cmp);
	for(int i=1;i<=m1;i++){
		int k,flag=0;
		for(int j=1;j<=tot;j++){
			if(end[j]<pla[i].st){
				k=j;
				flag=1;
				break;
			}
		}
		if(flag==0){
			tot++;
			end[tot]=pla[i].en;
			cnt[tot]=1;
		}else{
			end[k]=pla[i].en;
			cnt[k]++;
		}
	}
	int tot2=0;
	for(int i=1;i<=m2;i++){
		int k,flag=0;
		for(int j=1;j<=tot2;j++){
			if(end2[j]<pla2[i].st){
				k=j;
				flag=1;
				break;
			}
		}
		if(flag==0){
			tot2++;
			end2[tot2]=pla2[i].en;
			cnt2[tot2]=1;
		}else{
			end2[k]=pla2[i].en;
			cnt2[k]++;
		}
	}
	int ans=-1;
	int x=1,y=1;
	for(int i=1;i<=m1;i++)sum[i]=sum[i-1]+cnt[i];
	for(int i=1;i<=m2;i++)sum2[i]=sum2[i-1]+cnt2[i];
	for(int i=0;i<=n;i++){
		ans=max(ans,sum[i]+sum[n-i]);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

