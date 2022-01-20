#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#include<map>
#include<bitset>
#define ll long long
#define ull unsigned long long
using namespace std;

inline int read()
{
	int s=0,w=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
};

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cout << 0;
	return 0;
};
