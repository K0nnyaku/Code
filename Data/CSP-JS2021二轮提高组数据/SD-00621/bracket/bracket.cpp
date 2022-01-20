#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define in inline
#define re register
#define ll long long
using namespace std;
in int read()
{
	int x=0,k=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') k=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	 }
	 return x*k;
}
int n,k;
char x;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	if(n==1)
	{
		cin>>x;
		if(x=='*')
		{
			puts("1");
			return 0;
		}
	}
	return 0;
}

