#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstring>
#include<queue>

using namespace std;
inline int re()
{
	int x=0,y=1;char c=getchar();
	while(c>'9'||c<'0')
	{if(c=='-') y=-1;c=getchar();}
	while(c>='0'&&c<='9')
	x=x*10+(c^48),c=getchar();
	return x*y;
}
int T,n;
int a[20005],b[20005],c[20005];
int cnt=0;
int tnc;
int gg=0;
void d(int s)
{
	if(s>2*n)
	{
		int vis=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]!=b[2*n-i+1])
			vis=1;
		}
		if(vis==0)
		{
		for(int i=1;i<=2*n;i++)
		if(c[i]==1) cout<<"L";
		else cout<<"R";
		cout<<endl;gg=1;
		}return ;
	}
	b[2*n+1-s]=a[++cnt];c[s]=1;
	d(++s);if(gg==1) return;s--;cnt--;
	b[2*n+1-s]=a[--tnc];c[s]=2;
	d(++s);if(gg==1) return;s--;tnc++;
	return;
}
signed main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=re();
	while(T--)
	{
		n=re();
		for(int i=1;i<=2*n;i++)
		{
			a[i]=0;
			b[i]=0;
			c[i]=0;
		}
		gg=0;
		for(int i=1;i<=n*2;i++)
		a[i]=re();
		tnc=2*n+1;
		d(1);
		if(gg==0)
		cout<<"-1"<<endl;
	}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/

