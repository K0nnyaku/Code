#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll t;
ll n;
ll ps[100010],ans[100010];
ll a[10010];
int flag;
void dfs(int x,int h,int t){
	if(x>2*n)
	{
		for(int i=1;i<=2*n;i++)
		{
			putchar (ans[i]?'R':'L');
			puts("");
			flag=1;
			return ;
		}
	}
	if(x<=n)
	{
		if(!ps[a[h]])
		{
			ps[a[h]]=x;
			ans[x]=0;
			dfs(x+1,h+1,t);
			ps[a[h]]=0;
		}
		if(!ps[a[t]])
		{
			ps[a[t]]=x;
			ans[x]=1;
			dfs(x+1,h+1,t-1);
			ps[a[t]]=0;
			if(!flag)
				return ;
		}
	}
	else {
		if(ps[a[h]]=2*n-x+1)
		{
			
		}
	}
}
int main()
{
//freopen("palin.in","r","stdin");
//freopen("palin.out","w","stdout");
	cin>>t;
	while (t--)
	{
		memset(ps,0,sizeof(ps));
		cin>>n;
		flag=0;
		for(int i=1;i<=2*n;i++)
		{
			dfs(1,1,2*n);
			if(!flag)
			{
				puts("-1");
			}
		}
	}
	 return 0;
}



