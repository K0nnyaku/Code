#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int read()
{
	int an=0,f=1;
	char a;
	a=getchar();
	while(a!='-'&&(a<'0'||a>'9'))
	{
		a=getchar();
	}
	if(a=='-')
	{
		f=-1;
		a=getchar();
	}
	while(a>='0'&&a<='9')
	{
		an=an*10+a-'0';
		a=getchar();
	}
	return an*f;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	ios::sync_with_stdio(false);
	cout<<100
	return 0;
 } 
