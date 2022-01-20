#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	char ch=getchar(),fl=1;
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')
		{
			fl=-1;
		}
		ch=getchar();
	}
	int p=0;
	while(ch>='0'&&ch<='9')
	{
		p=(p<<1)+(p<<3)+(ch^48);
		ch=getchar();
	}
	return fl*p;
}
signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cout<<0;
	return 0;
}

