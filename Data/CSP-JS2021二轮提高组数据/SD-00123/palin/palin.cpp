#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int n,T,a[200010],b[200010];
bool f;
char c[200010];
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=b[2*n-i+1])
			return 0;
	}
	for(int i=1;i<=2*n;i++)
	{
		printf("%c",c[i]);
	}
	return 1;
}
int l,r;
void dfs(int k)
{
	if(f)return;
	if(k==2*n+1)
	{
		f=check();
		return ;
	}
	
	//lv1
	c[k]='L';
	b[k]=a[l];
	l=l+1;
	dfs(k+1);
	l=l-1;
	
	//lv2
	c[k]='R';
	b[k]=a[r];
	r=r-1;
	dfs(k+1);
	r=r+1;
	
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	int pf=0;
	while(T--)
	{
		f=0;
		cin>>n;
		if(n>20)
		{
			pf=1;
			break;
		}
		l=1,r=2*n;
		for(int i=1;i<=2*n;i++)
		{
			scanf("%d",&a[i]);
		}
		dfs(1);
		if(!f)printf("-1");
		printf("\n");
	}
	if(pf)cout<<-1<<endl;
	return 0;
}
