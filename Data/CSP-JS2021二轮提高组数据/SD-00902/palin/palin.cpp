#include<cstdio>
#define il inline
using namespace std;

const int maxn=1e6+1;
bool F;
char opt[maxn];
int n;
int a[maxn],b[maxn];

il int read()
{
	int num=0; bool flag=1; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') flag=1; c=getchar();}
	while(c>='0'&&c<='9') num=(num<<1)+(num<<3)+(c^48), c=getchar();
	return flag?num:-num;
}

il bool pd1()
{
	int i;
	for(i=1;i<=n/2;i++)
		if(a[i]!=a[n+1-i])
			return 0;
	return 1;
}

il bool pd2()
{
	int i;
	for(i=1;i<=n/2;i++)
		if(b[i]!=b[n+1-i])
			return 0;
	return 1;
}

il void dfs(int ha,int ta,int cur)
{
	if(F)
		return;
	if(cur>n-1)
	{
		if(pd2())
			F=1;
		return;
	}
	
	b[cur+1]=a[ha];
	opt[cur]='L';
	dfs(ha+1,ta,cur+1);
	if(F)
		return;
	b[cur+1]=a[ta];
	opt[cur]='R';
	dfs(ha,ta-1,cur+1);
	
	return;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	int T=read();
	int i;
	
	while(T--)
	{
		F=0;
		
		n=read();
		n*=2;
		
		for(i=1;i<=n;i++)
			a[i]=read();
		
		if(pd1())
		{
			for(i=1;i<=n;i++)
				printf("L");
			printf("\n");
			continue;
		}
		dfs(1,n,0);
		
		if(F)
			printf("%s\n",opt);
		else
			printf("-1\n");
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
