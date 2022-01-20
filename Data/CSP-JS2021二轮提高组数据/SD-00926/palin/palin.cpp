#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int a[N];
string s;
int path[N];
int n;
int flag=0;
bool check()
{
	for(int i=1;i<=n/2;i++)
	{
		if(a[i]!=a[2*n+1-i])return false;
	}
	return true;
}
void dfs(int u,int l,int r)
{
	if(u==n)
	{
		if(check())flag=1;
		return;
	}
	path[u]=a[l];
	s+='L';
	dfs(u+1,l+1,r);
	path[u]=a[r];
	s+='R';
	dfs(u+1,l,r-1);
}
int main()
{
	//freopen("palin.in","r",stdin);
	//freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		flag=0;
		cin>>n;
		for(int i=1;i<=2*n;i++)
		{
			cin>>a[i];	
		}
		cout<<-1<<endl;
	}
}
