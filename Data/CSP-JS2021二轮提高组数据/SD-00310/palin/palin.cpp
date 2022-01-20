#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int k,n,a[500001]={0},t[500001],
	ans[500001],ans2=0,ans1[500001];
bool b[500001];
bool ce(int l,int r)
{
	if(b[a[l]]==0) l--;
	if(b[a[r]]==0) r++;
	for(int i=n;i>=1;i--)
	{
		if(a[l]==t[i]) {l++;ans1[n+n-i+1]=1;}
		else if(a[r]==t[i]) {r--;ans1[n+n-i+1]=2;}
		else return false; 
	}
	return true;
}
void write()
{
	int f=1;
	if(ans2!=0)
	{
		for(int i=1;i<=2*n;i++)
		{
			if(ans[i]>ans1[i]){
				f=0;
				break;
			}
		}
	}
	if(f)
	{
		for(int i=1;i<=2*n;i++)
		{
			ans[i]=ans1[i]; 
		}
	}
	ans2=1;
}
void dfs(int l,int r,int num)
{
	if(num==n+1) 
	{
		if(ce(l,r)) {write();}
		return;
	}
	if(!b[a[l]])
	{
		t[num]=a[l];
		b[a[l]]=true;
		ans1[num]=1;
		dfs(l+1,r,num+1);
		t[num]=0;
		b[a[l]]=false;
		ans1[num]=0;
	}/*
	b[num]=1;t[num]=a[l];
	dfs(l+1,r,num+1);*/
	if(!b[a[r]])
	{
		t[num]=a[r];
		b[a[r]]=true;
		ans1[num]=2;
		dfs(l,r-1,num+1);
		t[num]=0;
		b[a[r]]=false;
		ans1[num]=0;
	}
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>k;
	while(k>0)
	{
		ans2=0;
		memset(b,false,sizeof(b));
		cin>>n;
		for(int i=1;i<=2*n;i++)
			cin>>a[i];
		dfs(1,2*n,1);
		if(ans2==0) cout<<"-1"<<endl;
		else
		{
			for(int i=1;i<=2*n;i++)
			{
				if(ans[i]==1) cout<<"L";
				if(ans[i]==2) cout<<"R";
			}
			cout<<endl;
		}
		k--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
