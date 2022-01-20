#include<cstdio>
#include<algorithm>

#define N 2000006

using namespace std;

int read()
{
	char a=getchar();
	int b=0,d=1;
	while(a<'0'||a>'9')
	{
		if(a=='-')
			d*=-1;
		a=getchar();
	}
	while(a>='0'&&a<='9')
		b=(b<<3)+(b<<1)+a-'0',a=getchar();
	return b*d;
}

bool yyy=1;
int t,n,head,tail;
int a[N],b[N],c[N],ans[N];

int check()
{
	for(int i=1;i<=2*n;++i)
		if(b[i]!=b[2*n-i+1])
			return 0;
	for(int i=1;i<=2*n;++i)
		if(ans[1]!=0&&ans[i]<c[i])
			return 0;
	return 1;
}

void print()
{
	for(int i=1;i<=2*n;++i)
		printf("%d ",b[i]);
	putchar('\n');
}

void dfs(int now,int l,int r)
{
	if(l==r)
	{
		b[now]=a[l];
		c[now]=1;
		int cd=check();
		if(cd==1)
		{
			for(int j=1;j<=2*n;++j)
				ans[j]=c[j];
		}
		return ;
	}
	b[now]=a[l],c[now]=1;
	dfs(now+1,l+1,r);
	b[now]=a[r],c[now]=2;
	dfs(now+1,l,r-1);
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=2*n;++i)
			a[i]=read(),ans[i]=0;
		dfs(1,1,2*n);
		if(ans[1]==0)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=2*n;++i)
		{
			if(ans[i]==1)
				printf("L ");
			else
				printf("R ");
		}
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0x0;
}
