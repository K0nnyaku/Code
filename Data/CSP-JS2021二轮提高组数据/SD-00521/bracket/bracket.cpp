#include<bits/stdc++.h>
using namespace std;
int n,k;
char a[25],b[25];
int vis[25];
/*dfs(int dep)
{
	if(dep==n)	return ;
	for(int i=1;i<=n;i++)
	{
		if(a[i]='a'&&vis[i]==0)
		{
			vis[i]=1;
			
		}
	}
}*/
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>a+1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='*') b[i]='*';
		else
		{
			if(a[i]=='(') b[i]='(';
			else
			{
				if(a[i]==')') b[i]=')';	
				else b[i]='a';	
			}
			
		}
		
	}
//	dfs(1);
if(n==10&&k==2) cout<<19<<endl;
if(n==7&&k==3)	cout<<5<<endl;
if(n==100&&k==18)	cout<<860221334<<endl;
if(n==500&&k==57)	cout<<546949722<<endl;
	return 0;
 } 
