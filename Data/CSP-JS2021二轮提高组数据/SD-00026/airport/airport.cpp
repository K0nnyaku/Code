#include<bits/stdc++.h>
using namespace std;
int n,m,p,t,t1,ans;
struct data{
	int q,w;
}f[100005],f1[100005],c[100005],d[100005];
bool dfs(data x,data y)
{
	return x.q<y.q;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=m;i++)
	   scanf("%d%d",&c[i].q,&c[i].w);
	sort(c+1,c+m+1,dfs);
	for(int i=1;i<=p;i++)
	   scanf("%d%d",&d[i].q,&d[i].w);
	sort(d+1,d+p+1,dfs);
	for(int i=1;i<=m;i++)
	   {
	   	int a=c[i].q,b=c[i].w,flag=0;
	   	for(int j=1;j<=t;j++)
	   	   if(f[j].q<a)
	   	     {
	   	     	f[j].q=b,f[j].w++,flag=1;
	   	     	break;
				}
	   	if(!flag)f[++t].q=b,f[t].w=1;
	   }
	for(int i=1;i<=p;i++)
	   {
	   	int a=d[i].q,b=d[i].w,flag=0;
	   	for(int j=1;j<=t1;j++)
	   	   if(f1[j].q<a)
	   	     {
	   	     	f1[j].q=b,f1[j].w++,flag=1;
	   	     	break;
				}
	   	if(!flag)f1[++t1].q=b,f1[t1].w=1;
	   }
	for(int i=1;i<=t;i++)
	   f[i].w+=f[i-1].w;
	for(int i=1;i<=t1;i++)
	   f1[i].w+=f1[i-1].w;
	for(int i=0;i<=n;i++)
	   {
	   	int e=min(n-i,t1),e1=min(i,t);
	   ans=max(ans,f[e1].w+f1[e].w);
	   }
	cout<<ans;
    return 0;
}
