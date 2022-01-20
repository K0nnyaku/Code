#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>

const int N=1e5+5;

using namespace std;

int n,m[2],ans[2][N],tre[2][N<<2];

struct node{
	int l,r;
}a[2][N];

inline int read()
{
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))
		ch=getchar();
	while(isdigit(ch))
		x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}

inline bool cmp(const node &a,const node &b)
{
	return a.l<b.l;
}

void fin(int t,int l,int r,int step,int ll,int rr)
{
	if(l==r)
	{
		if(tre[step][t]<=ll)
		{
			tre[step][t]=rr;//线段树下标与其他数组不一样** 
			ans[step][l]++;
		} 
		return;
	}
	int ls=t<<1,rs=(t<<1)|1,mid=l+r>>1;
	if(tre[step][ls]<=ll)
		fin(ls,l,mid,step,ll,rr);
	else
	{
		if(tre[step][rs]<=ll)
			fin(rs,mid+1,r,step,ll,rr);
		else
			return;
	}
	tre[step][t]=tre[step][ls]<tre[step][rs]?tre[step][ls]:tre[step][rs];
}

inline void qiuans(int step)
{
	sort(a[step]+1,a[step]+1+m[step],cmp);
	for(int i=1;i<=m[step];++i)
	{
		fin(1,1,n,step,a[step][i].l,a[step][i].r);
	}
	for(int i=2;i<=n;++i)
		ans[step][i]+=ans[step][i-1];
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m[0]=read();m[1]=read();
	for(int i=1;i<=m[0];++i)
		a[0][i].l=read(),a[0][i].r=read();
	for(int i=1;i<=m[1];++i)
		a[1][i].l=read(),a[1][i].r=read();
	qiuans(0);
	qiuans(1);
	int maans=0;
	for(int i=0;i<=n;++i)
	{
		maans=maans<ans[0][i]+ans[1][n-i]?ans[0][i]+ans[1][n-i]:maans; 
	}
	cout<<maans;
	return 0;
}
