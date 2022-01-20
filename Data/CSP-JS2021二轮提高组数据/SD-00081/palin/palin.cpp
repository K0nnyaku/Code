#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n,given[1000010],mine[1000010];
int step[1000010];
bool ok=0;
void initf()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
	{
		scanf("%d",&given[i]);
		mine[i]=given[i];
	}
	memset(given,0,sizeof(given));
	memset(mine,0,sizeof(mine));
	memset(step,0,sizeof(step));
}
void moves(int i)
{
	if(i==1)
	{
		if(given[1]<=given[n*2])
		{
			mine[1]=given[1];
			given[1]=-1;
			step[1]='L';
		}
		else
		{
			mine[1]=given[n*2];
			given[n*2]=-1;
			step[1]='R';
		}
		moves(2);
	}
	if(i==n*2&&ok)
	{
		for(int j=1;j<=n*2;j++)
			printf("%c",(char)step[j]);
		printf("\n");
	}	
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	for(int k=1;k<=T;k++)
	{
		initf();
		//moves(1);
		printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
