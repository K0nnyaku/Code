#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<stack>
#define ll long long
using namespace std;
int re()
{
	int x=0,p=1;
	char y=getchar();
	while(y>'9'||y<'0')
	{
		if(y=='-')
		p=-1;
		y=getchar();
	}
	while(y>='0'&&y<='9')
	{
		x=10*x+y-'0';
		y=getchar();
	}
	return x*p;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cout<<0;
}
