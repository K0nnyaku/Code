#include<bits/stdc++.h>
using namespace std;
bool check(string x)
{
	int len=x.size();
	for(int i=1;len-i-1>=i;i++)
	{
		if(x[i]!=x[len-i-1])
			return false;
	}
	return true;
}
string an;
bool dfs(string a,string b,string c)
{
	if(a.empty())
	{
		if(check(c))
		{
			an=b;
			return true;
		}
		else
			return false;
	}
	string c1=c,c2=c,c3,c4;
	char x=a[0],y=a[a.size()-1];
	c1=c+x,c2=c+y;
	for(int i=1;i<a.size();i++)
		c3+=a[i];
	bool mx1=dfs(c3,b+'L',c1);
	if(mx1)
		return true;
	for(int i=0;i<a.size()-1;i++)
		c4+=a[i];
	bool mx2=dfs(c4,b+'R',c2);
	if(mx2)
		return true;
	return false;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;cin>>t;
	while(t--)
	{
		an.clear();
		int n,c;cin>>n;
		n*=2;
		string x;
		for(int i=1;i<=n;i++)
		{
			cin>>c;
			x+=c+'0';
		}
		string b;b.clear();
		string b2;b2.clear();
		bool mx3=dfs(x,b,b2);
		if(mx3)
			cout<<an<<"\n";
		else
			cout<<-1<<"\n";
	}
	return 0;
}
