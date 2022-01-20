#include<bits/stdc++.h>
#define maxn 520
using namespace std;
int n,m,t,cnt,ans;
int a[maxn];
bool pd[maxn];
void dfs(int x)
{
	//cout<<x;
	if(x==cnt)
	{
		bool pd=0;
		int ln=0,rn=0,tot=0;
		for(int i=0;i<t;i++)
		{
			if(a[i]==1)ln++;
			if(a[i]==2)tot++;
			else
		    {
				rn++;
				tot=0;				
			}
			//if(tot>m)return ;
			if(tot>m)pd=1;
		}
		//if(ln!=rn) return ;
		if(!pd&&ln!=rn)ans++;
		return ;
	}
	for(int i=0;i<t;i++)
	{
		if(!a[i])
		{
			for(int i=1;i<=3;i++)
			{
				a[i]=i;
				dfs(x+1);
			}
		}
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	string s;
	cin>>n>>m;
	cin>>s;
	t=s.size();
	if(s[0]=='*'||s[t-1]=='*')
	{
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')a[i]=1;
		else if(s[i]=='*')a[i]=2;
		else if(s[i]==')')a[i]=3;
		else cnt++;
	} 
	dfs(0);
	fclose(stdin);
	fclose(stdout);
	cout<<ans;
	return 0;
 }
/*
7 3
(*??*??
*/
