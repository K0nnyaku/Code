#include <stack>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int aas=0;
char a[505];
int m,k;
stack<char>s;
void pip(int q)
{
	if(q==m)
	{
		int p=0,shic=0,shicma=0;
			while(p<m)
				{
			if(a[p]=='*'&&a[p+1]=='*')
						{
							shic++;
							if(shicma<=shic)shicma=shic;
						}
			 if(a[p]!=a[p+1])shic=0;
			 if(a[p]=='(')s.push('(');
			 if(a[p]==')'&&!s.empty())s.pop();
			 if(a[p]==')'&&s.empty());
				p++;	
				}	
		if(s.empty()&&shicma<k&&p==m)aas++;
	}



	if(q<m) 
	{	
	if(a[q]=='?')
			{			
				a[q]=')';
				pip(q+1);
				a[q]='?';
				a[q]='(';
				pip(q+1);
				a[q]='?';
				a[q]='*';
				pip(q+1);
				a[q]='?';
			}
	else pip(q+1);
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
	pip(0);
	aas--;
	cout<<aas%1000000007;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
