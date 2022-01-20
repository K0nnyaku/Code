#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>

//unsigned long long Score=400

using namespace std;
typedef long long ll;
inline ll qread()
{
	char a=getchar();
	ll shu=0,Sign=1;
	while(a<'0'||a>'9'){
		if(a=='-')
			Sign=-1;
		a=getchar();
	}
	while(a>='0'&&a<='9')
	{
		shu=(shu<<3)+(shu<<1)+a-'0';
		a=getchar();
	}
	return shu*Sign;
}
ll a[10001],b[10001],n,t;
char cz[10001];
bool ov=0;
int check()
{
	for(int i=1;i<=n/2;i++)
	{
		if(b[i]!=b[n-i+1])
		{
			return 0;
		}
	}
	return 1;
}
int dfs(ll l,ll r,ll pos)
{
	//cout<<l<<" "<<r<<" "<<pos<<endl; 
	if(ov)
	{
		return 0;
	}
	if(pos>(n/2)+1)
	{
		pos--;
		if(b[pos]!=b[n-pos+1])
		{
			//cout<<pos<<endl;
			return 0;
		}
		pos++;
	}
	if(pos>n)
	{
		if(check()) 
		{
			for(int i=1;i<=n;i++)
			{
				cout<<cz[i];
			}
			cout<<endl;
			ov=1;
			//return 0;
		}
		return 0;
	}
	b[pos]=a[l];
	cz[pos]='L';
	//cout<<l+1<<" "<<r<<" "<<pos+1<<endl;
	dfs(l+1,r,pos+1);
	b[pos]=a[r];
	cz[pos]='R';
	//cout<<l<<" "<<r-1<<" "<<pos+1<<endl;
	dfs(l,r-1,pos+1);
	return 0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=qread();
	while(t)
	{
		t--;
		ov=0;
		n=qread();
		n*=2;
		for(int i=1;i<=n;i++)
		{
			a[i]=qread();
		}
		dfs(1,n,1);
		if(ov==0)
		{
			cout<<"-1\n";
		}
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
