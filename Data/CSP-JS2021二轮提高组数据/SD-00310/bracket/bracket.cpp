#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int n,k,c[501],ans=0,sum;
string b;
char a[501];
bool check()
{
	int t=0;
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++)
	{
		if(a[i]=='(') t++;
		else if(a[i]=='*') {
			c[t]++;
			if(c[t]>=k) return false;
		//	if(a[i-1]==')'&&c[t]!=0&&t!=0) return false;
		}
		else if(a[i]==')') 
		{
			c[t]=0;
			t--;
			if(t<0) return false;
		}
	}
	if(t!=0) return false;
	return true;
}
void dfs(int num)
{
	if(num==n)
	{
		if(check()) {ans++;
	/*	for(int i=0;i<n;i++)
			cout<<a[i];
		cout<<endl;*/}
		return;
	}	
	if(a[num]=='?')
	{
		if(sum<n/2){
			sum++;
			a[num]='(';dfs(num+1);
			sum--;
		}/*
		a[num]='(';dfs(num+1);*/
		a[num]='*';dfs(num+1);
		a[num]=')';dfs(num+1);
		a[num]='?';
	}
	else dfs(num+1);
	return;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>b;
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++)
	{
		a[i]=b[i];
		if(a[i]=='(') sum++;
	}
	a[0]='(';a[n-1]=')';/**/
	dfs(0);
	cout<<ans%1000000007;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
