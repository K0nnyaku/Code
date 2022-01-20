#include<iostream>
#include<cstdio>
//#include<cstring>
using namespace std;
long long freedom[515];
int n;int k;string a[512];int flag;int canliu[512][3];int tempx,tempy;
void ziyouwenhao()
{
	for(int i=5;i<=512;i++)
	{
		for(int j=0;j<=i-2;j++)
		{
			freedom[i]+=freedom[j]*freedom[i-j-2];
		}
		freedom[i]+=freedom[i-1];
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	scanf("%d%d",&n,&k);freedom[0]=1;
	freedom[1]=1;
	freedom[2]=2;
	freedom[3]=4;
	freedom[4]=9;ziyouwenhao();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!="?")flag++;
		if(a[i]=="("&&tempy!=2)
		{
		
		}
	}
	if(flag==0)printf("%d",freedom[n]);
	return 0;
}
