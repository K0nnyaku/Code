#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;
const int N=5*1e5+5;
int a[2*N],b[2*N],step[2*N];
int node,l,r,sp;
int n,t;
bool flag=0;
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(b[2*n+1-i]!=b[i])return 0;
	}
	flag=1;
	return 1;
}
void dfs()
{
	if(l>2*n)return;
	if(r<1)return;
	if(flag)return;
	if(sp==2*n+1)
	{
		if(check())
		{
			for(int i=1;i<sp;i++)
			{
				if(step[i]==1)printf("L");
				else printf("R");
			}
			printf("\n");
		}
		else return;
	}
	b[node]=a[l];
	node++,l++;
	step[sp++]=1;
	dfs();
	sp--;
	node--,l--;
	b[node]=a[r];
	node++,r--;
	step[sp++]=2;
	dfs();
	node--,r++;
	sp--;
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++)scanf("%d",&a[i]);
		flag=0;
		memset(b,0,sizeof(b));
		memset(step,0,sizeof(step));
		sp=1;
		l=1,r=2*n,node=1;
		dfs();
		if(!flag)printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
