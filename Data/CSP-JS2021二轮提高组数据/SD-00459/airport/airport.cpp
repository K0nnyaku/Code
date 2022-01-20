#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

int n,m1,m2,rk[200008];
bool vis[200008];
struct plane {
	int t,val,tag;
} p1[200008],p2[200008];

bool cmp(plane pp1,plane pp2) {
	return pp1.t < pp2.t || (pp1.t == pp2.t && pp1.val < pp2.val);
} 

int count1(int k)
{
	memset(vis,0,sizeof(vis));
	int cnt=0,ans=0;
	for(int i=1; i<=2*m1; ++i)
	{
		if(p1[i].val==-1 && vis[p1[i].tag]==0) --cnt;
		if(p1[i].val==1)
		{
			if(cnt!=k){
				++cnt; ++ans;
			}
			else vis[p1[i].tag]=1;
		}
	}
	return ans;
}

int count2(int k)
{
	memset(vis,0,sizeof(vis));
	int cnt=0,ans=0;
	for(int i=1; i<=2*m2; ++i)
	{
		if(p2[i].val==-1 && vis[p2[i].tag]==0) --cnt;
		if(p2[i].val==1)
		{
			if(cnt!=k){
				++cnt; ++ans;
			}
			else vis[p2[i].tag]=1;
		}
	}
	return ans;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
		
	scanf("%d%d%d",&n,&m1,&m2);
	
	int x,y; 
	for(int i=1; i<=m1; ++i){
		scanf("%d%d",&x,&y);
		p1[i*2-1].t=x; p1[i*2-1].val=1; p1[i*2-1].tag=i;
		p1[i*2].t=y; p1[i*2].val=-1; p1[i*2].tag=i;
	}
	for(int i=1; i<=m2; ++i){
		scanf("%d%d",&x,&y);
		p2[i*2-1].t=x; p2[i*2-1].val=1; p2[i*2-1].tag=i;
		p2[i*2].t=y; p2[i*2].val=-1; p2[i*2].tag=i;
	}

	sort(p1+1,p1+1+2*m1,cmp);
	sort(p2+1,p2+1+2*m2,cmp);
	
	if(n<=5000 && m1+m2<=10000)
	{
		int maxn=-1;
		for(int i=0; i<=n; ++i){
			int total=count1(i)+count2(n-i);
			if(maxn<total) maxn=total;
		}
		cout<<maxn;
	}
	else
	{
		if(n>=m1+m2){
			cout<<m1+m2;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		int maxn=-1,maxm=-1;
		for(int i=0; i<=n; i+=n/110){
			int total=count1(i)+count2(n-i);
			if(maxn<total) {maxn=total; maxn=i;}
		}
		maxn=-1;
		for(int i=max(1,maxn-250); i<=min(n,maxn+250); ++i){
			int total=count1(i)+count2(n-i);
			if(maxn<total) maxn=total;
		}
		cout<<maxn;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
