#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,t,head,tail,wancheng,a[500001],s[500001],S[500001],vis[500001];
void dfs(int now,int d)
{
	if(d==0)
	{
		if(now<=n&&vis[a[head]]==1)	return;
		vis[a[head]]=1;
		s[now]=a[head++];
		S[now]=d;
		if(now==2*n)
		{
			for(int i=1;i<=n;i++)
			{
				if(s[i]!=s[2*n-i+1])
				{
					head--;
					vis[a[head]]=0;
					return;
				}
			}
			for(int i=1;i<=2*n;i++)
			{
				if(S[i]==0)
					cout<<"L";
				if(S[i]==1)
					cout<<"R";
			}
			cout<<endl;
			wancheng=1;
			return;
		}
		else
		{
			dfs(now+1,0);
			if(wancheng==1)
				return;
			dfs(now+1,1);
			if(wancheng==1)
				return;
			head--;
			vis[a[head]]=0;
		}
	}
	if(d==1)
	{
		if(now<=n&&vis[a[tail]]==1)	return;
		vis[a[tail]]=1;
		s[now]=a[tail--];
		S[now]=d;
		if(now==2*n)
		{
			for(int i=1;i<=n;i++)
			{
				if(s[i]!=s[2*n-i+1])
				{
					tail++;
					vis[a[tail]]=0;
					return;
				}
			}
			for(int i=1;i<=2*n;i++)
			{
				if(S[i]==0)
					cout<<"L";
				if(S[i]==1)
					cout<<"R";
			}
			cout<<endl;
			wancheng=1;
			return;
		}
		else
		{
			dfs(now+1,0);
			if(wancheng==1)
				return;
			dfs(now+1,1);
			if(wancheng==1)
				return;
			tail++;
			vis[a[tail]]=0;
		}
	}
	return;
}
int main()
{
	freopen("palin.in","r",stdin); 
	freopen("palin.out","w",stdout);
	t=read();
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		wancheng=0;
		n=read();
		for(int i=1;i<=2*n;i++)
		{
			a[i]=read();
		}
		head=1;
		tail=2*n;
		dfs(1,0);
		if(wancheng==1)
			continue;
		dfs(1,1);
		if(wancheng==1)
			continue;
		cout<<"-1"<<endl;
	}
	return 0;
} 
