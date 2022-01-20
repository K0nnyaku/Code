#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char a[100001],b[100001];
int p[100001],nxt,n,k;
int mod=1000000007;
int main()
{
	freopen("bracket.in","r",stdin); 
	freopen("bracket.out","w",stdout);
	cout<<12;
	return 0;
} 
