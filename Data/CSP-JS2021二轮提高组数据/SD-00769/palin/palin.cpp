#include<cstdio>
#include<cstring>

int n,l,r,a[50],b[50],tmp[50];
char res[50],ans[50];

bool cmp()
{
	if(!b[1]) return true;
	for(int i=1;i<=(n<<1);++i)
		if(b[i]!=tmp[i]) return tmp[i]<b[i];
	return false;
}

bool is_palin()
{
	for(int i=1;i<=n;++i)
		if(tmp[i]!=tmp[(n<<1|1)-i]) return false;
	return true;
}

void dfs(int u)
{
	if(u==(n<<1|1))
	{
		if(!is_palin()||!cmp()) return;
		for(int i=1;i<=(n<<1);++i)
			b[i]=tmp[i],ans[i]=res[i];
		return;
	}
	tmp[u]=a[l++],res[u]='L',dfs(u+1),--l;
	tmp[u]=a[r--],res[u]='R',dfs(u+1),++r;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	for(scanf("%d",&T);T--;)
	{
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		for(int i=1;i<=(n<<1);++i) scanf("%d",&a[i]);
		l=1,r=(n<<1),dfs(1);
		if(b[1]) 
		{
			for(int i=1;i<=(n<<1);++i) putchar(ans[i]);	
			putchar('\n');
		}
		else puts("-1");		
	}
	return 0;
}
