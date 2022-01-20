#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
int T,n;
int en=0;
int b[1000006];
int a[1000006];
int seq[1000003];
bool flag=0;
void sou(int t,int l,int r)
{
	if(flag) return ;
	if(t==n*2)
	{
		for(int i=1;i<=en;i++)
		{
			if(b[i]!=b[n*2+1-i])
			{
				return ;
			}
		}
		flag=1;
//		for(int i=1;i<=en;i++)
//		{
//			cout<<b[i]<<' ';
//		}
//		cout<<endl;
		for(int i=0;i<t;i++)
		{
			if(seq[i]==1) printf("L");
			if(seq[i]==2) printf("R");
			//if(seq[i]==0) printf(" ? ");
		}
		return;
	}
	seq[t]=1;
	b[++en]=a[l];
	sou(t+1,l+1,r);
	b[en]=0;
	en--;
	seq[t]=2;
	b[++en]=a[r];
	sou(t+1,l,r-1);
	b[en]=0;
	en--;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		flag=0,en=0;
		memset(b,0,sizeof b);
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++)
		{
			scanf("%d",&a[i]);
		}
		if(n>=21) printf("-1\n");
		else
		{
			sou(0,1,n*2);
			if(!flag) printf("-1");
			printf("\n");
		}
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
