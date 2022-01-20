#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<vector>
#include<bitset>
using namespace std;
#define re register
#define mod 1000000007
#define inf 0x7f7f7f7f
#define maxn 150
#define int long long
inline int read();
inline void wn(int x);
inline void wr(int x);
inline void wi(int x);
int t;
int n,a[maxn];
vector<int>v;
int l,r;
int b[maxn];
int p=0;
void dfs(int x)
{
	if(p)	return ;
	if(x==(n+n+1))
	{
		int ll=1,rr=n+n;
		memset(b,0,sizeof b);
		int t=0;
		for(re int i=0;i<n+n;++i)
		{
			if(v[i]==0)	b[++t]=a[ll++];
			else
				b[++t]=a[rr--];
		}
		for(re int i=1;i<=n;++i)
		{
			if(b[i]!=b[n+n+1-i])	return ;
		}
		p=1;
		for(re int i=0;i<n+n;++i)
			if(v[i]==0)	putchar('L');
			else	putchar('R');
		puts("");
		return ;
	}
	v.push_back(0);
//	if(x<=n&&amo[a[l]]>=1)	return ;
//	amo[a[l]]++,l++; 
	dfs(x+1);
//	l--,amo[a[l]]--;
	v.pop_back();
	v.push_back(1);
//	if(x<=n&&amo[a[r]]>=1)	return ;
//	amo[a[r]]++,r--;
	dfs(x+1);
//	r--,amo[a[r]]--;
	v.pop_back();
	
}
signed main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
//	printf("%d M",((sizeof(edge)>>20)));
	t=read();
	while(t--)
	{
		n=read();
		p=0;
		for(re int i=1;i<=n+n;++i)	a[i]=read();
		dfs(1);
		if(!p)	wr(-1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//======================================================
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void wn(int x)
{
	if(x<0)
	{
		putchar('-');
		wn(-x);
		return ;
	}
	if(x>=10)	wn(x/10);
	putchar(x%10+'0');
}
inline void wr(int x)
{
	wn(x);
	putchar('\n');
}
inline void wi(int x)
{
	wn(x);
	putchar(' ');
}

