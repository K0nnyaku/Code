#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 510
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
//-------------------------------------
int n,k,sum;
char s[N];
char Stac[N],tot;
int sti;
bool check()
{
	sti=0;
	tot=0;
	memset(Stac,0,sizeof(Stac));
	for(int i=0;i<n;++i)
	{
		if(s[i]=='*')  ++tot;
		else
		{
			if(tot>k) return false;
			tot=0;
		}
		Stac[++sti]=s[i];
		if(Stac[sti]==')')
		{
			sti--;
			while(Stac[sti]!='('&&sti)
			{
				--sti;
			}
			if(Stac[sti]=='(') sti--;
			else Stac[++sti]=')';
		}
	}
	if(sti==0) return true;
	return false;
}
void dfs(int k)
{
	if(k==n)
	{
		if(check())
			++sum;
		return;
	}
	if(s[k]=='?')
	{
		s[k]='(';
		dfs(k+1);
		s[k]='?';
		s[k]=')';
		dfs(k+1);
		s[k]='?';
		s[k]='*';
		dfs(k+1);
		s[k]='?';
		return;
	}
	dfs(k+1);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	cin>>s;
	dfs(0);
	write(sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

