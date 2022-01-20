#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define ll long long
using namespace std;
bool check(int x[105],int p)
{
	for(int i=1;i<=p;i++)
	{
		if(x[i]!=x[p-i+1])
		{
			return 0;
		}
	}
	return 1;
}
int dfs(deque<int> q,int na[105],int p,string ans)
{
	if(q.empty())
	{
		if(check(na,p))
		{
			cout<<ans<<endl;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	deque<int> a=q,b=q;
	int nb[105],nc[105];copy(na,na+104,nb),copy(na,na+104,nc);
	nb[p+1]=a.back();nc[p+1]=a.front();
	string a1=ans,a2=ans;a1+='L',a2+='R';
	a.pop_back(),b.pop_front();
	if(dfs(b,nc,p+1,a1))return 1;
	if(dfs(a,nb,p+1,a2))return 1;
	return 0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,an[105];
		deque<int> q;
		cin>>n;
		for(int i=1;i<=n*2;i++)
		{
			int x;
			cin>>x;
			q.push_back(x);
		}
		if(!dfs(q,an,0,""))
		{
			cout<<-1<<endl;
		}
	}
	return 0;
}
