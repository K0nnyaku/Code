#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int read()
{
	int x=0,f=1;
	char c;
	c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main()
{
	//freopen("palin.in","r",stdin);
	//freopen("palin.out","w",stdout);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
