#include<stack>
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int len,n,k,pd,sum,G,pd_spc,spc_one,spc_two;
bool flag=0;
stack <char> T1;
stack <char> T2;
stack <char> T_1;
string s;
bool PDD()
{
	for(int j=0;j<len;j++)
	{
		if(s[j]=='*')
		{
			pd++;
			if(pd>k)
			{
				while(!T1.empty())
					T1.pop();
				pd=0;
				return 0;
			}	
		}
		else if(s[j]=='(')
		{
			T1.push(s[j]);
			pd=0;
		} 
		else if(s[j]==')')
		{
			if(!T1.empty())  //·Ç¿Õ 
			{
				T1.pop();
				pd=0;
			} 
			else
			{
				pd=0;
				return 0;
			}
		}
	}
	if(T1.empty()&&pd==0) 
	{
		for(int i=0;i<len;i++)
			if(s[i]=='*')
			{
				spc_one=i;
				break;
			}
		for(int i=len-1;i>=0;i--)
			if(s[i]=='*')
			{
				spc_two=i;
				break;
			}
		for(int i=spc_one;i<len;i++)
			if(s[i]!='*')
			{
				spc_one=i;
				break;
			}
		for(int i=spc_two;i>=0;i--)
			if(s[i]!='*')
			{
				spc_two=i;
				break;
			}
		bool flag=1;
		for(int i=spc_one;i<=spc_two;i++)
		{
			if(s[i]=='*')
			{
				pd++;
				if(pd>k)
				{
					while(!T_1.empty())
						T_1.pop();
					pd=0;
					flag=0;
				}
			}
			else if(s[i]=='(')
			{
				T_1.push(s[i]);
				pd=0;
			} 
			else if(s[i]==')')
			{
				if(!T_1.empty())  //·Ç¿Õ 
				{
					T_1.pop();
					pd=0;
				} 
				else
				{
					pd=0;
					flag=0;
				}
			}
		}
		if(flag)
		{
			if(T_1.empty()&&pd==0)
				return 0;
			else
			{
				while(!T_1.empty())
					T_1.pop();
				//sum++;
				return 1;
			}
		}
		else
		{
			//sum++;
			return 1;
		}
	}
	else
	{
		while(!T_1.empty())
			T_1.pop();
		return 1;
	}
	return 0;
}
void dfs(int sit,int nums)
{
	if(nums==G)
	{
		if(PDD())
			sum++;
		return;
	}
	else if(s[sit]=='?')
	{
		for(int k=1;k<=3;k++)
		{
			if(k==1)
			{
				s[sit]='(';
				dfs(sit+1,nums+1);
				s[sit]='?';
			}
			else if(k==2)
			{
				s[sit]='*';
				dfs(sit+1,nums+1);
				s[sit]='?';
			}
			else if(k==3)
			{
				s[sit]=')';
				dfs(sit+1,nums+1);
				s[sit]='?';
			}
		}
	}
	else if(s[sit]=='('||s[sit]==')'||s[sit]=='*')
	{
		dfs(sit+1,nums);
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.ans","w",stdout);
	scanf("%d %d",&n,&k);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]=='?')
			G++;
	dfs(0,0);
	printf("%d",sum); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
