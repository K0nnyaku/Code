#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
#define ull unsigned long long
#define next nxt

using namespace std;



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
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	
	return 0;
}
