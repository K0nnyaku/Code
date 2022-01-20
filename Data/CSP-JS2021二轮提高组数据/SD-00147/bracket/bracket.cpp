#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[10001],ans=0,uk=0;
int dfs(int x,int y,int z,int q)
{
	 if(x>n)
	 {
	 	
		 return 0;
	 }
	 if(x==n)
	 {
	 	
		  if(z==q+1)
	 	{
	 	
			 ans++;
		 }
		
		 return 0;
	 }
	 if(q>z)return 0;
	 if(a[x]==3&&y+1>m)
	 {
	 	
		 return 0;
	 }
	 if(a[x]!=4)
	 {
	 	if(a[x]==1)
	 	{
	 		
			 uk=1;dfs(x+1,0,z+1,q); 
	 		
		 } 
		 	if(a[x]==2)
	 	{
	 	uk=0;dfs(x+1,0,z,q+1); 
	 		
		 } 
		 	if(a[x]==3)
	 	{
	 			
				 uk=0;dfs(x+1,y+1,z,q); 
	 	
		 } 
		 return 0;
	 }
	 if(z>q&&uk!=1)
	 {
	 	uk=0;dfs(x+1,0,z,q+1);
	 	
	 }
	 if(y<m)
	 {
	 		uk=0;dfs(x+1,y+1,z,q);
	 
	 }
	 if(z-q<n-x)
	 {
	 		uk=1;dfs(x+1,0,z+1,q);
	 
	 } 
	 return 0;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin>>x;
		if(x=='(')
		{
			a[i]=1;
		}
		if(x==')')
		{
			a[i]=2;
		}
		if(x=='*')
		{
			a[i]=3;
		}
		if(x=='?')
		{
			a[i]=4;
		}
	}
	if(a[1]==3||a[n]==3||a[1]==2||a[n]==1)
	{
		cout<<0;
		return 0;
	}
	a[1]=1;a[n]=2;
	dfs(2,0,1,0);
	cout<<ans<<endl;
	return 0;
}
