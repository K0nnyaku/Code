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
ll n,k,ql[10001],hl[10001],qk[10001],hk[10001],ans=0;
char a[10001],b[10001];
int check()
{
	int zk=0,yk=0,lx=0;
	for(int i=0;i<n;i++)
	{
		if(b[i]=='(')
		{
			zk++;
		}
		if(b[i]==')')
		{
			yk++;
		}
		if(b[i]=='*')
		{
			lx++;
			if(lx>k)
			{
				return 0;
			}
		}
		/*if(b[i]=='*'&&b[i+1]=='('&&zk==0)
		{
			return 0;
		}*/
	} 
	if(zk!=yk)
	{
		return 0;
	}
	//cout<<'(';
	//cout<<b<<')'<<endl;
	return 1;
}
ll dfs(int pos)
{
	if(pos==n)
	{
		if(check())
		{
			ans++;
		}
		return 0;
	}
	if(a[pos]!='?')
	{
		b[pos]=a[pos];
		dfs(pos+1);
		return 0;
	}
	b[pos]='*';
	dfs(pos+1);
	b[pos]='(';
	dfs(pos+1);
	b[pos]=')';
	dfs(pos+1);
	return 0;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	n=qread();
	k=qread();
	cin>>a;
	for(int i=0;i<n-2;i++)
	{
		a[i]=a[i+1];
	}
	n-=2;
	//cout<<a<<endl;
	dfs(0); 
	cout<<ans-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
7 3
(*??*??
*/

/*
10 2
???(*??(?)
*/
