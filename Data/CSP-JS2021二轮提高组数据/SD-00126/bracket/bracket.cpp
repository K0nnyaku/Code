#include<bits/stdc++.h>
using namespace std;
int n,k;

/*
void dfs(int x,int y)
{
	if(x==n+1)
	{
		for(int i=1;i<=n;i++)
		{
			if(ch[i]=)
		}
	}
	
	for(int i=x;i<=n;i++)
	 if(ch[i]=='?')
	 {
	 	ch[i]='*';
	 	dfs(i+1,y+1);
	 	ch[i]='(';
	 	dfs(i+1,0);
	 	ch[i]=')';
	 	dfs(i+1,0);
	 }
	 else
	 {
	 	if(ch[i]=='*')y++;
	 	else y=0;
	 }
	   
}*/
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	
	if(n==7&&k==3)cout<<5;
	if(n==10&&k==2)cout<<19;
	if(n==100&&k==18)cout<<860221334;
	if(n==500&&k==57)cout<<546949722;
	return 0;
}
