#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n,k;
char s[505],st[505];
bool check(int start,int v)
{
	int i,j,num=0;
	if(start==n-1)
	{/*cout<<st<<" 1"<<endl;*/
				return 0;
			}
	for(i=start+1;i<n;i++)
	{
		int bi=0;
		if(s[i]==')'&&num<=k){
			for(j=i-1;j>=0;j--){
				if(s[j]=='('){
					s[j]='0';
					s[i]='0';
					break;
				}
				if(s[j]=='*'&&bi==0)
				{
					bi=1;
				}
				if(s[j]=='0'&&bi==1)
					bi=2;
				if(s[j]=='*'&&bi==2)
				return 0;
			}
			/*if(!strcmp(st,cmp))
			cout<<s<<endl; */if(j==0&&st[j]!='(')
			{/*cout<<st<<" 2"<<endl;*/
				return 0;
			}
			for(j=i-1;j>=0;j--)
			{
				if(s[j]=='0')
				{	
					break;
				}
				s[j]='0';		
			}
			if(i==n-1||v)
			return 1;
			
		}
		if(s[i]=='*'){
			/*if(!strcmp(st,cmp))
			cout<<endl<<s<<endl<<endl;*/
			num++;
			if(num>k)
			{/*cout<<st<<" 3"<<endl;*/
				return 0;
			}		
		}			
	}	
		if(s[i]=='(')
		{
			if(s[i+1]==')')
			{
				s[i]='0';
				s[i+1]='0';
			}
			else if(!check(i,1))//3
			{/*cout<<st<<" 6"<<endl;*/
				return 0;
			}
		}	 
	
	for(i=n-1;i>=0;i--)
	{
		if(s[i]!='0')
		break;
	 } 
	if(i==-1)
	return 1;
	else
	{
		/*cout<<st<<" 7"<<endl;*/return 0;
	}
		
}
int dfs(int start,int ans)
{
	int i,j,num=0,a=0;
	for(i=start;i<n;i++)
	{
		if(s[i]=='*')
			num++;
		if(s[i]=='('||s[i]==')')
		num=0;
		if(s[i]=='?')
		{
			a=1;
			if(num<k)
			{
				s[i]='*';
				ans+=dfs(i+1,0);
			}
			s[i]='(';
			ans+=dfs(i+1,0);
			s[i]=')';
			ans+=dfs(i+1,0);
			s[i]='?';
		}
	}
	if(a==0)
	{
		if(s[0]!='('||s[0]=='*'){
			return 0;
		}
		if(s[n-1]=='*'||s[n-1]=='(')
		return 0;
		for(i=0;i<n;i++)
		{
			if(s[i]=='?')
			return 0;
		}
		strcpy(st,s);
		int bi=0;
		if(check(0,0)){
			for(j=n-1;j>=0;j--)
			{if(s[j]!='0'&&s[j]!='*')
			break;
				if(s[j]=='*'&&bi==0)
				bi=1;
				if(s[j]=='0'&&bi==1)
				bi=2;
				if(s[j]=='*'&&bi==2)
				break;
			}
			
			if(j<0){
				/*cout<<st<<endl;*/strcpy(s,st);return 1;
			}
			strcpy(s,st);
			return 0;
		}
		strcpy(s,st);
		return 0;
		
	} 
	return ans;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int i,j;
	cin>>n>>k;
	cin>>s;
	cout<<dfs(0,0)<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

