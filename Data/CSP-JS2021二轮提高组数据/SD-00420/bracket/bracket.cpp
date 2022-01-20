#include<bits/stdc++.h>
using namespace std;
string aa;
int n,k,cd,ans,num,jl;
string zhan;


void dfs(int x)
{
	if(x>=n)
	{
		for(int i=0;i<n;i++)
		{
			zhan[++num]=aa[i];
			if(zhan[num]==')' and zhan[num-1]=='(')
			{
				num=num-2;
			}		
			else if(zhan[num]=='*')
			{
				jl++;
				if(aa[i+1]=='(' or aa[i+1]==')')
				{
					if(jl<k)
					{
						num=num-jl;
					}
					jl=0;
				}
			}
		}
		if(num==0)
		{
			ans++;
		}
		num=0;
		return ;
	}
	else
	{
		if(aa[x]=='?')
		{
			aa[x]='(';
			dfs(x+1);
			aa[x]='?';
		}
		
		if(aa[x]=='?')
		{
			aa[x]='*';
			dfs(x+1);
			aa[x]='?';
		}
		
		if(aa[x]=='?')
		{
			aa[x]=')';
			dfs(x+1);
			aa[x]='?';
		}
		
		if(aa[x]!='?')
		{
			dfs(x+1);
		}
	}
}



int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>aa;
	dfs(0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
