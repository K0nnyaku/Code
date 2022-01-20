#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,a[10005];

inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar(); }
	while(c>='0'&&c<='9'){ x=(x<<1)+(x<<3)+(c^48); c=getchar(); }
	return x*f;
}

int main()
{
//	freopen("traffic.in","r",stdin);
//	freopen("traffic.out","w",stdout);
	n=read();
	return 0;
	fclose(stdin);
	fclose(stdout);
}


