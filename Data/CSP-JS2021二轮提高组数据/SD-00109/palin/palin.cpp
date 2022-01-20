//CSP2021 rp++ 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<queue>
using namespace std;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+(ch-'0'),ch=getchar();
	return s*w;
}
const int MAXN(1e6+10);
int T,n;
bool c[MAXN];
int ans[MAXN],now[MAXN];
deque<int>a;
deque<int>b;
inline bool check()
{
	int cnt(0);
	for(register deque<int>::iterator it=b.begin();it!=b.end();++it) now[++cnt]=*it;
	int m=n>>1;
	for(register int i=1;i<=m;i++) if(now[i]!=now[n+1-i]) return false;
	return true;
}
inline bool zdx()
{
	for(register int i=1;i<=n;i++)
	{
		if(ans[i]>c[i]) return true;
		else if(ans[i]<c[i]) return false;
	}
}
inline void dfs(int k)
{
	if(k>n)
	{
		if(check()&&zdx()) for(register int i=1;i<=n;i++) ans[i]=c[i];
		return;
	}
	int val=a.front();
	a.pop_front();
	b.push_back(val);
	c[k]=false;
	dfs(k+1);
	b.pop_back();
	a.push_front(val);
	val=a.back();
	a.pop_back();
	b.push_back(val);
	c[k]=true;
	dfs(k+1);
	b.pop_back();
	a.push_back(val);
}
inline void solve()
{
	n=read()<<1;
	if(n>100)
	{
		puts("-1");
		return;
	}
	memset(ans,0x3f,sizeof(ans));
	while(a.size()) a.pop_back();
	while(b.size()) b.pop_back();
	for(register int i=1;i<=n;i++)
	{
		int x=read();
		a.push_back(x);
	} 
	dfs(1);
	if(ans[1]==0x3f3f3f3f) puts("-1");
	else
	{
		for(register int i=1;i<=n;i++)
		{
			if(ans[i]) putchar('R');
			else putchar('L');
		}
	}
	puts("");
	return;
} 
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
