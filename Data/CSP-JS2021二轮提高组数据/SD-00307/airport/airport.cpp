#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100010;
int n,m[3],c1[2*N],cnt[3],c2[2*N];
int c[2*N];
struct Node{
	int a,b; 
}t[3][N];
bool cmp(int a,int b)
{
	return a<b;
}
bool cmp2(Node a,Node b)
{
	return a.a<b.a;
}
void add(int x,int y)
{
	for(;x<=2*N;x+=x&(-x))
		c[x]+=y;
}
int ask(int x)
{
	int res=0;
	for(;x;x-=x&(-x))
		res+=c[x];
	return res;
}
int calc(int p,int x)
{
	int res=0;
	memset(c,0,sizeof c);
	for(int i=1;i<=m[p];i++)
	{
		if(ask(t[p][i].a-1)<x)
		{
			add(t[p][i].a,1);
			add(t[p][i].b,-1);
			res++;
		}
		else continue;
	}
	return res;
}
int precalc(int p)
{
	int res=0;
	memset(c,0,sizeof c);
	for(int i=1;i<=m[p];i++)
	{
		add(t[p][i].a,1);
		add(t[p][i].b,-1);
		res=max(res,ask(t[p][i].a));
	}
	return res;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m[1],&m[2]);
	for(int i=1;i<=m[1];i++)
	{
		scanf("%d%d",&t[1][i].a,&t[1][i].b);
		c1[++cnt[1]]=t[1][i].a;
		c1[++cnt[1]]=t[1][i].b;
	}
	sort(c1+1,c1+cnt[1]+1,cmp);
	for(int i=1;i<=m[1];i++)
	{
		t[1][i].a=lower_bound(c1+1,c1+cnt[1]+1,t[1][i].a)-c1;
		t[1][i].b=lower_bound(c1+1,c1+cnt[1]+1,t[1][i].b)-c1;
	}
	for(int i=1;i<=m[2];i++)
	{
		scanf("%d%d",&t[2][i].a,&t[2][i].b);
		c2[++cnt[2]]=t[2][i].a;
		c2[++cnt[2]]=t[2][i].b;
	}
	sort(c2+1,c2+cnt[2]+1,cmp);
	for(int i=1;i<=m[2];i++)
	{
		t[2][i].a=lower_bound(c2+1,c2+cnt[2]+1,t[2][i].a)-c2;
		t[2][i].b=lower_bound(c2+1,c2+cnt[2]+1,t[2][i].b)-c2;
	}
	sort(t[1]+1,t[1]+m[1]+1,cmp2);
	sort(t[2]+1,t[2]+m[2]+1,cmp2);
	int x=precalc(1),y=precalc(2);
	//cout<<x<<" "<<y<<endl;
	int ans=0;
	for(int i=0;i<=min(n,x);i++)
	{
		ans=max(ans,calc(1,i)+calc(2,n-i));
	}
	for(int i=max(0,n-y);i<=n;i++)
	{
		ans=max(ans,calc(1,i)+calc(2,n-i));
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
