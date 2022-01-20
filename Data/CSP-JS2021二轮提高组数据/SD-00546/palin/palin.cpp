#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=1e6+10;
int T,n,a[N],b[N],sign;
char ans[N];
void dfs(int x,int l,int r)//第x位执行的操作 
{
	
	if (x==2*n) 
	{
		ans[x]='L';
		sign=1;
	}
	else{
    int y=a[l];
	if (b[y]==0 || b[y]==x)
	{
		int beifen=b[y];
		b[y]=2*n-x+1;
		dfs(x+1,l+1,r);
		if (sign==1) {ans[x]='L';return;}
		b[y]=beifen;
	}
	y=a[r];
	if (b[y]==0 || b[y]==x)
	{
		int beifen=b[y];
		b[y]=2*n-x+1;
		dfs(x+1,l,r-1);
		if (sign==1) {ans[x]='R';return;}
		b[y]=beifen;
	}}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		mem(b,0);
		sign=0;
		scanf("%d",&n);
		for (int i=1;i<=2*n;i++)
		  scanf("%d",&a[i]);
		dfs(1,1,2*n);
		if (sign)
		for (int i=1;i<=2*n;i++)
		  printf("%c",ans[i]);
		else printf("-1");
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1
3
3 2 1 1 3 2 
 
1
5
4 1 2 4 5 3 1 2 3 5

1
3
3 2 1 2 1 3


2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

*/
