#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<deque>
#include<stack>

using namespace std;

int n,k,f[505];
char a[505]; 

int ans=0;

stack<pair<char,int> > st;

void dfs(int x)
{
	if(x>n)
	{
		if(a[x-1]=='*')return;
		while(st.size())st.pop();
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='*')
			{
				f[i]=f[i-1]+1;
			}
			else f[i]=0;
			if(f[i]>k)return;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='(')
			{
				st.push(make_pair(a[i],i));
			}
			else if(a[i]==')')
			{
				if(!st.empty()&&st.top().first=='(')
				{
					int cur=f[i+1];
					for(int lzj=i+2;lzj<=n;lzj++)
					{
						if(cur>=f[lzj]||!f[lzj])break;
						else cur=f[lzj];
					}
					if(f[st.top().second-1]+cur>k)return;
					st.pop(); 
				}
				else 
				{
					st.push(make_pair(a[i],i));
				} 
			}
		}
		if(st.empty()){
			for(int i=1;i<=n;i++)
			{
				cout<<a[i];
			}
			cout<<endl;
			ans++; 
		}
		return;
	}
	if(a[x]=='?')
	{
		a[x]='(';
		dfs(x+1);
		a[x]='*';
		dfs(x+1);
		a[x]=')';
		dfs(x+1);
		a[x]='?';
	}
	else dfs(x+1);
}

string s;

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		a[i]=s[i-1];
	}
	dfs(1);
	printf("%d",ans-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
Äã	É¾	×¢	ÊÍ	ÁË	Âð 
*/ 
