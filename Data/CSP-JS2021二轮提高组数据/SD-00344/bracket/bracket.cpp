#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<queue>
#define maxn 2000006
inline int read()
{
	int f=1,s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=(s<<1)+(s<<3)+(ch^48);
		ch=getchar();
	}
	return s*f;
}
using namespace std;
char a[300000];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k;
	n=read();
	//k=read();
	cin>>n;
	cout<<n++;
	return 0;
}
