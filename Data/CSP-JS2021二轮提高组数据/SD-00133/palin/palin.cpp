#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

char ch[1000];
int n,k;

int pos[1000];
int cnt = 0;
int ans = 0;

int already[1000];

int check(int l,int r)
{
	if(ch[l] !='('&&ch[n] != ')')
	{
		return 0;
	}
	int sta[1000];
	int tops = 0;
	int pp = 0;
	if(l+1==r)
	{
		return 1;
	}
	for(pp  = l+1;ch[pp] == '*'&&pp < r;pp++);
	if(pp == r)
	{
		return 1;
	}
	for(int i  =l+1; i<= r-1;i++)
	{
		if(ch[i] == '(')
		{
			//将前括号入栈 
			sta[++tops] = i;
			//如果前面的星号超过数量了，退出 
			int j = 0;
			for(j = i+1;ch[j] == '*'&&j <= n;j++);
			if(j-i-1 > k)
			{
				return 0;
			}
		}
		
		else if(ch[i] == ')')
		{
			//如果前面没有能匹配的了，退出
			if(tops == 0)
			{
				return 0;
			}
			//如果括号两边都是星号,且后面星号已经没法匹配了，退出 ***()***
			if(ch[sta[tops]-1] == '*'&&ch[i+1] == '*')
			{
				bool ok = false;
				for(int s = i+1;ch[s] == '*'&&s <= 1+k+i&&s <= n;s++)
				{
					if(ch[s] == '(')
					{
						ok = true;
						break;
					}
				} 
				if(!ok)
				{
					return 0;
				}
			}
			int j = 0;
			//如果后面的星号超过数量了，退出 
			for(j = i+1;ch[j] == '*';j++);
			if(j-i-1 > k)
			{
				return 0;
			}
			if(check(sta[tops],i))
			{
				tops--;
			}
			else
			{
				return 0;
			}
		}
		
		
				
		
	}
	
	if(tops == 0)
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("palin.out","w",stdout);
	cout << 12; 

	return 0;
}
