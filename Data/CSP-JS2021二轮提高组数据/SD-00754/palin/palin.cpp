#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
#define ull unsigned long long
#define next nxt

using namespace std;

int t,n,a[1000100],book;

template<typename type>
inline void read(type &x)
{
	x=0;bool flag(0);char ch=getchar();
	while(!isdigit(ch)) flag^=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	flag?x=-x:0;
}

template<typename type>
inline void write(type x,bool mode)
{
	x<0?x=-x,putchar('-'):0;static short Stack[50],top(0);
	do Stack[++top]=x%10,x/=10;while(x);
	while(top) putchar(Stack[top--]|48);
	mode?putchar('\n'):putchar(' '); 
}

signed main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	read(t);
	while(t--)
	{
		read(n);
		memset(a,0,sizeof(a));
		book=0;
		n<<=1;
		for(int i=1;i<=n;i++) read(a[i]);
		n>>=1;
		for(int t1=1,t2=n<<1;t1<t2;t1++,t2--)
		{
			if(a[t1]!=a[t2])
			{
				printf("%s\n","-1");
				book=1;
				break;
			}
		}
		if(book) continue;
		n<<=1;
		for(int i=1;i<=n;i++) putchar('L');
		putchar('\n');
	}
	return 0;
}
/*
1 2 2 4 3 3 4 1
no

1 4 3 2 2 3 4 1


1 1 2 3 4 4 3 5 5 2


*/ 
