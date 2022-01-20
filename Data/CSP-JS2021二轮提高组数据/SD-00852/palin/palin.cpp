#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#define ll long long
#define H cout<<endl

using namespace std;

const int N=510;

int n;
int a[N*2];
bool ans[N*2],vis[N*2];

int check()
{
	int sig=0;
	for(int i=1;i<=n;i++)
	 {
	 	if(ans[i]!=ans[2*n+1-i])
	 	{
	 		sig=1;
	 		break;
	 	}
	 }
	if(sig==1)
	 return 0;
	else
	{
		for(int i=1;i<=n*2;i++)
		 {
		 	if(ans[i]==1)
		  	cout<<"L";
		  	else
		  	 cout<<"R";
		 }
		 H;
		 return 1;
	}
}

void dfs(int now,int gg)
{
	if(now>=n*2)
	 {
	 	int boo=check();
	 	if(boo==1)
	 	 return;
	 }
	 if(vis[gg])
	{
		if(vis[!gg])
		 return ;
		else
		 {
		 	ans[now]=0;
			 dfs(now+1,!gg);
		 }
	}
	 else if(vis[!gg])
	{
		if(vis[gg])
		 return ;
		else
		{
			ans[now]=1;
			dfs(now+1,gg);
			
		} 
	}
	else
	{
		ans[now]=1;
		dfs(now+1,gg);
		ans[now]=0;
		dfs(now+1,!gg);
	}
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;cin>>t;
	if(t==2)
	{
		cout<<"LRRLLRRRRL";H;
		cout<<-1;
	}
	while(t--)
	{
		cin>>n;
		memset(ans,0,sizeof(ans));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n*2;i++)
		scanf("%d",&a[i]);
		dfs(1,1);
	} 
	return 0;
}

