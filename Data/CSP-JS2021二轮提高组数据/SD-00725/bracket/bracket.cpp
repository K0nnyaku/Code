#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAXN 100010
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
int n,K;
int sta[MAXN],tpf,ans;
char s[MAXN];
void dfs(int cur,int len,bool have)
{
	if(cur==n)
	{
			if(is_print) printf("%s\n",s+1);
		if(!len&&!tpf&&s[1]!='*'&&s[n]!='*')
		{
			if(is_print) puts("!!!");
			ans++;
		}
		return;
	}
	cur++;
	if(is_print) printf("cur=%d tpf=%d have=%d %s\n",cur,tpf,have,s+1);
	if(s[cur]=='(')
	{
		sta[++tpf]=cur;
		dfs(cur,0,0);
		tpf--;
		return;
	}
	else if(s[cur]==')')
	{
		if(!tpf) return;
		if(s[sta[tpf]+1]=='*'&&s[cur-1]=='*'&&have) return;
		int w=sta[tpf];
		tpf--;
		dfs(cur,0,have|1);
		sta[++tpf]=w;
	}
	else if(s[cur]=='*')
	{
		if(len==K) return;
		if(is_print) printf("* cur=%d\n",cur);
		dfs(cur,len+1,have);
	}
	else
	{
		sta[++tpf]=cur,s[cur]='(';
		dfs(cur,0,0);
		tpf--,s[cur]='?';
		if(is_print) printf("? cur=%d tpf=%d len=%d have=%d %s\n",cur,tpf,len,have,s+1);
		if(tpf&&!(s[sta[tpf]+1]=='*'&&s[cur-1]=='*'&&have))
		{
			int w=sta[tpf];
			s[cur]=')',tpf--;
			dfs(cur,0,have|1);
			sta[++tpf]=w,s[cur]='?';
		}
		if(len<K)
		{
			s[cur]='*';
			dfs(cur,len+1,have);
			s[cur]='?';
		}
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),K=read();
	scanf("%s",s+1);
	dfs(0,0,0);
	printf("%d\n",ans);
	return 0;
}
