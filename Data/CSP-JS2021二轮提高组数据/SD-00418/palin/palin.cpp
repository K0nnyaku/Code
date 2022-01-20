#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<stack>

using namespace std;

int T;
int n;
int a[1000001];

stack<int> dtc,ptc;

deque<int> btc;

bool possible()
{
	while(!btc.empty())btc.pop_front();
	for(int i=1;i<=2*n;i++)
	{
		if(btc.empty()||(!btc.empty()&&a[i]!=btc.front()))
		{
			btc.push_back(a[i]);
		}
		else btc.pop_front();
		while(btc.size()>=2&&btc.front()==btc.back())
		{
			btc.pop_front();
			btc.pop_back();
		}
	}
	if(btc.empty())return true;
	return false;
}

bool strcmp(string x,string y)
{
	for(int i=0;i<x.length();i++)
	{
		if(x[i]=='L'&&y[i]=='R')return false;
		if(x[i]=='R'&&y[i]=='L')return true;
	}
}

string dfs(int l,int r,int type)
{
	string poura,pourb;
	if(l==r)
	{
		int x;bool flag;
		while(!ptc.empty())ptc.pop();
		while(!dtc.empty())
		{
			x=dtc.top();
			dtc.pop();
			if(!dtc.empty()&&x==dtc.top())
			{
				ptc.push(x);
				dtc.pop();
			}
			else
			{
				dtc.push(x);
				break;
			}
		}
		if(dtc.size()<=1)flag=true;
		else flag=false;
		while(!ptc.empty())
		{
			dtc.push(ptc.top());dtc.push(ptc.top());
			ptc.pop();
		}
		if(flag)
		{
			if(type==0)return "L";
			if(type==1)return "R";
		}
		else return "P";
	}
	if(dtc.empty()||(!dtc.empty()&&a[l]!=dtc.top()))
	{
		dtc.push(a[l]);
		poura=dfs(l+1,r,0);
		dtc.pop();
	}
	else
	{
		dtc.pop();
		poura=dfs(l+1,r,0);
		dtc.push(a[l]);
	}
	if(dtc.empty()||(!dtc.empty()&&a[r]!=dtc.top()))
	{
		dtc.push(a[r]);
		pourb=dfs(l,r-1,1);
		dtc.pop();
	}
	else
	{
		dtc.pop();
		pourb=dfs(l,r-1,1);
		dtc.push(a[r]);
	}
	if(poura=="P"&&pourb=="P")return "P";
	if(poura=="P")return "R"+pourb;
	if(pourb=="P")return "L"+poura;
	return "L"+poura;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	for(int ijk=1;ijk<=T;ijk++)
	{
		cin>>n;
		for(int i=1;i<=2*n;i++)
		{
			cin>>a[i];
		}
		if(!possible())cout<<"-1"<<endl;
		else
		{
			while(!dtc.empty())dtc.pop();
			cout<<dfs(1,2*n,-1)<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
