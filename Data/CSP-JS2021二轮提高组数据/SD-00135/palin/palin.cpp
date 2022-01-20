#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#pragma GCC optimize(2)
const int N=1e6+10;
int a[N],n,len;
int b[N],b2[N];
char cz2[N];
vector<char> cz;
vector<int> ans2;
void dfs(int u,int l,int r)
{ 
	if(u==2*n+1)
	{
		int i;
		for(i=1;i<=2*n;i++)
		    if(b[i]!=b2[i]) break;
		if(b[i]>b2[i])
		{
		    for(int i=1;i<=2*n;i++) b[i]=b2[i]; 
		    len=0;
		    for(int i=0;i<cz.size();i++) cz2[++len]=cz[i];
		}
		return;
	}
	if(l<=r)
	{
		if(u>n)
		{
			if(a[l]==b2[2*n+1-u])
		    {
			    b2[u]=a[l];
			    cz.push_back('L');
			    dfs(u+1,l+1,r);
			    cz.pop_back();
			}
			if(a[r]==b2[2*n+1-u])
			{
		        cz.push_back('R');
		        b2[u]=a[r];
		        dfs(u+1,l,r-1);
		        cz.pop_back();
		    }
	    }
	    else
	    {
	    	b2[u]=a[l];
		    cz.push_back('L');
			dfs(u+1,l+1,r);
			cz.pop_back();
			cz.push_back('R');
		    b2[u]=a[r];
		    dfs(u+1,l,r-1);
		    cz.pop_back();
		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=2*n;i++)
		    cin>>a[i];
		if(n>1000)
		{
			int l=1,r=2*n;
			for(int i=1;i<=n;i++)
			{
				if(a[l]==a[l+1]) cout<<"LL",l+=2;
				else if(a[l]==a[r]) cout<<"LR",l++,r--;
				else if(a[r]==a[r-1]) cout<<"RR",r-=2;
			}
			cout<<endl;
		    continue;
		} 
		for(int i=1;i<=2*n;i++) b[i]=1e9;	
		dfs(1,1,2*n);
		if(len==0)
		{
			cout<<"-1"<<endl;
			continue;
		}
		for(int i=1;i<=2*n;i++) cout<<cz2[i];
		len=0;
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
