#include<iostream>
#include<cstdio>
#include<stack>
#include<map>
#define ull unsigned long long 
using namespace std;
string s;
stack<char> stk;
map<string,int> m;
int n,k,c1=0,c2=0,flag=0;
ull ans=0;
bool check(string s)
{
	while(stk.size()) stk.pop();
	flag=0,c1=0,c2=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='*') 
		{
			c1++;
			stk.push('*');
			if(c1>k) return 0;
		}
		if(s[i]=='(') 
		{
			stk.push('(');
			c1=0;c2++;		
		}
		if(s[i]==')')
		{
			c1=0;
			flag=0;
			while(stk.size())
			{
				char ch=stk.top();stk.pop();
				if(ch=='(')
				{
					if(stk.size()&&s[i+1]=='*')
					{
						if(stk.top()=='*')
							return 0;
					}
					else 
					{
						flag=1;c2--;break;
					}
				}
			}
			if(flag==0||c2<0) return 0;
		} 		
	}
	if(c2)return 0;
	return 1;	
}
void solve(string s,int st)
{
	for(int i=st;i<n;i++)
	{
		if(s[i]=='?')
		{
			s[i]='*';solve(s,i+1);
			s[i]='(';solve(s,i+1);
			s[i]=')';solve(s,i+1);
		}
		if(i==n-1)
		{
			if(m[s]==0)
			{
				m[s]=1;
				if(check(s)) 
				{
					//cout<<s<<endl;
					ans++;
				}
			}
			
		}
	}
} 
int main()
{
    freopen("bracket.in","r",stdin);
    freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	if(s[0]=='?') s[0]='(';if(s[n-1]=='?') s[n-1]=')';
	if(s[0]!='('||s[n-1]!=')')
	{
		cout<<-1<<endl;
		return 0;
	}
	if(n<=15) 
	{
		solve(s,0);
		cout<<ans<<endl;
	}
	else cout<<"-1"<<endl; 
	fclose(stdin);fclose(stdout);
	return 0;
}


