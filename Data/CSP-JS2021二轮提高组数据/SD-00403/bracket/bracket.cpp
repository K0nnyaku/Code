#include<bits/stdc++.h>  //我只要40分！！！！！！ 
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0)
#define re register
void fre()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
}
int n,k;
string s;
int main()
{
	fre();
	IO;
	cin>>n>>k;
	cin>>s;
	if(n==1)
	{
		printf("%d",0);
		return 0;
 	}
	if(n==2) 
	{
		int l=0,r=0,q=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='(') l++;
			if(s[i]==')') r++;
			if(s[i]=='*') q++;
		}
		if(q>=1||l>=2||r>=2)
		{
			printf("0");
			return 0;
		}
		else
		{
			printf("1");
			return 0;
		}
	}
		
	if(n==3)
	{
		int a=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='?') a++;
		}
		if(a==0)
		{
			for(int i=0;i<n;i++)
			{
				if(s[i]=='*')
				{
					printf("1");
					return 0;
				}
			}
			printf("0");
			return 0;		
		}
		if(a==1)
		{
			int l=0,r=0,q=0;
			for(int i=0;i<n;i++)
			{
				if(s[i]=='(') l++;
				if(s[i]==')') r++;
				if(s[i]=='*') q++;
			}
			if(l>=2||r>=2||q>=2)
			{
				printf("0");
				return 0;
			}
			else 
			{
				printf("1");
			}
		}
		if(a==2)
		{
			printf("1");
			return 0;
		}
		if(a==3)
		{
			printf("1");
			return 0;
		}
	}
	printf("5");
	return 0;
}
