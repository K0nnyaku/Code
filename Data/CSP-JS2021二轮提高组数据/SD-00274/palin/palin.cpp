#include<bits/stdc++.h>
using namespace std;
int T;
int n,L,R,flag=0;
int a[1000010],b[1000010];
bool vis[1000010];
char pre[1000010];
void dfs(int x)
{
	if(flag==1) return;
	if(x>2*n)
	{
		for(int i=1,j=2*n;i<j;i++,j--)
		{
			if(b[i]!=b[j]) return;
		}
		for(int i=1;i<=2*n;i++) cout<<pre[i];
		cout<<endl;
		flag=1;
		return;
	}
	if(1)
	{
		b[x]=a[L];
		pre[x]='L';
		vis[a[L]]=1;
		L++;
		dfs(x+1);
		vis[a[L]]=0;
		L--;
		
	}
	if(1)
	{
		b[x]=a[R];
		pre[x]='R';
		vis[a[R]]=1;
		R--;
		dfs(x+1);
		vis[a[R]]=0;
		R++;
		
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--)
	{
		flag=0;
		memset(b,0,sizeof(b));
		memset(pre,' ',sizeof(pre));
		cin>>n;
		for(int i=1;i<=2*n;i++) cin>>a[i];
		L=1,R=2*n;
		dfs(1);
		if(!flag) cout<<"-1"<<endl;
	}
	return 0;
}
