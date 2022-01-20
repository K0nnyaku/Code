#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<stack>
#include<set>
#include<queue>
#define MAXN 
#define MAXM 
#define INF 0x3f3f3f3f
#define BASE 131
#define ll long long
#define ull unsigned long long
using namespace std;
string zs(string s)
{
	int len=s.length();
	string ret="";
	for(int i=0;i<len;i++)
	{
		if(s[i]=='*')
		{
			while(s[i]=='*'&&i<len)i++;
			ret+="S";
			i--;
		}
		else ret+=s[i];
	}
	return ret;
}
int ckkh(string s)
{
	int zkhs=0;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]=='(')zkhs++;
		else if(s[i]==')')zkhs--;
		if(zkhs<0)return 0;
	}
	return zkhs<0;
}
int check(string s)
{
	int zkhs=0;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]=='(')zkhs++;
		else if(s[i]=='S')
		{
			while(zkhs!=0)
			{
				if(s[i]=='(')zkhs++;
				else if(s[i]==')')zhks--;
				i++;
			}
			i--;
		}
	}
}
int main()
{
	string s="";
	cin>>s;
	cout<<zs(s);
	return 0;
}
