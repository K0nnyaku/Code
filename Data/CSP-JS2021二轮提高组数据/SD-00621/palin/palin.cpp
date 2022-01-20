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
int t,n,a[1000001],js,flg;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	//cout<<t;
	if(t==1)
	{
		puts("-1");
		return 0;
	}
	while(t--)
	{
		memset(a,0,sizeof(a));
		flg=js=0;
		n=read();
		if(n==1)
		{
			int x(read()),y(read());
			puts("LL");
			continue;
		}
		for(re int i=1;i<=n*2;++i)
		{
			a[i]=read();
		}
		for(re int i=1;i<=2*n;++i)
		{
			if(a[i]!=a[2*n-i+1]) js=1;
		}
		if(js==0)
		{
			for(re int i=1;i<=n*2;++i)
			{
				printf("L");
			}
			puts("");
			continue;
		}
	}
	return 0;
}
/*
5
20
17 3 16 1 9 12 19 6 8 2 20 14 18 10 5 11 15 7 13 4 4 13 7 15 11 5 10 18 17 14 20 2 8 6 19 12 9 1 16 3
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
20
5 20 6 12 13 18 9 17 2 7 7 18 1 11 10 15 4 6 17 19 14 10 14 13 1 16 8 3 12 8 19 20 4 16 5 3 9 2 15 11
1 
1 1
*/
