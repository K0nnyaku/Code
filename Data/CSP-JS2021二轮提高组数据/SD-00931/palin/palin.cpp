#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n,a[50],k=0,d[50];
char c[50];
struct node 
{
	char b[50];
	int num[50];
}h[1050000];
void dfs(int x)
{
	if(x==2*n+1)
	{
		int l=1,r=2*n,p=1;
		memset(d,0,sizeof(d));
		for(int i=1;i<=2*n;i++)
		{
			if(c[i]=='L')d[i]=a[l],l++;
			if(c[i]=='R')d[i]=a[r],r--;
		}
		for(int i=1;i<=n;i++)if(d[i]!=d[2*n+1-i])p=0;
		if(p)
		{
			k++;
			for(int i=1;i<=2*n;i++)
				h[k].b[i]=c[i],h[k].num[i]=d[i];
		}	
		return ;
	}
	c[x]='L';
	dfs(x+1);
	c[x]='R';
	dfs(x+1);
}
bool cmp(node o,node s)
{
	for(int i=1;i<=2*n;i++)
	{
		if(o.num[i]==s.num[i])continue;
		if(o.num[i]<s.num[i])return true;
		else return false;
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		k=0;
		for(int i=1;i<=2*n;i++)scanf("%d",a+i);
		memset(c,0,sizeof(c));
		dfs(1);
		if(k==0)
		{
			printf("-1\n");
			continue;	
		}
		node x=h[1];
		for(int i=2;i<=k;i++)if(cmp(h[i],x))x=h[i];
		for(int i=1;i<=2*n;i++)printf("%c",x.b[i]);
		printf("\n");
	}
	return 0;
}
