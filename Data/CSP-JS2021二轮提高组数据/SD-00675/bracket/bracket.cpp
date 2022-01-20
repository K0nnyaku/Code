#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
int ans=0;
void dfs(int x,int k,vector <char> v,vector <int> qn)
{
	int bol[qn.size()+1][4];
	memset(bol,0,sizeof(bol));
	if(x>qn.size())
	{
		int xn=0,ln=0,rn=0,cs=0,wei=0;
		bool pd=false;
		stack <int> s;
		for(int i=0;i<=v.size()-1;i++)
		{
			if(wei==1)
			{
				if(v[i]=='*')
				return;
				else wei=0;
			}
			if(i==0&&v[i]=='*')
			{
				return;
			}
			if(i==v.size()-1&&v[i]=='*')
			{
				return;
			}
			s.push(v[i]);
			if(v[i]=='(')
			{
				ln++;
			}
			else if(v[i]==')')
			{
				
				if(ln==0)
				{
					
					return;
				}
				else
				{
					s.pop();
					while(s.top()!='(')
					{
						cs++;
						if(cs>k)
						{
							return;
						}
						s.pop();
						xn--;
					}
					s.pop();
					ln--;
					if((!s.empty())&&s.top()=='*')
					{
						wei=1;
					}
				}
			}
			else if(v[i]=='*')
			{
				xn++;	
			}
			
		}
		if(ln==0)
		{
			ans++;
			for(int i=0;i<=v.size()-1;i++)
			{
				cout<<v[i];
			}
			cout<<endl;
		}
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(i==1&&bol[x][i]==0)
		{
			v[qn[x-1]]='(';
			bol[x][i]=1;
		}
		else if(i==2&&bol[x][i]==0)
		{
			v[qn[x-1]]=')';
			bol[x][i]=1;
		}
		else if(i==3&&bol[x][i]==0)
		{
			v[qn[x-1]]='*';
			bol[x][i]=1;
		}
		dfs(x+1,k,v,qn);
		bol[x][i]=0;
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	vector <char> v;
	vector <int> qn;
	int i,j,m,n,k,mod=pow(10,9)+7;
	char a;
	cin>>n>>k;
	if(n==0||n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		v.push_back(a);
		if(a=='?')
		{
			qn.push_back(v.size()-1);
		}
		
	}
	dfs(1,k,v,qn);
	cout<<ans%mod; 
	return 0;
}   
