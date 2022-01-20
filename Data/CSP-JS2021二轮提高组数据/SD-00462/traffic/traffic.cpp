#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long long read()
{
	long long ans=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		ans=(ans<<1)+(ans<<3)+(c^48);
		c=getchar();
	}
	return ans*f;
}
int main()
{
//	freopen("traffic.in","r",stdin);
//	freopen("traffic.out","w",stdout); 
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
