#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=1e6+5;
int n,a[MAXN],T,flag,b[MAXN],cntb;
int ishuiwen()
{
	for(int i=1;i<=n;i++)
		if(b[i]!=b[2*n-i+1])return false;
	return true;
}
void dfs(int now,int head,int tail,string ans)
{
	if(flag)return;
	if(cntb>=2*n)
	{
		if(ishuiwen())
		{
			cout<<ans<<endl;
			flag=1;
			return;
		}
		return;
	}
	if(head>tail)return;
	b[++cntb]=a[head];
	dfs(now+1,head+1,tail,ans+'L');
	cntb--;
	b[++cntb]=a[tail];
	dfs(now+1,head,tail-1,ans+'R');
	cntb--;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--)
	{
		flag=0;
		cntb=0;
		cin>>n;
		for(int i=1;i<=2*n;i++)cin>>a[i];
		dfs(0,1,2*n,"");
		if(!flag)cout<<-1<<endl;
	}
	return 0;
}
