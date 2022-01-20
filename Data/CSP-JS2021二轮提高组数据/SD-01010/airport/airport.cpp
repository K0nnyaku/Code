#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
inline int read()
{
	char ch=getchar();int x=0,cf=1;
	while(ch<'0'||ch>'9'){if(ch=='-') cf=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*cf;
}
inline void write(int x)
{
	if(x<0){x=~(x-1);putchar('-');}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
const int N=100100;
struct node{
	int reach,leave;
}a[N],b[N];
bool cmp(node x,node y)
{
	return x.reach<y.reach;
}
int n,m1,m2,sum1=0,sum2=0,ans=-1,k1=1,k2=1,flag1=0,flag2=0;
int a1[N],b1[N],vis1[N],vis2[N];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
    cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		a[i].reach=read();
		a[i].leave=read();
	}   
	for(int i=1;i<=m2;i++)
	{
		b[i].reach=read();
		b[i].leave=read();
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(int i=0;i<=n;i++)
	{
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2)); 
		memset(a1,0,sizeof(a1));
		memset(b1,0,sizeof(b1));
		int num1=i,num2=n-i;
		sum1=sum2=0;
		for(int j=1;j<=m1;j++)
		{
			if(num1==0)
			{
				break;
			}
			if(j<=num1)
			{
				a1[j]=a[j].leave;
				sum1++;
				vis1[j]=1;
			}
			if(j>num1)
			{
				for(int k=1;k<=j;k++)
				{
					if(a[j].reach>a1[k])
					{
						if(vis1[k]==1)
						{
							a1[k]=a[j].leave;
							a1[j]=a[j].leave;
						    vis1[j]=1; 
						    sum1++;
						    break;
						}
						else continue;
					}
				}
			}
		}
		for(int j=1;j<=m2;j++)
		{
			if(num2==0)
			{
				break;
			}
			if(j<=num2)
			{
				b1[j]=b[j].leave;
				sum2++;
				vis2[j]=1;
			}
			if(j>num2)
			{
				for(int k=1;k<=j;k++)
				{
					if(b[j].reach>b1[k])
					{
						if(vis2[k]==1)
						{
							b1[k]=b[j].leave;
							b1[j]=b[j].leave;
						    vis2[j]=1;
						    sum2++;
						    break;
						}
						else continue;
					}
				}
			}
			
		}
		int sum=sum1+sum2;
		ans=max(ans,sum);
	}
	write(ans);
	return 0;
}
/*
21!9-324@emb
ÑùÀý1£º 
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


7

ÑùÀý2£º
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

4
*/ 

