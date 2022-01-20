#include <cstdio>
const int maxn = 5e5+5;
int a[maxn*2],b[maxn*2],num[maxn*2];
int n,t,flag,cnm,all,head,tail;
void shuchu()
{
	for(int i=1;i<=2*n;i++) if(num[i]==1) printf("L");
	else printf("R");
	printf("\n");
}
void dfs(int x)
{	
	if(flag) return ;
	if(x==(n<<1)+1)
	{		
		cnm=1;
		flag=1;
		shuchu();			
		return ;
	}
	if(x>n)
	{
		if(a[head]!=b[n*2+1-x]&&a[tail]!=b[n*2+1-x]) return ;
	}
	num[x]=1;
	b[x]=a[head];
	head++;
	dfs(x+1);
	head--;
	num[x]=2;
	b[x]=a[tail];
	tail--;
	dfs(x+1);
	tail++;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		flag=0;
		cnm=0;
		all=0;
		head=1;
		tail=2*n;
		for(int i=1;i<=n<<1;i++)
		{
			scanf("%d",&a[i]);
		}
		dfs(1);
		if(!cnm) printf("-1\n");	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
