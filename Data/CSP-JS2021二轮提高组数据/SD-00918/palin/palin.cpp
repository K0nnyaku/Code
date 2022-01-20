#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=1e6+5;

int T;
int n;

int a[N];
int pre[N];
int vis[N];
int b[N];

bool f;

void dfs(int l,int r,int cnt)
{
	if(l>2*n+1||r<-1) 
	{
		return;
	}
	if(cnt==2*n)
	{
		bool ff=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]!=b[2*n-i+1])
			{
				ff=1;
			}
		}
		if(!ff)
		{
			for(int i=1;i<=2*n;i++)
			{
				if(pre[i])
				{
					cout<<"R";
				}
				else
				{
					cout<<"L";
				}
				f=1;
			}
		}
		return;
	}
	
	if(f)
	{
		return;
	}
	
	pre[cnt+1]=0;
	b[cnt+1]=a[l];
	dfs(l+1,r,cnt+1);
	
	if(f)
	{
		return;
	}
	
	pre[cnt+1]=1;
	b[cnt+1]=a[r];
	dfs(l,r-1,cnt+1);
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);

	cin>>T;
	while(T--)
	{
		cin>>n;
		f=0;
		for(int i=1;i<=2*n;i++)
		{
			cin>>a[i];
		}
		
		bool tf=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[2*n-i+1])
			{
				tf=1;
			}
		}
		if(!tf)
		{
			for(int i=1;i<=2*n;i++)
			{
				cout<<"L";
			}
			cout<<endl;
			continue;
		}
		
		
		
		dfs(1,2*n,0);
		
		if(!f)
		{
			cout<<-1;
		}
		cout<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

