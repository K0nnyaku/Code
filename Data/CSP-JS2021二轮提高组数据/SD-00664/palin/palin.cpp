#include<bits/stdc++.h>
using namespace std;
const int mx=500010;
int a[mx],b[mx];
char s[mx];
int t,n;
inline int read()
{
	int x=0,y=1;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*y;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		int l=1,r=2*n,ll=1;
		for(int i=1;i<=2*n;++i)
		a[i]=read();
		while(l<=r)
		{
			if(ll<=n)
			{
				
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
