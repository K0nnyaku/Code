#include<iostream>
#include<cstdio> 
#include<algorithm>
#define MAXN 100100 
using namespace std;
int n,m1,m2;
struct node{
	long long a1,b1;
	bool vis=0;
}gn[MAXN];
struct NODE{
	long long a2,b2;
	bool viss=0;
}gj[MAXN];
int t=1,p;
int ans,a[100010],b[100010];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%lld%lld",&gn[i].a1,&gn[i].b1);
	for(int i=1;i<=m2;i++)
		scanf("%lld%lld",&gj[i].a2,&gj[i].b2);
	if(m1+m2<=n){
		printf("%d\n",m1+m2);
		return 0;
	}
	while(t<=n){
		p=0;
		for(int i=1;i<=m1;i++)
			if(gn[i].a1>=gn[p].b1&&gn[i].vis==0)
				a[t]++,gn[i].vis=1,p=i;
		t++;
	}
	t=1;
	while(t<=n){
		p=0;
		for(int i=1;i<=m2;i++)
			if(gj[i].a2>=gj[p].b2&&gj[i].viss==0)
				b[t]++,gj[i].viss=1,p=i;
		t++;
	}
	
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
		b[i]+=b[i-1];
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,a[i]+b[n-i]);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
