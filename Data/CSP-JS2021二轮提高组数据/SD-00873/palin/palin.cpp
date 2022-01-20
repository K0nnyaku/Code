#include<iostream>
#include<cstdio>
using namespace std;
int T,n;int a[500010];int flag;int temp;int temx,temy;int g;int x,y;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
		{
			scanf("%d",&a[i]);
		}
		x=1;y=2*n;g=2*n;
		while(g!=0)
		{

			if(a[x]==a[y]){printf("LR");g--;g--;x++;y--;}
		 if(a[x]==a[x+1]){printf("LL");g--;g--;x+=2;}
			 if(a[y]==a[y-1]){printf("RR");g--;g--;y-=2;}
		}
		if(g==0){printf("\n");}
		else
		{
			int k=-1; 
			printf("%d\n",k);
		}
	}
	return 0;
}
