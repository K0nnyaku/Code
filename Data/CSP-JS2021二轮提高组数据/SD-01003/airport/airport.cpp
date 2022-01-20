//无优化  加入树状数组 

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>

using namespace std;

const int N=1e5+10;

struct pl {
	int l,r;
}ou1[N],ou2[N];

int n,m1,m2;

int hav1[N],hav2[N];


bool srul(pl a,pl b)
{
	return a.l<b.l;
}

void print()
{
	puts(" ");
	for(int i=0;i<m1;i++)
	cout<<ou1[i].l<<"  "<<ou1[i].r<<endl;
	puts(" ");
}


int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	
	for(int i=0;i<m1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		ou1[i]={a,b};
	}
	
	sort(ou1,ou1+m1,srul);
	
	//print();
	
	int l[N]={0};
	for(int i=0;i<m1;i++)
	{
		int j=0;
		while(l[j]>ou1[i].l)j++;
		hav1[j]++;
		l[j]=ou1[i].r;
		
		//printf("%d  ",j);
		
	}
	
	
	//for(int i=0;i<n;i++)
	//{
	//	cout<<hav1[i]<<" ";
	//}
	
	for(int i=0;i<m2;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		ou2[i]={a,b};
	}
	
	sort(ou2,ou2+m2,srul);
	
	
	memset(l,0,sizeof l);
	for(int i=0;i<m2;i++)
	{
		int j=0;
		while(l[j]>ou2[i].l)j++;
		hav2[j]++;
		l[j]=ou2[i].r;
	}
	
	//puts(" ");
	//for(int i=0;i<n;i++)
	//{
	//	cout<<hav1[i]<<"  ";
	//}
	//puts(" ");
	//for(int i=0;i<n;i++)
	//{
	//	cout<<hav2[i]<<"  ";
	//}
	
	int res=0;
	for(int i=0;i<=n;i++)
	{
		int sum_q=0;
		for(int j=0;j<i;j++)
		{
			sum_q+=hav1[j];
		}
		
		int sum_p=0;
		for(int j=0;j<n-i;j++)
		{
			sum_p+=hav2[j];
		}
		res=max(res,sum_q+sum_p);
		
		
		//printf("%d %d\n",sum_p,sum_q);
	}
	
	printf("%d",res);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16


*/ 
