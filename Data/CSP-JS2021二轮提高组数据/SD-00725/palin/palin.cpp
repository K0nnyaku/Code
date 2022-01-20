#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAXN 1000010
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define FUP(i,x,y) for(int i=(x);i<=(y);i++)
#define FDW(i,x,y) for(int i=(x);i>=(y);i--)
#define FED(i,x) for(int i=head[x];i;i=ed[i].nxt)
#define pr pair<int,int>
#define mkp(a,b) make_pair(a,b)
#define ll long long
#define db double
using namespace std;
int read()
{
	int w=0,flg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){flg=-1;}ch=getchar();}
	while(ch<='9'&&ch>='0'){w=w*10-'0'+ch,ch=getchar();}
	return w*flg;
}
const bool is_print=0;
int n,a[MAXN],mid;
bool ok;
int re[MAXN],pos[MAXN][2];
char ans[MAXN];
void dfs(int l,int r,int cur)
{
	if(ok) return;
	if(cur==n*2-1)
	{
		FUP(i,1,n) if(re[i]!=re[n*2-i+1]) return;
		ok=true;
		printf("%s\n",ans+1);
		return;
	}
	cur++;
	if(is_print)
	{
		FUP(i,1,n*2) printf("%d ",re[i]);puts("");
		FUP(i,1,n*2) printf("%d ",a[i]);puts("");
	}
	if(l==pos[a[l]][1]&&l<mid)
	{
		if(cur>mid&&re[n*2-cur+1]==a[l])
		{
			re[cur]=a[l],ans[cur]='L';
			dfs(l+1,r,cur);
			re[cur]=0;
		}
	}
	if(l==pos[a[l]][0]&&l<mid)
	{
		re[cur]=a[l],ans[cur]='L';
		dfs(l+1,r,cur);
		re[cur]=0;
	}
	if(r==pos[a[r]][0]&&r>mid)
	{
		if(cur>mid&&re[n*2-cur+1]==a[r])
		{
			re[cur]=a[r],ans[cur]='R';
			dfs(l,r-1,cur);
			re[cur]=0;
		}
	}
	if(r==pos[a[r]][1]&&r>mid)
	{
		re[cur]=a[r],ans[cur]='R';
		dfs(l,r-1,cur);
		re[cur]=0;
	}
}
void solve()
{
	n=read();
	FUP(i,1,n<<1) re[i]=pos[i][0]=pos[i][1]=ans[i]=0;
	FUP(i,1,n<<1) a[i]=read();
	FUP(i,1,n<<1)
	{
		if(!pos[a[i]][0]) pos[a[i]][0]=i;
		else pos[a[i]][1]=i;
	}
	ans[n<<1]='L',re[1]=re[n*2]=a[1];
	ans[1]='L',mid=pos[a[1]][1];
	ok=false;
	dfs(2,n*2,1);
	if(ok) return;
	if(is_print) puts("111");
	ok=false;
	ans[1]='R',mid=pos[a[n*2]][0],re[1]=re[n*2]=a[n*2];
	dfs(1,n*2-1,1);
	if(ok) return;
	puts("-1"); 
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=read();
	while(T--) solve();
	return 0;
}
