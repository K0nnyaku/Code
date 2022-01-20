#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue> 
#include<cstring>
#include<stack>
using namespace std;
long long int mod=1e9+7,cnt=0;
int n,k;
string s;
char a[505];
struct node
{
	int num;
	char ki;
} ;
stack<node>q; 
bool check()
{
	while(!q.empty())
		q.pop();
	int i,cnt=0;
	if(a[1]!='('||a[n]!=')')
		return 0;
	for(i=1;i<=n;i++)
	{
		if(a[i]=='*')
			cnt++;
		if(a[i]!='*')
		{
			if(cnt>k)
				return 0;
			cnt=0;
		}
	}
	node out;
	for(i=1;i<=n;i++)
	{
		if(a[i]=='(')
		{
			out.ki='(';out.num=i;
			//cout<<out.num<<endl;
			q.push(out);
		}
		else if(a[i]==')')
		{
			if(q.empty())
				return 0;
			out=q.top();
			//cout<<a[out.num+1]<<" "<<a[i-1]<<endl;
			if(a[out.num+1]=='*'&&a[i-1]=='*')
			{
				for(int j=out.num+1;j<=i-1;j++)
					if(a[j]=='('||a[j]==')')
						return 0; 
			}
			q.pop();
		}
	}
	if(!q.empty())
		return 0;
	//for(i=1;i<=n;i++)
	//	putchar(a[i]);
	//puts(""); 
	return 1;
}
void dfs(int num)
{
	//cout<<num<<endl;
	if(num==n)
	{
		if(check())
			cnt++;
		if(cnt>=mod);
			cnt=cnt%mod; 
		return ;
	}
	if(s[num]=='*'||s[num]=='('||s[num]==')')
	{
		a[num+1]=s[num]; 
		dfs(num+1);
	}
	else
	{
		a[num+1]='(';
		dfs(num+1);
		a[num+1]=')';
		dfs(num+1);
		a[num+1]='*';
		dfs(num+1);
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	long long int sum;
	int i,j,d;
	cin>>n>>k;
	cin>>s;
	dfs(0);
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
