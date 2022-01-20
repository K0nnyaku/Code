#include<iostream>
#include<cstdio>
#include<stack> 
using namespace std;
int q;
string reads()
{
	string ret;
	char c = getchar();
	while((c!='(')&&(c!=')')&&(c!='*')&&(c!='?'))
	{
		c = getchar();
	}
	while((c=='*')||(c=='(')||(c==')')||(c=='?'))
	{
		if(c == '?')
		{
			q++;
		}
		ret += c;
		c = getchar();
	}
	return ret;
}
int n,k,len,ans=0;
string s;
char c[4] = {'0','(',')','*'};
bool check()
{
	stack<int> st;
	int cnt = 0;
	for(int i = 0;i<len;i++)
	{
		if(s[i] =='(')
		{
			cnt = 0;
			st.push(s[i]);
		}
		if(s[i]==')')
		{
			cnt = 0;
			if(st.empty())
			{
				return 0;
			}
			st.pop();
		}
		if(s[i] =='*')
		{
			
			if(i==0||i==len-1)
			{
				return 0;
			}
			/*
			if((s[i-1]!='*'&&s[i-1]!='(')&&(s[i+1]!='*'&&s[i+1]!=')'))
			{
				int l = i-2;
				int r = i+2;
				bool f = 0;
				int mk1 = 0;int mk2 = 0;
				bool fix1=0,fix2=0;
				while(l>=0&&r<=len-1)
				{
					
					if(s[l]=='('&&s[r]==')')
					{
						f = 1;
						break;
					}
					if(fix1&&fix2)
					{
						f = 1;
						break;
					}
					if(s[l]=='(')
					{
						if(mk1 == 0)
						{
							fix1 = 1;
						}
						mk1--;
					}
					if(s[l]!='(')
					{
						if(s[l]==')')
						{
							mk1++;
						}
						l--;
					}
					if(s[r]==')')
					{
						if(mk2==0)
						{
							fix2 = 1;
						}
						mk2--;
					}
					if(s[r]!=')')
					{
						r++;
					}
				}
				if(f==0)
				{
					return 0;
				}*/
			}
			cnt++;
			if(cnt>k)
			{
				return 0;
			}
		}
	}
	if(!st.empty())
	{
		while(!st.empty())
		{
			st.pop();
		}
		return 0;
	}
	return 1;
}
void work1(int x,int ques)
{
	if(ques==0)
	{
		if(check())
		{
			ans++;
			//cout<<s<<endl;
		}
		return;
	}
	if(s[x]!='?')
	{
		work1(x+1,ques);
		return;
	}
	for(int i = 1;i<=3;i++)
	{
		s[x] = c[i];
		work1(x+1,ques-1);
		s[x] = '?';
	}
}
int main ()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	s = reads();
	len = s.length();
	work1(0,q);
	printf("%d",ans);
	return 0;
}
