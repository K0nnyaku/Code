#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<algorithm>
#define in inline
#define re register
#define ll long long
using namespace std;
in int read()
{
	int x=0,k=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') k=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	 }
	 return x*k;
}
int n,m1,m2,max1=-1,max2=-1,t,js,cnt=1,flg=0,anss=-1;
int a[10000001],b[10000001],ans[100001];
int x1[100001],y1[100001],x2[100001],y2[100001];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	t=n,n++;
	for(re int i=1;i<=m1;++i)
	{
		x1[i]=read(),y1[i]=read();
		max1=max(max1,y1[i]);	
	}
	for(re int i=1;i<=m2;++i)
	{
		x2[i]=read(),y2[i]=read();
		max2=max(max2,y2[i]);	
	}
	while(n--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int n1=n,n2=t-n;
		//int n1=1,n2=2;
		//cout<<n1<<" "<<n2<<" ";
		for(re int i=1;i<=m1;++i)
		{
			for(re int j=x1[i];j<=y1[i];++j)
			{
				//cout<<x1[i]<<" "<<y1[i]<<" "<<endl;
				if(a[j]>=n1)
				{
					for(re int k=x1[i];k<=j;++k)
					{
						if(a[k]!=n1) a[k]--; 
						js=0;
						flg=1;
						break;
					}
				} 
				if(flg==1)
				{
					flg=0;
					break;
				}
				else
				{
					a[j]++;
					js++;
				}
				//cout<<js<<" "; 
				if(js==y1[i]-x1[i]+1)
				{
					ans[cnt]++; 
					js=0;
				} 
			}
			
		}
		//cout<<ans[cnt]<<" ";
		js=flg=0;
		for(re int i=1;i<=m2;++i)
		{
			for(re int j=x2[i];j<=y2[i];++j)
			{
				//cout<<x1[i]<<" "<<y1[i]<<" "<<endl;
				if(b[j]>=n2)
				{
					for(re int k=x2[i];k<=j;++k)
					{
						if(b[k]!=n2) b[k]--; 
						js=0;
						flg=1;
						break;
					}
				} 
				if(flg==1)
				{
					flg=0;
					break;
				}
				else
				{
					b[j]++;
					js++;
				}
				//cout<<js<<" "; 
				if(js==y2[i]-x2[i]+1)
				{
					ans[cnt]++; 
					js=0;
				} 
			}
			
		}
//		cout<<ans[cnt]<<endl;
//		for(re int i=1;i<=max1;++i)
//		{
//			cout<<a[i]<<" ";
//		}
//		cout<<endl;
//		for(re int i=1;i<=max1;++i)
//		{
//			cout<<b[i]<<" ";
//		}
//		cout<<endl;
		cnt++;
		js=flg=0;
		
	}
	for(re int i=1;i<=cnt;++i)
	{
		anss=max(anss,ans[i]);
	}
	printf("%d ",anss);
	//printf("%d ",clock());
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

2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10

3 4 5
2 11
4 15
7 17
12 16
1 5
3 8
6 10
9 14
13 18
*/
