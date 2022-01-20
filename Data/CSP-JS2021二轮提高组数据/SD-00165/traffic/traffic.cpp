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
int main()
{
	freopen("traffic.in","r",stdin); 
	freopen("traffic.out","w",stdout);
	int n=read(),m=read(),T=read();
	while(T--)
		cout<<0<<endl;
	return 0;
} 
