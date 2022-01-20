#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e6+500;
int pos[N][2],a[N],tp[N],op[N];
int n,T,pd;
void dfs(int l1,int r1,int l2,int r2,int tim)
{
//	cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
	if(l1>r1&&l2>r2){pd=1;return;}
	if(l1<=r1)
	{
		int t=pos[a[l1]][tp[l1]^1];
		op[tim]=0;
		if(t==r1&&l1!=r1)
		{
			op[2*n-tim+1]=0,dfs(l1+1,r1-1,l2,r2,tim+1);
		}
		if(pd)return;
		if(t==l2)
		{
			op[2*n-tim+1]=1,dfs(l1+1,r1,l2+1,r2,tim+1);
		}
	}	
	if(pd)return;
	if(l2<=r2)
	{
		int t=pos[a[r2]][tp[r2]^1];
		op[tim]=1;
		if(t==r1)
		{
			op[2*n-tim+1]=0,dfs(l1,r1-1,l2,r2-1,tim+1);
		}
		if(pd)return;
		if(t==l2&&l2!=r2)
		{
			op[2*n-tim+1]=1,dfs(l1,r1,l2+1,r2-1,tim+1);
		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)scanf("%d",a+i);
		for(int i=1;i<=n;i++)pos[i][0]=pos[i][1]=0;
		for(int i=1;i<=2*n;i++)
			if(pos[a[i]][0])tp[i]=1,pos[a[i]][1]=i;
			else tp[i]=0,pos[a[i]][0]=i;
		pd=0;
		op[1]=0,op[2*n]=0,dfs(2,pos[a[1]][1]-1,pos[a[1]][1]+1,2*n,2);
		if(!pd)
		{
			op[1]=1,op[2*n]=0,dfs(1,pos[a[2*n]][0]-1,pos[a[2*n]][0]+1,2*n-1,2);
		}
		if(!pd){puts("-1");continue;}
		for(int i=1;i<=2*n;i++)if(op[i]==0)putchar('L');
		else putchar('R');
		puts("");
	}
}
