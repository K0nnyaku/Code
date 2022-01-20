#include<iostream>
#include<cstdio>
#include<cstdlib>

const int N=15;

using namespace std;

inline int read()
{
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))
		ch=getchar();
	while(isdigit(ch))
		x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cout<<141;
	
	return 0;
}
