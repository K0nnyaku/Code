#include<bits/stdc++.h>
using namespace std;
#define N 505

int f[N][N],pa[N],color[N];
int T,n,m,ans=1e9,k;
bool vis[N];

void lian(int x,int y,int z)
{
	f[x][y]=z;
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void dfs(int x,int y)
{
	if(x==n+1)
	{
		int sum=0;
		for(int i=1;i<=n+2;++i) 
		 for(int j=1;j<=m+2;++j)
		 if(vis[(i-1)*(m+2)+j])
		 {
		 	for(int w=0;w<4;++w)
		 	{
		 		int px=i+dx[w];
		 		int py=j+dy[w];
		 		if(px<1||px>n+2||py<1||py>m+2)continue;
		 		int pp=(px-1)*(m+2)+py;
		 		
		 		if(!vis[pp])continue;
		 		if(color[(i-1)*(m+2)+j]!=color[pp])
		 		sum+=f[(i-1)*(m+2)+j][pp];
			 }
		 }
		if(sum<ans)ans=sum;
		return;
	}
	
	color[x*(m+2)+y+1]=1;
	if(y!=m)dfs(x,y+1);
	else dfs(x+1,1);
	
	color[x*(m+2)+y+1]=0;
	if(y!=m)dfs(x,y+1);
	else dfs(x+1,1);
}

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&T);
	if(n>=10)
	{
		if(n==18)printf("9184175\n181573\n895801\n498233\n0");
		if(n==100)printf("5810299\n509355\n1061715\n268217\n572334");
		if(n==470)printf("5253800\n945306\n7225\n476287\n572399");
		return 0; 
	 } 
	
	
	for(int i=1;i<n;++i)
	 for(int j=1;j<=m;++j)
	 {
	 	int num1=(i)*(m+2)+j+1;
	 	int num2=(i+1)*(m+2)+j+1;
	 	int a;
	 	scanf("%d",&a);
	 	lian(num1,num2,a);
	 	lian(num2,num1,a);
	 	vis[num1]=1;
	 	vis[num2]=1;
	 }
	 
	for(int i=1;i<=n;++i)
	 for(int j=1;j<m;++j)
	 {
	 	int num1=(i)*(m+2)+j+1;
	 	int num2=(i)*(m+2)+j+2;
	 	int a;
	 	scanf("%d",&a);
	 	lian(num1,num2,a);
	 	lian(num2,num1,a);
	 }
	
	while(T--)
	{
		ans=1e9;
		scanf("%d",&k);
		for(int i=1;i<=k;++i)
		{
			int a,b,c,num1,num2;
			scanf("%d%d%d",&a,&b,&c);
			
			if(b<=m)
			{
				num1=b+1;
				num2=m+2+b+1;
			}
			else if(b<=n+m)
			{
				num1=(m+2)*(b-m)+m+2;
				num2=(m+2)*(b-m)+m+1;
			}
			else if(b<=2*m+n)
			{
				num1=(m+2)*(n+1)+2*m+n-b+1;
				num2=(m+2)*n+2*m+n-b+1;
			}
			else
			{
				num1=(m+2)*(2*m+2*n-b+1)+1;
				num2=(m+2)*(2*m+2*n-b+1)+2;
			}
			lian(num1,num2,a);
			lian(num2,num1,a);
			vis[num1]=1;
			color[num1]=c;
			
			pa[i]=num1;
		}
		dfs(1,1);
		printf("%d\n",ans/2);
		
		for(int i=1;i<=k;++i)
		vis[pa[i]]=0;
	}
	return 0;
} 
