#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m1,m2,cnt,cnt2;
struct kkk
{
	ll st,en;
}a[100005];
kkk b[100005];
ll f[1005][1005],t[100005];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
void work1(int x)
{
	memset(f,0,sizeof(f));
	int men=0;
	for(int i=m1;i>=1;--i)
	for(int j=0;j<=x;++j)
	{
		if(a[i].st>=men)
		{
			
			f[i][j]=max(f[i+1][j],f[i+1][j-1]+1);
			if(f[i][j]==f[i+1][j-1]+1)
			men=a[i].en;
		}
	}
}
void work2(int x)
{
	memset(f,0,sizeof(f));
	int men=0;
	for(int i=m2;i>=1;--i)
	for(int j=0;j<=x;++j)
	{
		if(b[i].st>=men)
		{
			for(int k=1;k<=cnt;++k)
			{
				if(t[k]<=b[i].st)
				{
					cnt2++;
				}
			}
			f[i][j]=max(f[i+1][j+cnt2],f[i+1][j-1+cnt2]+1);
			if(f[i][j]==f[i+1][j-1]+1)
			{
				men=b[i].en;
				cnt2--;
			}
		}
	}
	return ;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	m1=read();
	m2=read();
	for(int i=1;i<=m1;++i)
	{
		a[i].st=read();
		a[i].en=read();
	}
	for(int i=1;i<=m2;++i)
	{
		b[i].st=read();
		b[i].en=read();
	}
	cout<<m1+m2<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
