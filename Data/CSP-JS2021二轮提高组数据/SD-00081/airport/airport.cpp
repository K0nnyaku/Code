#include<iostream>
#include<cstdio>
using namespace std;
int num,nin,nout,ok=0,maxn=1;
int road[100010]={0};
struct times{
	int arrive,leave;
}plane[100010],abroad[100010];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>num>>nin>>nout;
	for(int i=1;i<=nin+nout;i++)
		scanf("%d%d",&plane[i].arrive,&plane[i].leave);
	
	for(int k=0;k<=num;k++)//¹úÄÚk¸ö 
	{
		ok=0;
		for(int i=0;i<=num;i++)
			road[i]=0;
		for(int i=1;i<=nin;i++)
		{
			for(int j=1;j<=k;j++)
			{
				if(plane[i].arrive>=road[j])
				{
					road[j]=plane[i].leave;
					ok++;
					break;
				}
			}
		}
		for(int i=nin+1;i<=nin+nout;i++)
		{
			for(int j=k+1;j<=num;j++)
			{
				if(plane[i].arrive>=road[j])
				{
					road[j]=plane[i].leave;
					ok++;
					break;
				}
			}
		}
		if(ok>maxn)
			maxn=ok;
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
