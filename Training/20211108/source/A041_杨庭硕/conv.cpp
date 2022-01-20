#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=2e5+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;	
}
int a[MAXN],b[MAXN],n,c[MAXN];
int main()
{
	freopen("conv.in","r",stdin);
	freopen("conv.out","w",stdout);
	n=read();
	for(int i=0;i<n;i++) a[i]=read();
	for(int i=0;i<n;i++) b[i]=read();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			c[i]=max(a[j]+b[(i-j+n)%n],c[i]);
		}
		cout<<c[i]<<' ';
	}
	return 0;
}
