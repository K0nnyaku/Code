#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int t,n,tot=1,tt,top;
int a[50005],book,b[50005],flag;
char c[50005];
void dfs(int x)
{
	if(x==tt+1)
	{
		book=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]!=b[tt+1-i])
			book=1;
		}
		if(book==0)
		{
			flag=1;
			for(int i=1;i<=tt;i++)
			{
				cout<<c[i];
			}
			cout<<endl;
		}	
		return;
	}
	b[x]=a[tot];
	tot++;
	c[x]='L';
	dfs(x+1);
	tot--;
	if(book==0)
	return; 
	b[x]=a[top];
	top--;
	c[x]='R';
	dfs(x+1);
	top++;
	if(book==0)
	return;
}
int main() 
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		tt=top=2*n;
		tot=1;
		flag=0;
		for(int j=1;j<=tt;j++)
		{
			scanf("%d",&a[j]);	
		}	
		dfs(1);
		if(flag==0)
		printf("-1\n");
	}	
	return 0;
}
