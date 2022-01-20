//palin
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int m,a[100001],c[100001];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		memset(c,0x3f3f3f3f,sizeof(c));
		int n,sum=0;
		scanf("%d",&n);
		for(int j=1;j<=n*2;j++)
		    scanf("%d",&a[j]);
		for(int j=1;j<=n*2;j++)
		    c[n*2+1-j]=a[j];
		for(int j=1;j<=n*2;j++)
		    if(c[j]==a[j])
		        sum++;
		if(sum==n*2)
		{
			for(int j=1;j<=n*2;j++)
			    printf("L");
			printf("\n");
        }
        else 
            printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
