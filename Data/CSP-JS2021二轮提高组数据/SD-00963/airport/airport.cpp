#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
struct node{
	ll arr,lee;
	int sum;
}a1[100001],a2[100001];
int sum1[100001],sum2[100001];
int tot;
int n,m1,m2,ans;
ll x,y;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		int flag=0;
		scanf("%lld%lld",&x,&y);
		for(int i=1;i<=tot;i++){
			if(a1[i].lee<x){
				a1[i].lee=y;
				a1[i].sum++;
				flag=1;
				break;
			}
		}
		if(!flag) a1[++tot].arr=x,a1[tot].lee=y,a1[tot].sum++;
	}
	for(int i=1;i<=tot;i++) sum1[i]=sum1[i-1]+a1[i].sum;
	tot=0;
	for(int i=1;i<=m2;i++){
		int flag=0;
		scanf("%lld%lld",&x,&y);
		for(int i=1;i<=tot;i++){
			if(a2[i].lee<x){
				a2[i].lee=y;
				a2[i].sum++;
				flag=1;
				break;
			}
		}
		if(!flag) a2[++tot].arr=x,a2[tot].lee=y,a2[tot].sum++;
	}
	for(int i=1;i<=tot;i++) sum2[i]=sum2[i-1]+a2[i].sum;
	for(int i=1;i<=n;i++){
		ans=max(ans,sum1[i]+sum2[n-i]);
	}
	printf("%d\n",ans);
	//fclose(stdin);
	//fclose(stdout);	
    return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16

7
*/
