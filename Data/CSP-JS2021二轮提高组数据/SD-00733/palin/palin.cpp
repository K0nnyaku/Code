#include<iostream>
#include<cstdio>
using namespace std;
int t;
int n;
int a[100010];
int b[100010];
int road[100010];
string ans;
bool flag;
int len;
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=b[n*2-i+1])
		return false;
	}
	return true;
}
void purunte()
{
	if(flag==1) return;
	flag=1;
	for(int i=1;i<=n*2;i++)
	{
		if(road[i]==1) cout<<"L"; 
		else cout<<"R"; 
	}
	cout<<endl;
}
void dfs(int l,int r,int cnt)
{
	if(cnt==2*n)
	{
		if(check())
		{
			purunte();
		}
		return;
	}
	for(int i=1;i<=2;i++)
	{
		if(i==1)
		{
			road[len]=1;
			b[len]=a[l];
			len++;
			dfs(l+1,r,cnt+1);
			road[len]=0;
			b[len]=0;
			len--;
		}
		if(i==2)
		{
			road[len]=2;
			b[len]=a[r];
			len++;
			dfs(l,r-1,cnt+1);
			road[len]=0;
			b[len]=0;
			len--;
		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		len=1;
		flag=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
		{
			scanf("%d",&a[i]);
		}
		dfs(1,n*2,0);
		if(flag==0) cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
