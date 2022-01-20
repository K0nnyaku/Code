#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n,p1,p2,a[1000005],b[1000005],c[1000005];
bool bl;
bool check()
{
	for(int i=1;i<=n;i++)
		if(b[i]!=b[2*n-i+1])
			return false;
	return true;
}
void dfs(int k)
{
	if(bl)
		return;
	if(k==2*n+1)
	{
		bl=check();
		if(bl)
		{
			for(int i=1;i<=2*n;i++)
				cout<<((c[i]==0)? 'L':'R');
			cout<<endl;
		}
		return;
	}
	c[k]=0;
	b[k]=a[p1++];
	dfs(k+1);
	p1--;
	if(bl)
		return;
	c[k]=1;
	b[k]=a[p2--];
	dfs(k+1);
	p2++;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
			scanf("%d",&a[i]);
		bl=false,p1=1,p2=2*n;
		dfs(1);
		if(!bl)
			printf("-1\n");
	}
	return 0;
}
