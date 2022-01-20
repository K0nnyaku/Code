#include<iostream>
#include<cstdio>
using namespace std;
int a[500010],ans[500010];
bool b[500010];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		int y=0;
		scanf("%d",&n);
		n*=2;
		int l1=1,r1=1,l2,r2=n;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(a[n]>a[1])
		{
			while(a[++r1]!=a[1]);
			l1=2;
			l2=r1+1;
			--r1;
		}
		else
		{
			while(a[++r1]!=a[n]);
			l2=r1+1;
			--r1;
			r2=n-1;
		}
		int i;
		for(i=1;i<=n/2&&l1!=r1&&l2!=r2;i++)
		{
			if(a[l1]==a[l2]&&a[r1]==a[r2])
			{
				if(a[l1]>a[r1])
					b[i]=1,--r2,--r1;
				else
					b[i]=0,++l1,++l2;
				continue;
			}
			if(a[l1]==a[r1]&&a[l2]==a[r2])
			{
				if(a[l1]>a[r2])
					b[i]=1,++l1,--r1;
				else
					b[i]=0,++l2,--r2;
				continue;
			}
			if(a[l1]==a[l2])
			{
				b[i]=1,++l1,++r2;
				continue;
			}
			if(a[l1]==a[r1])
			{
				b[i]=1,++l1,--r1;
				continue;
			}
			if(a[l2]==a[r2])
			{
				b[i]=0,++l2,--r2;
				continue;
			}
			if(a[r1]==a[r2])
			{
				b[i]=0,--r1,--r2;
				continue;
			}
			y=1;break;
		}
		while(l1-r1){if(a[l1]!=a[r1])y=1;b[++i]=0,++l1,--r1;}
		while(l2-r2){if(a[l2]!=a[r2])y=1;b[++i]=0,++l2,--r2;}
		if(y==1)
		{
			printf("-1\n");
			continue;
		}
		int l=1,r=n;
		if(a[1]>a[n])
		{
			printf("R");
			--r;
			ans[1]=a[n];
		}
		else
		{
			printf("L");
			ans[1]=a[1];
			++l;
		}
		for(int i=2;i<=n/2;i++)
			if(b[i]=='0')
			{
				printf("L");
				ans[i]=a[l];
				++l;
			}
			else
			{
				printf("R");
				ans[i]=a[r];
				--r;
			}
		for(int i=1;i<=n/2;i++)
		{
			if(a[l]==ans[i])
			{
				printf("L");
				++l; 
			} 
			else
			{
				printf("R");
				--r;
			}
		}
		printf("\n");
	}
	return 0;
}
/*2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
