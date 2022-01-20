#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iomanip>
using namespace std;
int n,k;
string s;
int search(int i)
{
	if(s[i]=='?')
	{
		for(int j=1;j<=3;j++)
		{
			if(j==1)
			{
				s[i]='(';
				if(i==s.length()-1)
				{
					int sum=0,f=1;
					for(int j=0;j<s.length();j++)
					{
						if(s[j]=='*')
						{
							for(int w=j+1;w<s.length();w++)
							{
								if(s[w]=='*')
								{
									sum++;
								}
								else
								{
									break;
								}
							}
							if(sum>k)
							{
								f=0;
								break;
							}
						}
					}
					if(f==1)
					{
						
					}
				}
				else search(i+1);
			}
			if(j==2)
			{
				s[i]=')';
				if(i==s.length()-1)
				{
					cout<<s<<endl;
				}
				else search(i+1);
			}
			if(j==3)
			{
				s[i]='*';
				if(i==s.length()-1)
				{
					cout<<s<<endl;
				}
				else search(i+1);
			}
			s[i]='?';
		}
	}
	else search(i+1);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	//search(0);
	cout<<"1";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
