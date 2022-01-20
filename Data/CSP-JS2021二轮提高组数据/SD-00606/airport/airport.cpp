#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
using namespace std;
int n,m,mm,a,b,wei[N],cnt=0,ans[N],anss[N],p,cntt=0,dan=0;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	memset(wei,0,sizeof(wei));
	memset(ans,0,sizeof(ans));
	memset(anss,0,sizeof(anss));
	scanf("%d%d%d",&n,&m,&mm);
	if(n>=m+mm){
		printf("%d\n",m+mm);
		return 0;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		p=-1;
		for(int j=1;j<=cnt;j++){
			if(wei[j]<a){
				p=j;
				break;
			}
			if(j>n) break;
		}
		if(p==-1) p=++cnt;
		wei[p]=b,ans[p]++;
	}
	memset(wei,0,sizeof(wei));
	for(int i=1;i<=mm;i++){
		scanf("%d%d",&a,&b);
		p=-1;
		for(int j=1;j<=cntt;j++){
			if(wei[j]<a){
				p=j;
				break;
			}
			if(j>n) break;
		}
		if(p==-1) p=++cntt;
		wei[p]=b,anss[p]++;
	}
	for(int i=1;i<=n;i++){
		ans[i]+=ans[i-1];
		anss[i]+=anss[i-1];
	}
	for(int i=0;i<=n;i++)
		dan=max(dan,ans[i]+anss[n-i]);
	printf("%d\n",dan);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
