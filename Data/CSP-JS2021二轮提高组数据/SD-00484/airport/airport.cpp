#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int f=1,w=0;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		w=w*10+c-'0';
		c=getchar();
	}
	return f*w;
}
const int o=100010;
int taga[o],tagb[o],n,m,mm,fa[o],fb[o];
struct plane{
	int a,b;
};
plane d[o],g[o];
int cmp(plane x,plane y)
{
	return x.a<y.a;
}
int efa(int a,int b,int x)
{
	int ans=m+1,l=a,r=b;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(d[mid].a>=x){
			ans=mid,r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}
int efb(int a,int b,int x)
{
	int ans=mm+1,l=a,r=b;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(g[mid].a>=x){
			ans=mid,r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m=read(),mm=read();
	for(int i=1;i<=m;i++)
	{
		d[i].a=read(),d[i].b=read();
	}
	for(int i=1;i<=mm;i++)
	{
		g[i].a=read(),g[i].b=read();
	}
	int tota=0,totb=0;
	sort(d+1,d+m+1,cmp);
	sort(g+1,g+mm+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(!taga[i])taga[i]=++tota,fa[taga[i]]++;
	    else continue;
		int x=efa(i,m,d[i].b);
		while(x<=m)
		{
			while(taga[x])x++;
			if(x>m)continue;
			taga[x]=taga[i];
			fa[taga[i]]++;
			x=efa(x,m,d[x].b);
			
		}
	}
	for(int i=1;i<=mm;i++)
	{
		if(!tagb[i])tagb[i]=++totb,fb[tagb[i]]++;
		else continue;
		int x=efb(i,mm,g[i].b);
		while(x<=mm)
		{
		while(tagb[x])x++;
		if(x>mm)continue;
			tagb[x]=tagb[i];
			fb[tagb[i]]++;
			x=efb(x,mm,g[x].b);
		}
	}
	for(int i=1;i<=tota;i++){
	fa[i]+=fa[i-1];
	
	}
	for(int i=1;i<=totb;i++){
	fb[i]+=fb[i-1];	
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,fa[min(i,tota)]+fb[min(n-i,totb)]);
	}
	printf("%d",ans);
	return 0;
 } 
