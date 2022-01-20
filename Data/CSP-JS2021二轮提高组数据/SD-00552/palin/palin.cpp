#include<bits/stdc++.h>

#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>
#include<deque>
#include<cmath>
#include<cstring>
#include<unordered_map>
#include<map>
#include<set>
#include<vector>
using namespace std;

deque<int>V;
deque<int >C;

int T;
bool check()
{
	for(int i=1,j=2*n;i!=j;i++,j--)
	{
		if(a[i]!=a[j]) return false;
	}
	return true;
}
void dfs(int k)
{
	if(k==1*n)
	{
		if(check());
		
		
	}
	for(int i=1;i<=2*n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			a[k]=mark[i];
			dfs(k+1);
			a[k]=0;	
			vis[i]=0;
		 } 
	}
}

int main()
{
	freopen(" ","r",stdin);
	freopen(" ","w",stdout);
	cin>>T;
	while(T--)
	{
		
		int n;
		scan("%d",&n);
		
		for(int i=1;i<=2*n;i++)
		{
			scanf("%d",&mark[i]);
		} 
		
		dfs(0);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
