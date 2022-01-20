#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int st[1000001];
int stp[10001];
int b[10001];
int bi=0;
int ha=0;
void dfs(int l,int r)
{
	if(ha)
	{
		return ;
	}
	if(l>r)
	{
		if(ha)
		{
			return ;
		}
		int fg=0;
		for(int i=1;i<=2*n;i++)
		{
			if(b[i]!=b[2*n-i+1])
			{
				fg=1;
				break;
			}
		}
		if(!fg)
		{
			for(int i=1;i<=2*n;i++)
			{
				if(stp[i]==0)
				{
					cout<<"L";
				}
				else
				{
					cout<<"R";
				}
			}
			ha=1;
			return;
		}
		return ;
	}
	bi++;
	b[bi]=st[l];
	stp[bi]=0;
	dfs(l+1,r);
	b[bi]=st[r];
	stp[bi]=1;
	if(ha)
	{
		return ;
	}
	dfs(l,r-1);
	
	bi--;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=2*n;i++)
		{
			cin>>st[i];
		}
		bi=0;
		ha=0;
		dfs(1,2*n);
		if(!ha)
		{
			cout<<-1;
		}
		cout<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
