#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<map>

using namespace std;
int t,n,num[1000050];
bool f=1;
int read()
{
	int f=1,sum=0;
	char ch=getchar();
	if(ch=='-')
	{
		f=-1;
		ch=getchar();
	} 
	while(ch>='0'&&ch<='9')
	{
		sum*=10;
		sum+=ch-'0';
		ch=getchar();
	}
	return sum*f;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		memset(num,0,sizeof(num));
		for(int j=1;j<=2*n;j++)
		{
			num[j]=read();
			if(j>n && num[j]!=num[2*n-j+1]){
				printf("%d %d\n",num[j],num[2*n-j+1]);
				f=0;
			} 
		}
		if(f){
			for(int i=1;i<=2*n;i++) printf("L");
			printf("\n");
		}
		else printf("-1\n");
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
