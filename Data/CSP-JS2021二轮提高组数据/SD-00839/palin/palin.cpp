#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
typedef unsigned long long ULL;
typedef long long LL;
typedef double DB;
using namespace std;
inline int read()
{
	int s=0;bool w=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') w=1; ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+(ch^48); ch=getchar();}
	return w ? ~s+1 : s;
}
const int maxn=500005;
int dq[maxn<<2],head,tail,n;
int tmp[maxn<<1],ans[maxn<<2],endpos;
bool book[maxn];
bool check(int dep)
{
	if(head>tail) return true;
	if(dq[head]==tmp[n-dep])
	{
		ans[++endpos]=-1;
		head++;
		if(check(dep+1)) return true;
		ans[endpos--]=0;
		head--;
	}
	else if(dq[tail]==tmp[n-dep])
	{
		ans[++endpos]=1;
		tail--;
		if(check(dep+1)) return true;
		ans[endpos--]=0;
		tail++;
	}
	return false;
}
bool dfs(int dep)
{
	if(dep==n+1)
	{
		return check(0);
	}
	if(!book[dq[head]])
	{
		book[dq[head]]=true;
		tmp[dep]=dq[head];
		ans[++endpos]=-1;
		head++;
		if(dfs(dep+1)) return true;
		ans[endpos--]=0;
		head--;
		book[dq[head]]=false;
	}
	//==========
	if(!book[dq[tail]])
	{
		book[dq[tail]]=true;
		tmp[dep]=dq[tail];
		ans[++endpos]=1;
		tail--;
		if(dfs(dep+1)) return true;
		ans[endpos--]=0;
		tail++;
		book[dq[tail]]=false;
	}
	return false;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read();head=1;tail=n+n;endpos=0;
		for(int i=1;i<=n+n;i++) dq[i]=read();
		memset(book,0,sizeof(book));
		bool resul=dfs(1);
		if(resul){
			for(int i=1;i<=endpos;i++)
			{
				if(ans[i]==-1) printf("L");
				else if(ans[i]==1) printf("R");
			}
		}
		else printf("-1");
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


