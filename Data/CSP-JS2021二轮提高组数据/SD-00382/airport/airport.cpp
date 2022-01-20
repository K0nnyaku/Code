#include<bits/stdc++.h>
#define N 100005
using namespace std;

char buf[1<<23],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<23,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
	int res=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		res=(res<<1)+(res<<3)+ch-'0';
		ch=getchar();
	}
	return f?-res:res;
}

struct node{
	int l,r;
}m_1[N],m_2[N];

int ans,cnt,ml[N],Ml[N],can[2][N];
int dp[2][N],tong[2][N];

bool cmp(node x,node y)
{
	return x.l<y.l;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n=read(),m=read(),M=read();
	for(int i=1;i<=m;i++)
	{
		m_1[i].l=read();
		m_1[i].r=read();
	}
	for(int i=1;i<=M;i++)
	{
		m_2[i].l=read();
		m_2[i].r=read();
	}
	sort(m_1+1,m_1+m+1,cmp);
	sort(m_2+1,m_2+M+1,cmp);
	for(int i=1;i<=m;i++) ml[i]=m_1[i].l;
	for(int i=1;i<=M;i++) Ml[i]=m_2[i].l;
	int tot=0;
	for(int i=1;i<=m;i++)
	{
		if(can[0][i]||tot==n) continue;
		tot++;
		int k=i;
		while(k<=m)
		{
			can[0][k]=tot;
			tong[0][tot]++;
			int tmp = lower_bound(ml+k+1,ml+m+1,m_1[k].r)-ml;
			while(can[0][tmp]) tmp++;
			k=tmp;
		}
	}
	tot=0;
	for(int i=1;i<=M;i++)
	{
		if(can[1][i]|tot==n) continue;
		tot++;
		int k=i;
		while(k<=M)
		{
			can[1][k]=tot;
			tong[1][tot]++;
			int tmp=lower_bound(Ml+k+1,Ml+M+1,m_2[k].r)-Ml;
			while(can[1][tmp]) tmp++;
			k=tmp;
		}
	}
	for(int i=1;i<=n;i++)
	{
		dp[0][i]=dp[0][i-1]+tong[0][i];
		dp[1][i]=dp[1][i-1]+tong[1][i];
	}
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,dp[0][i]+dp[1][n-i]);
	}
	printf("%d\n",ans);
	return 0;
}
