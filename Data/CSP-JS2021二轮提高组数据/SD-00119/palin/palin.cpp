#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1000005;
int t,n,a[MAXN],l;
char s[MAXN];
bool p;
int e[500005];
void dfs(int k,int hed,int tal)
{
	if(k==l)
	{
		p=1;
		for(int i=1;i<=k;++i)
		{
			printf("%c",s[i]);
		}
		printf("\n");
		return;
	}
	if(!(e[a[hed]]&&e[a[hed]]!=l-k))
	{
		s[k+1]='L';
		int x=e[a[hed]];
		e[a[hed]]=k+1;
		dfs(k+1,hed+1,tal);
		e[a[hed]]=x;
	}
	if(p) return;
	if(!(e[a[tal]]&&e[a[tal]]!=l-k))
	{
		s[k+1]='R';
		int x=e[a[tal]];
		e[a[tal]]=k+1;
		dfs(k+1,hed,tal-1);
		e[a[tal]]=x;
	}
	if(p) return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		l=n<<1;
		p=0;
		for(int i=1;i<=l;++i)
		{
			scanf("%d",&a[i]);
		}
		memset(e,0,sizeof(e));
		dfs(0,1,l);
		if(!p) printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
