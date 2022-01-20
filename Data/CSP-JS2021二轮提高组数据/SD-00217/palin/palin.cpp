#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<deque>
#include<stack>

using namespace std;

int a[1005],b[1005];
string s;
bool vis[1005];
int n;

int ans[1005];
string lzj; 

int fk=0;

void dfs(int x,int L,int R)
{
	if(L>2*n||R<0)return;
	if(x-1>n)
	{
		if(b[x-1]!=b[n*2-x+1+1])return;
	}
	if(x==2*n)
	{
		fk=1;
		int flag=0;
		if(s<lzj){
			lzj=s;
			flag=1;
		}
		if(flag)
		{
			for(int i=1;i<=n*2;i++)
			{
				ans[i]=b[i];
			}
		}
		return;
	}
	b[x]=a[L];
	s[x]='L'; 
	dfs(x+1,L+1,R);
	b[x]=a[R];
	s[x]='R';
	dfs(x+1,L,R-1);
	b[x]=0;
	s[x]='Z';
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(ans,127,sizeof(ans));
		cin>>n;
		for(int i=1;i<=2*n;i++)
		{
			cin>>a[i];
			lzj[i-1]='Z'; 
		}
		dfs(1,1,n*2);
		if(!fk)cout<<-1<<"\n"; 
		else 
		{
			for(int i=0;i<lzj.length();i++)
			{
				cout<<s[i];
			}
			cout<<"\n";
		}
		memset(a,0,sizeof(a));
		
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
Äã	É¾	×¢	ÊÍ	ÁË	Âð 
*/ 
