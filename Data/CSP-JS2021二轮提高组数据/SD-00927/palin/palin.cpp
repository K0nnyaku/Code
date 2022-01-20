#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1e3+50;

int T;
char ans[N];
int n,a[N];
int now[N];
int b[N];
char nans[N];
void newans()
{
	int TT=1;
	while(ans[TT]==nans[TT]) TT++;
	if(ans[TT]<nans[TT]) 
	{
		for(int i=1;i<=2*n;i++) ans[i]=nans[i];
	}
}
bool check()
{
	//for(int i=1;i<=n;i++) cout<<now[i];
	//puts("");
	int l=1,r=2*n;
	int vis[N];
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++)
	{
		if(now[i])
		{
			if(vis[a[l]]) return 0;
			vis[a[l]]=1;
			b[i]=a[l];
			l++;
			nans[i]='L';
		}
		else
		{
			if(vis[a[r]]) return 0;
			vis[a[r]]=1;
			b[i]=a[r];
			r--;
			nans[i]='R';
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[l]==b[n-i+1])
		{
			b[n+i]=a[l];
			l++;
				nans[i+n]='L';
				continue;
		}
		else if(a[r]==b[n-i+1])
		{
			b[n+i]=a[r];
			r--;
			nans[i+n]='R';
			continue;
		}
		return 0;
	}
	for(int i=1;i<=n;i++) if(b[i]!=b[2*n+1-i]) return 0;
	//for(int i=1;i<=2*n;i++) cout<<nans[i];
	//puts("");
	return 1;

}
int solve()
{
	int flag=-1;
	for(int S=0;S<(1<<n);S++)
	{
		for(int i=1;i<=n;i++)
		{
			now[i]=((S&(1<<(i-1)))==(1<<(i-1)));
		}
		if(check()) flag=1,newans();
	}
	return flag;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		for(int i=1;i<=n*2;i++) ans[i]='L'; 
		scanf("%d",&n);
		if(n>20) return 0;
		for(int i=1;i<=2*n;i++)
		{
			cin>>a[i];
			//cout<<a[i]<<" ";
		}
		if(solve()!=-1)
		{
			for(int i=1;i<=2*n;i++) cout<<ans[i];
			puts("");
		}
		else puts("-1");
	}
	
	fclose(stdin);
	fclose(stdout);
}
